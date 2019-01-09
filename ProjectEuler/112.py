

def testNumber(n, testtype):
    def lt(a, b):
        return a < b

    def gt(a, b):
        return a > b

    comp = gt if testtype == 'i' else lt

    while n // 10 != 0:
        d1 = n % 10
        d2 = (n // 10) % 10

        if comp(d2, d1):
            return False

        n //= 10

    return True


assert testNumber(134468, testtype='i')
assert testNumber(66420, testtype='d')
assert not testNumber(143468, testtype='i')
assert not testNumber(143468, testtype='d')


def bouncyNumber(num):
    return not testNumber(num, 'i') and not testNumber(num, 'd')


def solve(limit):
    count = 0
    num = 100
    while True:
        if bouncyNumber(num):
            count += 1

        percentage = count / num * 100

        if percentage >= limit:
            return num

        num += 1


assert solve(50) == 538
assert solve(90) == 21780


print(solve(99))
