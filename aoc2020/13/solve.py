


with open("./input", "r") as f:
    x = f.readlines()
    time = int(x[0].strip())
    avl = [int(i) for i in x[1].strip().split(",") if i != 'x']

    z =  [a - time % a for a in avl]
    m = min(z)
    i = z.index(m)
    print(z[i] * avl[i])


