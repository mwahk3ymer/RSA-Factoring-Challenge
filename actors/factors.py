import sys

def factorize(n):
    for i in range(2, n//2 + 1):
        if n % i == 0:
            return i, n // i
    return None

def main():
    if len(sys.argv) != 2:
        print("Usage: {} <file>".format(sys.argv[0]))
        sys.exit(1)
    
    input_file = sys.argv[1]

    try:
        with open(input_file, 'r') as file:
            for line in file:
                n = int(line.strip())
                factors = factorize(n)
                if factors:
                    p, q = factors
                    print("{}={}*{}".format(n, p, q))
                else:
                    print("{} is prime".format(n))

    except FileNotFoundError:
        print("File not found:", input_file)
        sys.exit(1)

if __name__ == "__main__":
    main()
