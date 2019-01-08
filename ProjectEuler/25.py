def nlen(n):
    c = 0
    while n != 0:
        n = n // 10
        c += 1
    return c


def solve(reqlen):
    a = 1
    b = 1

    n = 2
    while True:
        t = a
        a = b
        b = t + b

        n += 1

        if nlen(b) == reqlen:
            return n


assert solve(2) == 7
assert solve(3) == 12
assert solve(4) == 17
print(solve(1000))

