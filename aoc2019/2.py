import fileinput
from typing import List

VAL = 19690720


def run_prog(nums_input: List[int]):
    nums = nums_input[:]
    for i in range(0, len(nums), 4):
        inst = nums[i]

        if inst == 99:
            break
        elif inst == 1:
            nums[nums[i + 3]] = nums[nums[i + 1]] + nums[nums[i + 2]]
        elif inst == 2:
            nums[nums[i + 3]] = nums[nums[i + 1]] * nums[nums[i + 2]]

    return nums


assert run_prog([1, 0, 0, 0, 99]) == [2, 0, 0, 0, 99]
assert run_prog([2, 3, 0, 3, 99]) == [2, 3, 0, 6, 99]
assert run_prog([2, 4, 4, 5, 99, 0]) == [2, 4, 4, 5, 99, 9801]
assert run_prog([1, 1, 1, 4, 99, 5, 6, 0, 99]) == [30, 1, 1, 4, 2, 5, 6, 0, 99]


def main():
    # part 1
    nums_copy = [int(x) for x in fileinput.input()[0].strip().split(",")]
    nums = nums_copy[:]
    nums[1] = 12
    nums[2] = 2
    print(run_prog(nums)[0])

    # part 2
    for noun in range(0, 100):
        for verb in range(0, 100):
            nums = nums_copy[:]
            nums[1] = noun
            nums[2] = verb
            res = run_prog(nums)
            if res[0] == VAL:
                print(100 * noun + verb)


main()
