/*
B. Write a SQL code that creates
the tables to hold your report sections.
*/

/* 
Code for the detailed table.
*/

DROP TABLE IF EXISTS seasonality;
CREATE TABLE seasonality (
    dvd_id          NUMERIC,
    dvd_title       VARCHAR(50),
    dvd_category_id NUMERIC,
    dvd_category    VARCHAR(50),
    rental_date     DATE,
    rental_rate     NUMERIC
); 

/*
Code for the summary table.
*/


DROP TABLE IF EXISTS seasonality_sum;
CREATE TABLE seasonality_sum (
	season				VARCHAR(20),
	dvd_category		VARCHAR(50),
	qty_rented			NUMERIC,
	sales_in_dollars	NUMERIC
);

/*
C. Write a SQL query that will extract the raw data
needed for the Detailed section of your report from
the source database and verify the data's accuracy.
*/



INSERT INTO seasonality
    (dvd_id, dvd_title, dvd_category_id, dvd_category,
    rental_date, rental_rate)
SELECT fc.film_id, f.title, fc.category_id,
        c.name, (r.rental_date::TIMESTAMP::DATE), 
		f.rental_rate
    FROM rental AS r
    INNER JOIN inventory AS i
    ON r.inventory_id = i.inventory_id
    INNER JOIN film AS f
    on f.film_id = i.film_id
    INNER JOIN film_category AS fc
    ON fc.film_id = f.film_id
    INNER JOIN category AS c
    ON c.category_id = fc.category_id;
	
/*
The green notification box near the bottom right 
indicated that the code was generated successfully.

Verify data's accuracy.

Select * 
FROM seasonality;
*/


/*
D. Write code for function(s) that perform the transformations(s) 
you identified in part A4.

Show above code for Timestamp to Date data type and code 
below for Case function.
*/

/*
E. Write a SQL code that creates a trigger on the detailed
table of the report that will continually update the summary
table as data is added to the detailed table.
*/


CREATE OR REPLACE FUNCTION seasonality_sum_function()
	RETURNS TRIGGER
	LANGUAGE plpgsql
	AS 
$$
BEGIN	

DELETE FROM seasonality_sum;

INSERT INTO seasonality_sum (	
SELECT 
        CASE
            WHEN rental_date BETWEEN '2004-12-21' AND '2005-03-19' THEN 'Winter' 
            WHEN rental_date BETWEEN '2005-12-21' AND '2006-03-19' THEN 'Winter' 
            WHEN rental_date BETWEEN '2005-03-20' AND '2005-06-20' THEN 'Spring' 
            WHEN rental_date BETWEEN '2005-06-21' AND '2005-09-21' THEN 'Summer' 
            WHEN rental_date BETWEEN '2005-09-21' AND '2005-12-21' THEN 'Fall' 
            ELSE 'N/A'
        END AS season, dvd_category, COUNT(dvd_category) AS qty_rented, SUM(rental_rate) AS sales_in_dollars
    FROM seasonality
    GROUP BY 1, 2
    ORDER BY 3 DESC
);

RETURN NEW;

END;

$$

CREATE TRIGGER seasonality_sum_update
AFTER INSERT ON seasonality
FOR EACH STATEMENT
EXECUTE PROCEDURE seasonality_sum_function();



/*
F. Create a stored procedure that can be used to refresh the data
in both your detailed and summary tables. The procedure should clear
the contents of the detailed and summary tables and perform
the ETL load process from part C and include comments that identify
how often the stored procedure should be executed. 
	1. Explain how the stored procedure can be run on a schedule to
	ensure data freshness.
*/


--Note: The stored procedure should be executed every three 
--months to update the seasonal data in the seasonality 
--and seasonality summary tables.


DROP PROCEDURE IF EXISTS update_tables();
CREATE PROCEDURE update_tables()
LANGUAGE plpgsql
AS 

$$
BEGIN

DELETE FROM seasonality;
INSERT INTO seasonality (dvd_id, dvd_title, dvd_category_id, dvd_category,
    rental_date, rental_rate)
SELECT fc.film_id, f.title, fc.category_id,
        c.name, (r.rental_date::TIMESTAMP::DATE), 
		f.rental_rate
    FROM rental AS r
    INNER JOIN inventory AS i
    ON r.inventory_id = i.inventory_id
    INNER JOIN film AS f
    on f.film_id = i.film_id
    INNER JOIN film_category AS fc
    ON fc.film_id = f.film_id
    INNER JOIN category AS c
    ON c.category_id = fc.category_id;

END;

$$




CALL update_tables();


SELECT *
FROM seasonality;

SELECT *
FROM seasonality_sum;

CALL update_tables();
INSERT INTO seasonality
    (dvd_id, dvd_title, dvd_category_id, dvd_category,
    rental_date, rental_rate)
	VALUES (001, 'Movie1', 15, 'Sports', '2005-08-14', 2.99),
			(002, 'Movie2', 2, 'Animation', '2005-08-16', 3.99),
			(003, 'Movie3', 1, 'Action', '2005-08-12', 5.99);