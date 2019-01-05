
def isPandigital(num):
    # print(num)

    if len(str(num)) != 9:
        return False

    tendigits = [0 for _ in range(9)]

    while num != 0:
        digit = num % 10
        # print(num, digit)

        if not digit:
            return False
        digit -= 1

        if tendigits[digit] == 0:
            tendigits[digit] = 1
        elif tendigits[digit] == 1:
            return False

        num = num // 10

    return True


assert isPandigital(123456789)
assert not isPandigital(123456799)
assert not isPandigital(1234)


def concatNumbers(x, y):
    p = 10
    while y >= p:
        p *= 10

    return x * p + y

assert concatNumbers(123, 515) == 123515
assert concatNumbers(12, 0) == 120


def solve():
    limit = 10_000
    numbers = set()

    for a in range(1, limit):
        for b in range(1, int(limit/a) + 1):
            c = a * b
            identity = concatNumbers(concatNumbers(a, b), c)
            if isPandigital(identity):
                numbers.add(c)
                # print(f"{a} x {b} = {c} | {identity}")

    print(sum(numbers))


solve()
