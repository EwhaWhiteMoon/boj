M, N = map(int, input().split())

if N % 2 == 0:
    N -= 1

is_prime: list[bool] = [True] * ((N - 3) // 2 + 1)

for i, need_check in enumerate(is_prime):
    if need_check:
        cur_no: int = i * 2 + 3
        if cur_no >= M:
            print(cur_no)

        j: int = cur_no * 3
        while j <= N:
            is_prime[(j - 3) // 2] = False
            j += cur_no * 2
