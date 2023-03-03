import sys

class Seg_tree:
    def __init__(self, size : int) -> None:
        self.r_size : int = 1
        while self.r_size < size:
            self.r_size *= 2
        self.r_size *= 2
        self.arr : list[int] = [ 0 for i in range(0, self.r_size)]

    def update(self, n, add) -> None:
        n += self.r_size // 2
        self.arr[n] += add 
        while n != 1:
            n //= 2 
            self.arr[n] = self.arr[n * 2] + self.arr[n * 2 + 1]

    def find(self, rank) -> int:
        n : int = 1
        while n < self.r_size / 2:
            if self.arr[n * 2] >= rank:
                n = n * 2
            else:
                rank -= self.arr[n * 2] 
                n = n * 2 + 1
        return int(n - self.r_size / 2)

N : int = int(input())
tree : Seg_tree = Seg_tree(1000000)
ans : list[int] = []

for _ in range(0, N):
    i : list[int] = list(map(int, sys.stdin.readline().rstrip().split()))
    if len(i) == 2:
        a, b = i
        b = tree.find(b)
        tree.update(b, -1)
        ans.append(b)
    else:
        a, b, c = i
        tree.update(b, c)

for i in ans:
    sys.stdout.write(str(i) + '\n')
