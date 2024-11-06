W=input()
sum=[0 for _ in range(26)]
for i in W:
    sum[ord(i)-97]+=1
print(*sum)