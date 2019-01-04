
def word_sum(word):
    s = 0
    for letter in word:
        s += ord(letter) - 64

    return s


assert word_sum('COLIN') == 53



def solve():
    f = open('./p022_names.txt', 'r')
    raw_words = f.readline().rstrip().replace('"','').split(',')

    words = sorted(raw_words)

    score = 0
    for idx, word in enumerate(words):
        score += (idx + 1) * word_sum(word)

    return score

print(solve())







