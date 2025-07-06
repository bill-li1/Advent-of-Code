largest_perfect_square = 0

# target = 347991
target = 23

for i in range(1, 1000, 2):
    if ((i+2) * (i+2) > target):
        largest_perfect_square = i
        break

diff = target - (largest_perfect_square * largest_perfect_square)

print(largest_perfect_square, diff)
