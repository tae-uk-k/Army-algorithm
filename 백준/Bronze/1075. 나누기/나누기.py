change_number = [f"{i:02}" for i in range(100)]
N = input()
F = int(input())
N = N[:-2]

for i in change_number:
    C = int(N + i)
    if C % F == 0:
        print(i) 
        break

    