purchase = {"bananas": 1.85, "steak": 19.99, "cookies": 4.52, "celery": 2.81, "milk": 4.34}
grocery_item = input("Select grocery item: ").lower()
#grocery_item_value = purchase[grocery_item]
grocery_item_value = purchase.get(grocery_item)
qnty_of_items = int(input("Enter qnty: "))


if qnty_of_items < 10:
    total_purchase_cost = qnty_of_items * grocery_item_value
elif qnty_of_items >= 10 and qnty_of_items <= 20:
    total_purchase_cost = qnty_of_items * grocery_item_value * 0.95
elif qnty_of_items >= 21:
    total_purchase_cost = qnty_of_items * grocery_item_value * 0.90


print(f'{grocery_item} ${total_purchase_cost:.2F}')

