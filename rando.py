import random
import sys
import os

def random_input(size):
    arr = random.sample(range(-500, 500), size)
    random.shuffle(arr)
    return ' '.join(map(str, arr))

if __name__ == "__main__":
    av = sys.argv[1:]
    res = random_input(int(av[0]))
    print(res)
