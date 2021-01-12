

from functools import reduce

# Code for chinese remainder theorem has been taken from this source
# https://rosettacode.org/wiki/Chinese_remainder_theorem#Python_3.6
def chinese_remainder(n, a):
    sum = 0
    prod = reduce(lambda a, b: a * b, n)
    for n_i, a_i in zip(n, a):
        p = prod // n_i
        sum += a_i * mul_inv(p, n_i) * p
    return sum % prod


def mul_inv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1:
        return 1
    while a > 1:
        q = a // b
        a, b = b, a % b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += b0
    return x1


with open("./input", "r") as f:
    y = f.readlines()
    time = int(y[0].strip())
    l2 = y[1].strip()
    seq = [int(i) if i != 'x' else 'x' for i in l2.split(",")]
    avl = [i for i in seq if i != 'x']

    z = [a - time % a for a in avl]
    m = min(z)
    i = z.index(m)
    print(z[i] * avl[i])

    alpha = list(zip(list(range(len(seq))), seq))
    a = [x[1] - x[0] for x in alpha if x[1] != 'x']
    n = [x[1] for x in alpha if x[1] != 'x']

    print(chinese_remainder(n,a))
