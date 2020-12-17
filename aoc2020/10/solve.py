
with open("./input", "r") as f:
    numbers = []
    for l in f.readlines():
        numbers.append(int(l.strip()))
    numbers.sort()

    counter_one = [0,1,0,1]
    for i in range(1, len(numbers)):
        counter_one[numbers[i] - numbers[i-1]] += 1

    print(counter_one[1] * counter_one[3])

