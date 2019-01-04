
def isPermuted(original, test):
    tenelements = [0 for i in range(10)]
    while original != 0:
        tenelements[original % 10] += 1
        original //= 10
    while test != 0:
        tenelements[test % 10] -= 1
        test //= 10

    return all(x == 0 for x in tenelements)

assert isPermuted(1234, 2413) == True
assert isPermuted(1234, 5121) == False

def solve():
    num = 1

    while True:
        count = 0
        for i in range(2, 7):
            if isPermuted(num, i * num):
                count += 1
            else:
                break

        if count == 5:
            print(num)
            break

        num += 1

solve()





