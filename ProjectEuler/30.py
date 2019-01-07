def solve():
    n = 5
    limit = 9 ** n * n
    numbers = set()
    for num in range(10, limit):
        numsum = 0
        numdash = num

        while numdash != 0:
            numsum += (numdash % 10) ** n
            numdash //= 10

        if numsum == num:
            numbers.add(num)

    print(sum(numbers))

solve()

