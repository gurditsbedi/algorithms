
def penta(x):
    return x * (3 * x - 1) // 2


def isPenta(x):
    t = ((24 * x + 1)**0.5 + 1) / 6
    # print(t)
    return t.is_integer()


assert isPenta(1)
assert isPenta(12)
assert isPenta(35)
assert isPenta(70)
assert isPenta(117)


def solve():

    i = 1
    notFound = True
    while notFound:
        a = penta(i)

        for j in range(i-1, 0, -1):
            # print(j)
            b = penta(j)
            s, d = b + a, abs(b - a)


            if isPenta(s) and isPenta(d):
                print(a, b, d)
                notFound = False
                break

        i += 1


solve()
