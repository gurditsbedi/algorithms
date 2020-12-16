

def can_sum(preamble, num):
    for i in range(len(preamble)):
        for j in range(i, len(preamble)):
            if preamble[i] + preamble[j] == num:
                return True

    return False


with open("./input", "r") as f:
    numbers = []
    i = 0
    for l in f.readlines():
        numbers.append(int(l.strip()))

    invalid = 0
    preamble = numbers[:25]
    nums = numbers[25:]
    for num in nums:
        if can_sum(preamble, num):
            preamble.pop(0)
            preamble.append(num)
        else:
            invalid = num
            break

    print(invalid)
