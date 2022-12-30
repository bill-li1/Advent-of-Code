f = open("input.txt", "r")


def solutionOne():
    count = 0
    for line in f:
        line = line.strip()
        str1, str2 = line.split(",")
        start1, end1 = str1.split("-")
        start2, end2 = str2.split("-")
        start1 = int(start1)
        start2 = int(start2)
        end1 = int(end1)
        end2 = int(end2)
        if ((start1 <= start2 and end1 >= end2) or
                (start1 >= start2 and end1 <= end2)):
            count += 1
    print(count)


def solutionTwo():
    count = 0
    for line in f:
        line = line.strip()
        str1, str2 = line.split(",")
        start1, end1 = str1.split("-")
        start2, end2 = str2.split("-")
        start1 = int(start1)
        start2 = int(start2)
        end1 = int(end1)
        end2 = int(end2)
        if ((end1 >= start2) and
                (end2 >= start1)):
            count += 1
    print(count)


solutionTwo()
