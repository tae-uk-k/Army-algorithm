numbers = list(range(1, 10001))

non_self_numbers = set()

for i in numbers:
    j = i
    while j <= 10000:
        j = j + sum(map(int, str(j)))
        if j <= 10000:
            non_self_numbers.add(j)

numbers = [num for num in numbers if num not in non_self_numbers]

for num in numbers:
    print(num)
