def isPrime(n):
    # Corner cases
    if (n <= 1):
        return False
    if (n <= 3):
        return True

    # This is checked so that we can skip
    # middle five numbers in below loop
    if (n % 2 == 0 or n % 3 == 0):
        return False

    i = 5
    while(i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6

    return True


def solve():
    req_primes = [x for x in range(1487+1, 10**4) if isPrime(x)]

    for a in req_primes:
        for d in range(1, (10**4 - a) // 2 + 2):
            if a + d + d < 10**4:
                nums = [a, a + d, a + d + d]
                num_sets = [set(str(x)) for x in nums]

                all_prime = all(x in req_primes for x in nums)
                all_permu = all(x == num_sets[0] for x in num_sets)
                if all_prime and all_permu:
                    print(''.join(str(x) for x in nums))
                    break



solve()
