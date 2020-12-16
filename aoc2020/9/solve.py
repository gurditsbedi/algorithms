

def can_sum(preamble, num):
    for i in range(len(preamble)):
        for j in range(i, len(preamble)):
            if preamble[i] + preamble[j] == num:
                return True

    return False


with open("./input", "r") as f:
    numbers = []
    i = 0
    for l in f.readlines():
        numbers.append(int(l.strip()))

    invalid = 0
    preamble = numbers[:25]
    nums = numbers[25:]
    for num in nums:
        if can_sum(preamble, num):
            preamble.pop(0)
            preamble.append(num)
        else:
            invalid = num
            break

    print(invalid)

    curr_sum = numbers[0]
    start_idx = 0
    end_idx = 0

    for i in range(1, len(numbers)):
        if curr_sum == invalid:
            s = min(numbers[start_idx: end_idx+1])
            m = max(numbers[start_idx: end_idx+1])
            print(s+m)
            break

        new_sum = curr_sum + numbers[i]
        end_idx += 1

        if new_sum > invalid:
            while new_sum > invalid:
                new_sum = new_sum - numbers[start_idx]
                start_idx += 1
            curr_sum = new_sum

        elif new_sum < invalid:
            curr_sum = new_sum
