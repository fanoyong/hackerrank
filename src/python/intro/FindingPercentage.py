n = int(raw_input())
for i in range(0,n):
    line = raw_input().split()
    name = line[0]
    a = int(line[1])
    b = int(line[2])
    c = int(line[3])
    data[name] = (a+b+c) / 3

answer = raw_input()
print data[answer]
