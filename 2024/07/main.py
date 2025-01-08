# f = open("test.txt", "r")
f = open("input.txt", "r")
allAns = set()
ans = 0

def solve(vals, cum, target, index, id):
    global ans
    if cum == target and index == len(vals):
        allAns.add((target, id))
        return
    elif cum > target or index == len(vals):
        return
    else:
        solve(vals, cum + vals[index], target, index + 1, id)
        solve(vals, cum * vals[index], target, index + 1, id)
        solve(vals, int(str(cum) + str(vals[index])), target, index + 1, id)

id = 0

for line in f.readlines():
    [t, vals] = line.strip().split(': ')
    vals = [int(val) for val in vals.split()]
    solve(vals, vals[0], int(t), 1, id)
    id += 1


for elm in allAns:
    ans += elm[0]

print(ans)
