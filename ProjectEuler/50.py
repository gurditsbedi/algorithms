

def prime(a):
    return not (a < 2 or any(a % x == 0 for x in range(2, int(a ** 0.5) + 1)))

assert prime(281) == True


def solve(limit):
    primes = [x for x in range(2,limit) if prime(x)]
    print(primes)

    sp = 0
    max_sp = 0
    for i in range(len(primes)):
        sp += primes[i]
        print(sp)
        if sp > limit:
            break
        if prime(sp):
            max_sp = sp



    print(max_sp)

    return max_sp


assert solve(100) == 41
assert solve(1000) == 953

# print(solve(10**6))
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73
