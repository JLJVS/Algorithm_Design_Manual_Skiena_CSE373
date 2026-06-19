from functools import lru_cache
import time

@lru_cache(maxsize=None)
def collatz_cycle(n):

    count = 1
    while (n!=1):
        count += 1
        if (n%2==0):
            n//=2
        else:
            n = 3*n+1
    return count

def find_longest_cycle(start, end):

    longest = 0
    for i in range(start, end+1):
        cycle = collatz_cycle(i)
        longest = max(cycle, longest)
    return longest


# for start, end in [(1, 10), (100, 200), (201, 210), (900, 1000)]:
#     longest = find_longest_cycle(start, end)
#     print("{} {} {}".format(start, end, longest))

if __name__ == '__main__':
    problem_input = []
    line = input()
    while line:
        if line: problem_input.append(line.strip().split())
        try: line = input()
        except: line = ''
    
    start = time.time()
    for problem in problem_input:
        start = int(problem[0])
        end = int(problem[1])
        longest = find_longest_cycle(start, end)
        print("{} {} {}".format(start, end, longest))
    end = time.time()
    delta = (end -start)/1_000_000_000
    print(f"It took {delta} seconds.")
   