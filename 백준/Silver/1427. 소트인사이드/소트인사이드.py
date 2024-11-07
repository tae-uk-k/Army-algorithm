num=str(input())
s_num=[]
for i in num:
    s_num.append(i)
s_num.sort(reverse=True)
print(*s_num,sep="")