import sys


def main():
    test_cases = open(sys.argv[1], 'r')

    results = []
    for test in test_cases:
        sample = test.split()
        A, B, N = eval(sample[0]), eval(sample[1]), eval(sample[2])

        output = []
        for i in range(N):
            fizz = ((i + 1) % A) == 0
            buzz = ((i + 1) % B) == 0
            if not(fizz or buzz):
                output.append(str(i + 1))
            else:
                if fizz and buzz:
                    output.append('FB')
                else:
                    if fizz:
                        output.append('F')
                    else:
                        output.append('B')
        #print(' '.join(output))
        results.append(output)

    for r in results:
        print(' '.join(r))

if __name__ == '__main__':
    main()
