def kmp(S : str) -> list[int]:
    i : int = 0
    j : int = 1

    ans = [0 for _ in range(0, len(S))]

    while j < len(S):
        while i > 0 and S[i] != S[j]:
                i = ans[i - 1]
        if S[i] == S[j]:
            i += 1
            ans[j] = i
        j += 1
    return ans

def find(T : str, P : str) -> list[int]:
    ans : list[int] = []
    fail : list[int] = kmp(P)

    i : int = 0
    j : int = 0

    while i < len(T):
        while j > 0 and T[i] != P[j]:
            j = fail[j - 1]
        if T[i] == P[j]:
            if j == len(P) - 1:
                ans.append(i - len(P) + 1)
                j = fail[j]
            else:
                j += 1
        i += 1
    return ans

T = input()
P = input()

ans = find(T, P)

print(len(ans))

for i in ans:
    print(i + 1, end=' ')
