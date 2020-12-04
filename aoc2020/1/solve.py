
def one():
    with open("./input", "r") as f:
        ns = [int(x) for x in f.readlines()]
        for i in ns:
            for j in ns:
                if i + j == 2020:
                    # print(i,j)
                    print(i*j)
                    return
def two():
    with open("./input", "r") as f:
        ns = [int(x) for x in f.readlines()]
        for i in ns:
            for j in ns:
                for k in ns:
                    if i + j +k  == 2020:
                        # print(i,j,k)
                        print(i*j*k)
                        return

one()
two()
