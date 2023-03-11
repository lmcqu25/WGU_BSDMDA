water_temp = int(input())

if water_temp < 33:
    print("Frozen")
    print("Watch out for ice!")
elif water_temp >= 33 and water_temp < 80: 
    print("Cold")
elif water_temp >= 80 and water_temp < 115:
    print("Warm")
elif water_temp >= 115 and water_temp <= 211:
    print("Hot")
elif water_temp == 212:
    print("Boiling")
    print("Caution: Hot!")
else:
    print("Boiling")
