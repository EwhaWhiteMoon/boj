def solve(N : int) -> int:
    ans : int = 0
    arr : list[int] = [0 for i in range(0, N)]

    def n_queen(depth : int):
        nonlocal ans, arr

        for i in range(0, N):
            arr[depth] = i
            if check_vaild(depth, i):
                if depth < N - 1:
                    n_queen(depth + 1)
                else:
                    ans += 1

    def check_vaild(depth : int, cur : int) -> bool:
        nonlocal arr

        if depth == 0:
                return True
        for i in range(0, depth):
            if arr[i] == cur:
                return False
            if (arr[i] + depth - i) == cur:
                return False
            if (arr[i] - depth + i) == cur:
                return False
        return True

    n_queen(0)

    return ans

N : int = int(input())

print(solve(N))
