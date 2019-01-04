
def sdiv(n):
    s = ''
    r = 10
    print(n)
    for i in range(100):
        d = r // n
        r = r % d
        r *= 10
        s += str(d)

    return s


def solve(limit):
    multiple_of_2_5 = (x for x in range(2, limit) if x % 2 == 0 or x % 5 == 0)
    # print(list(multiple_of_2_5))

    for d in range(2, limit):
        if d not in multiple_of_2_5:
            print(d, sdiv(d))



print(solve(10))
