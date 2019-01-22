def is_palindrome(num):
    return str(num) == str(num)[::-1]


def dec2bin(num):
    binary_list = [(num >> i) & 1 for i in range(31, -1, -1)]
    convert = 0
    for i in binary_list:
        convert *= 10
        convert += i

    return convert


def solve():
    limit = 10**6
    summ = 0
    for num in range(limit):
        if is_palindrome(num):
            binary = dec2bin(num)
            if is_palindrome(binary):
                # print(num, binary)
                summ += num
    print(summ)

solve()
