various_data_types = [516, 112.49, True, "meow", ("Western", "Governors", "University"), {"apple": 1, "pear": 5}]
print(various_data_types)
print()


index_value = int(input("#"))
name_index_value = various_data_types[index_value]
data_type = type(name_index_value).__name__


print(f'Element {index_value}: {data_type}')
