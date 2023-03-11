std_id = int(input())
#std_id = std_id.strip()

first = std_id // 1_000_000
second = (std_id // 10_000) % 100
third = std_id % 10_000

print(f'{first}-{second}-{third}')