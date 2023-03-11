num_of_ounces = int(input("#"))

tons = num_of_ounces // 32_000
num_of_ounces %= 32_000
pounds = num_of_ounces // 16
num_of_ounces %= 16
ounces = num_of_ounces






print(f'Tons: {tons}')
print(f'Pounds: {pounds}')
print(f'Ounces: {ounces}')