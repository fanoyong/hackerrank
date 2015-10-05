N = int(raw_input())
data = raw_input().split()
str = ''
for i in range(0,N-1):
    str = str + data[i] + ","
num = data[N-1]
str = str + num
T = eval(str)
print hash(T)

