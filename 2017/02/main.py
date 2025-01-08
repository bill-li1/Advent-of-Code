f = open("input.txt", "r")
ans = 0
for line in f:
    nums = list(map(int, line.split()))
    nums.sort(reverse=True)
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] % nums[j] == 0:
                ans += nums[i] // nums[j]

print(ans)

# f = open("input.txt", "r")
# ans = 0
# for line in f:
#     nums = list(map(int, line.split()))
#     nums.sort()
#     ans += nums[len(nums) - 1] - nums[0]
