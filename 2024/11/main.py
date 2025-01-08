import time
import copy

file = open("test.txt", "r")
default_stones = [x for x in file.readline().strip().split()]

for test in range(40):
    print(f"Test {test + 1}")
    start_time = time.perf_counter()
    memo = { '0': ['1'] }
    stones = copy.deepcopy(default_stones)
    for _ in range(test):
        new = []
        for s in stones:
            if s in memo:
                new.extend(memo[s])
                continue
            elif len(s) % 2 == 0:
                middle = len(s) // 2
                first = s[0:middle]
                second = s[middle:].lstrip('0').ljust(1, '0')
                new.append(first)
                new.append(second)
                memo[s] = [first, second]
            else:
                new_stone = str(int(s) * 2024)
                memo[s] = [new_stone]
                new.append(new_stone)
        stones = new
    end_time = time.perf_counter()
    print(f"Execution time: {end_time - start_time:.4f} seconds")
    print("ans", len(stones))

end_time = time.perf_counter()

# print(f"Execution time: {end_time - start_time:.4f} seconds")

