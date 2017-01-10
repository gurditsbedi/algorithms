#!/usr/bin/env python3
import math

def ncr(n,r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)


# returns the count of occurence of value in a XdY
def counterOfValue(value, X, Y):
    limit = math.floor((value-X)/Y)
    sum = 0
    for k in range(0, limit+1):
        tmp = value-Y*k-1
        tmp2 = ncr(X, k)
        tmp3 = ncr(tmp, X-1)
        sum += (-1)**k * tmp2 * tmp3
    # print(sum)
    return sum


def spellProb(hp, spell):
    # parsing the spell
    sign = '+' # * -> nothing, + -> +ve, - -> -ve
    spl = spell[:] #copy spell
    if '+' in spell:
        sign = '+'
        spl = spl.replace('+', 'd')
    elif '-' in spell:
        sign = '-'
        spl = spl.replace('-', 'd')
    # print(spl)
    attrs = list(map(int, spl.split('d')))
    X, Y = attrs[:2]
    Z = 0
    if len(attrs) == 3:
        Z = attrs[2]
    # print(X, Y, Z)

    # analysing the spell variables
    if sign == '+':
        lowerBound = X+Z
        upperBound = X*Y + Z
        hitpointShift = -Z
    elif '-' in spell:
        lowerBound = X-Z
        upperBound = X*Y - Z
        hitpointShift = +Z
    else:
        lowerBound = X
        upperBound = X*Y
        hitpointShift = 0
    # print(lowerBound, upperBound)

    cov = 0
    prob = 0
    summ = 0
    for hitpoint in range(lowerBound, upperBound+1):
        if hitpoint >= hp:
            cov = counterOfValue(hitpoint+ hitpointShift, X,Y)
            prob = cov/Y**X
            summ += prob

        # print(hitpoint, prob, prob*hitpoint)

    # print(summ)

    return summ


def run():
    strr = input()
    H, S = map(int, strr.split(' '))
    # print(H, S)
    spells = input().split()
    # print(spells)
    maxProb = 0.0
    for spell in spells:
        newProb = spellProb(H, spell)
        if newProb > maxProb: maxProb = newProb

    # print('%.6f'% maxProb)
    return maxProb

def start():
    T = int(input())

    ans = 0
    for i in range(T):
        ans = run()
        print('Case #%d: %.6f' % (i+1, ans))


start()

