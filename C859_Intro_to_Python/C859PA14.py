from math import factorial as fact

user_input = int(input("#: "))

fact_of_user_input = fact(user_input)

if fact_of_user_input > 100:
    boolean = True
else:
    boolean = False
    

print(fact_of_user_input)
print(boolean)