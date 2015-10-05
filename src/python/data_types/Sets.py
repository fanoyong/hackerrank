N1 = int(raw_input())
data1 = raw_input().split()
S1 = set()
for i in data1:
    S1.add(i)

N2 = int(raw_input())
data2 = raw_input().split()
S2 = set()
for i in data2:
    S2.add(i)

S3 = S1.symmetric_difference(S2)
#S4 = S2.difference(S1)
L1 = list(map(int,S3))
#L2 = list(map(int,S4))
L1.sort()
#L2.sort()

for i in L1:
    print i
#for i in L2:
#    print i
