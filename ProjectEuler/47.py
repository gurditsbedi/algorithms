
def primeFactors(num):
    pf = set()
    while num % 2 == 0:
        pf.add(2)
        num //= 2

    i = 3
    for i in range(3, int(num**.5 + 1), 2):
        while num % i == 0:
            pf.add(i)
            num //= i

    if num > 2:
        pf.add(num)

    return pf


def solve(consec):
    num = 2
    count = 0
    notFound = True
    while notFound:
        pfs = primeFactors(num)
        # print(num, pfs)

        if len(pfs) == consec:
            count += 1
        else:
            count = 0

        if count == consec:
            return num - consec + 1
            notFound = False

        num += 1

assert solve(2) == 14
assert solve(3) == 644
print(solve(4))

