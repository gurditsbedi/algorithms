
def cachefact(limit):
    def fact(n):
        p = 1
        for i in range(1, n + 1):
            p *= i
        return p

    facttable = {}
    for i in range(limit + 1):
        facttable[i] = fact(i)

    return facttable

facttt = cachefact(100)


def ncr(n, r):
    return facttt[n] / facttt[r] // facttt[n - r]


assert ncr(23, 10) == 1144066
assert ncr(5, 3) == 10


def solve():
    count = 0
    for n in range(1, 101):
        for r in range(1, n + 1):
            comb = ncr(n, r)

            if comb > 10**6:
                count += 1

    return count


print(solve())
