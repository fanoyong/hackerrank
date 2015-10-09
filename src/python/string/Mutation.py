s = raw_input()
line = raw_input().split()
n = int(line[0])
k = line[1]

print s[:n] + k + s[(n+1):]
