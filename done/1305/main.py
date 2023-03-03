import sys

def kmp_table(S : str) -> list[int]:
    i : int = 0
    j : int = 1
    ans : list[int] = [0 for _ in range(0, len(S))]

    while j < len(S):
        while i > 0 and S[i] != S[j]:
            i = ans[i - 1]
        if S[i] == S[j]:
            i += 1
            ans[j] = i
        j += 1
    return ans


_ = sys.stdin.readline()
S : str = sys.stdin.readline().rstrip()
table : list[int] = kmp_table(S)

print(len(table) - table[-1])
