def solve(n, a, m):
    # Initialize the maximum value to 0
    max_val = 0
    # Try all possible values of x
    for x in range(n):
        # Initialize the window size to 1
        k = 1
        # Keep increasing the window size until the value of the function becomes greater than M
        while x+k <= n and a[x+k-1]*k <= m:
            k += 1
        # Update the maximum value if necessary
        max_val = max(max_val, sum(a[x+i]*(k-i) for i in range(k)))
    return max_val

# Read the number of test cases
t = int(input())

# Process each test case
for i in range(t):
    # Read the input
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    # Solve the problem and print the result
    print(f"Case #{i+1}: {solve(n, a, m)}")
