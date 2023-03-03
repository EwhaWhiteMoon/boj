import sys

N: int = int(input())
C: list[int] = sorted(list(map(int, input().split())), reverse=True)

M: int = int(input())
B: list[int] = sorted(list(map(int, input().split())), reverse=True)

t: int = 0

if B[0] > C[0]:
    print(-1)
    sys.exit()
    
while B:
    for c in C:
        for b in B:
            if c >= b:
                B.remove(b)
                break
    t += 1

print(t)
