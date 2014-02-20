import sys

output = []

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        line = test.split(' ')
        reverse = [line[i].replace('\n', '') for i in range(len(line) - 1, -1, -1)]
        output.append(' '.join(reverse))

    for line in output:
        print(line)
