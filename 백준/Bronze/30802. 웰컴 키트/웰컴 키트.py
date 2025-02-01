total = int(input())
shirt = list(map(int, input().split()))
T, P = map(int, input().split())

TS = 0
for i in shirt:
    if i == 0:
        continue
    if i % T == 0:
        TS += i // T
    else:
        TS += i // T + 1

print(TS)
print(total // P, total % P)
