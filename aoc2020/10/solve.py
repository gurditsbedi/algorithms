
with open("./input", "r") as f:
    numbers = []
    for l in f.readlines():
        numbers.append(int(l.strip()))
    numbers.sort()

    counter_one = [0,1,0,1]
    for i in range(1, len(numbers)):
        counter_one[numbers[i] - numbers[i-1]] += 1

    print(counter_one[1] * counter_one[3])

    numbers = [0] + numbers
    counter_two = [0] * len(numbers)

    counter_two[-1] = 1
    counter_two[-2] = 1
    counter_two[-3] = 1

    if numbers[-1] - numbers[-3] <=3:
        counter_two[-3] += 1

    for i in range(len(numbers)-4, -1, -1):
        for j in [1, 2, 3]:
            if numbers[i+j] - numbers[i] <= 3:
                counter_two[i] += counter_two[i+j]

    print(counter_two[0])

