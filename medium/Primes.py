import sys


def prime_sieve(max_num):
    int_range = [None, None]

    for val in range(2, max_num + 1):
        int_range.append(val)

    p = 2
    while (p * 2 <= max_num):

        # Eliminate the multiples of this p (i.e., p*2, p*3, ...)
        i = 2
        while (i * p <= max_num):
            multiple = i * p
            int_range[multiple] = None
            i += 1

        # Find the smallest remaining integer > last p
        p += 1
        while (int_range[p] is None):
            p += 1

    return [n for n in int_range if n is not None]


def main():
    with open(sys.argv[1], 'r') as test_cases:
        for test in test_cases:
            try:
                primes = prime_sieve(eval(test))
                print(",".join([str(num) for num in primes]))
            except (NameError, SyntaxError) as e:
                print(e)

if __name__ == '__main__':
    main()
