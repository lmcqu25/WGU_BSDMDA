predef_list = [4, -27, 15, 33, -10]

compared_to_list = int(input()) 

if compared_to_list > max(predef_list):
    boolean = True
else: 
    boolean = False

print(f'Greater Than Max? {boolean}')
