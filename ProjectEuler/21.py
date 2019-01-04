
def divisor_sum(num):

    divs = [1]

    for n in range(2, num // 2 + 1):
        if num % n == 0:
            divs.append(n)

    return sum(divs)


def solve(limit):
    limit += 1
    divsums = [0]

    for n in range(1, limit):
        divsums.append(divisor_sum(n))

    amicable_nums = set()

    for x in divsums:
        for y in divsums:
            if x != y and x < limit and y < limit and divsums[x] == y and divsums[y] == x:
                amicable_nums.add(x)

    # print(divsums)
    # print(amicable_nums)
    print(sum(amicable_nums))


solve(10000)
