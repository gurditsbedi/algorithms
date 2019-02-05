def decryption(key, inp):
    afterxor = []
    for (idx, n) in enumerate(inp):
        value = n ^ key[idx%3]
        if value > 122:
            return (False, [])
        afterxor.append(value)

    return (True, afterxor)


def solve():
    inp = [int(x) for x in open('./p059_cipher.txt').readline().rstrip().split(',')]
    # print(inp, len(inp), chr(inp[0]))

    for i in range(97, 123):
        for j in range(97, 123):
            for k in range(97, 123):
                # print(i, j, k)
                key = [i, j, k]
                possible, afterxor = decryption(key, inp[:])
                if possible:
                    text = ''.join([chr(x) for x in afterxor])
                    if all(x in text for x in ["in", "to", "the"]):
                        print(text, sum(afterxor))


solve()
