import sys
a = -sys.maxint - 1
b = -sys.maxint - 1
N = int(raw_input())
line = raw_input().split()
a = int(line[0])
b = int(line[1])
if a < b:
    b = int(line[0])
    a = int(line[1])
elif a == b:
    b = -sys.maxint - 1

for i in range (2,N):
    n = int(line[i])
    if b < n and a < n:
        b = a
        a = n
    elif a > n and n > b:
        b = n

print b
