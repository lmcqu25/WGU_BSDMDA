frameworks = ["Django", "Flask", "CherryPy", "Bottle", "Web2Py", "TurboGears"]

index_value = int(input())

try:
    name_output = frameworks[index_value]
    print(name_output)
except:
    print("Error")
