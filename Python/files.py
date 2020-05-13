import sys
from itertools import islice, count

# f = open(sys.argv[1], mode='rt', encoding='utf-8')
# for line in f:
#     # print(line) #Print adds an extra newline to each EOL. Hence, we use
#     sys.stdout.write(line) 
# f.close()

def sequence():
    """Generate Recaman's sequence"""
    seen = set()
    a = 0
    for n in count(1):
        yield a
        seen.add(a)
        c = a - n
        if c<0 or c in seen:
            c = a + n
        a = c

# def write_sequence(filename, num):
#     f=open(filename, mode = 'wt', encoding='utf-8')
#     f.writelines(f"{r}\n" for r in islice(sequence(), num+1))
#     f.close()

def write_sequence(filename, num):
    with open(filename, mode = 'wt', encoding='utf-8') as f:
        f.writelines(f"{r}\n"
                    for r in islice(sequence(), num+1))

if __name__ == '__main__':
    write_sequence(filename= sys.argv[1],num=int(sys.argv[2]))