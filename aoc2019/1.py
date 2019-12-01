#!/usr/bin/env python3


def cal(x: int):
    return x // 3 - 2


def cal2(x: int):
    fuel = 0
    while True:
        y = x // 3 - 2
        if y < 0:
            break
        fuel += y
        x = y

    return fuel


def main():
    with open("./in1-1.txt") as f:
        ans = sum((cal(int(x)) for x in f))
        print(ans)

        f.seek(0, 0)

        ans = sum((cal2(int(x)) for x in f))
        print(ans)


main()
