from collections import defaultdict
import time

file = open("input.txt", "r")
stones_arr = [x for x in file.readline().strip().split()]

start_time = time.perf_counter()

stones = defaultdict(int)

for stone in stones_arr:
    stones[stone] = stones_arr.count(stone)

memo = { '0': ['1'] }

for _ in range(75):
    new = defaultdict(int)
    for s in stones:
        if s in memo:
            for elm in memo[s]:
                new[elm] += stones[s]
            continue
        elif len(s) % 2 == 0:
            middle = len(s) // 2
            first = s[0:middle]
            second = s[middle:].lstrip('0').ljust(1, '0')
            new[first] += stones[s]
            new[second] += stones[s]
            memo[s] = [first, second]
        else:
            new_stone = str(int(s) * 2024)
            memo[s] = [new_stone]
            new[new_stone] += stones[s]
    stones = new

ans = 0
for i in stones:
    ans += stones[i]
print(ans)

end_time = time.perf_counter()

print(f"Execution time: {end_time - start_time:.4f} seconds")

