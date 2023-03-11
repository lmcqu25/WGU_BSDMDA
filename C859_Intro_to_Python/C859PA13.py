import csv

user_input = input("Enter csv file: ")

with open(user_input, 'r+') as cc:
    rdr_obj = csv.reader(cc)
    rdr_obj_list = list(rdr_obj)
    
    rdr_obj_list1 = rdr_obj_list[0]
    rdr_obj_list2 = rdr_obj_list[1]
    
    rdr_obj_list1 = [i.strip() for i in rdr_obj_list1]
    rdr_obj_list2 = [i.strip() for i in rdr_obj_list2]

    item1 = iter(rdr_obj_list1)
    item2 = iter(rdr_obj_list2)

    dict1 = dict(zip(item1, item1))
    dict2 = dict(zip(item2, item2))

    print(dict1)
    print(dict2)
