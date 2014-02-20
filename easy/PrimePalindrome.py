def is_palidrome(num):
    digits = list(str(num))

    i = 0
    j = len(digits) - 1

    while (i < j):
        if digits[i] != digits[j]:
            return False
        else:
            i += 1
            j -= 1

    return True


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
    primes = prime_sieve(1000)

    for i in list(range(len(primes) - 1, -1, -1)):
        if is_palidrome(primes[i]):
            break

    print(str(primes[i]))

if __name__ == '__main__':
    main()
