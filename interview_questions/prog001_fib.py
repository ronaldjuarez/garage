import time

def fib(n):
    result = -1
    if n == 1 or n == 2:
        result = 1
    elif n > 2:
        result = fib(n-1) + fib(n-2)
    return result

# DP = REC + MEMO
def fib2(n):
    if MEMO[n] != None:
        return MEMO[n]

    if n == 1 or n == 2:
        result = 1
    else:
        result = fib2(n-1) + fib2(n-2)
    MEMO[n] = result
    return result

# 
def fib3(n):
    if MEMO[n] != None:
        return MEMO[n]
    MEMO[1] = 1
    MEMO[2] = 1
    for i in range(3, n+1):
        print (i)
        MEMO[i] = MEMO[i-1] + MEMO[i-2]
    return MEMO[n]

def fib4(n):
    a = 1 
    b = 1
    if n == 1 or n == 2:
        result = 1
    else:
        for _ in range(3, n + 1):
            result = a + b
            b = a 
            a = result

    return result 



 #A memoized solution
def fib_2(n, memo):
    if memo[n] is not None:
        return memo[n]
    if n == 1 or n == 2:
        result = 1
    else:
        result = fib_2(n-1, memo) + fib_2(n-2, memo)
    memo[n] = result
    return result

def fib5(n):
    memo = [None] * (n + 1)
    return fib_2(n, memo)




n = 100
MEMO = [None] * (n + 1)


t_start = time.time()
print (fib(n))          # naive 
#print (fib2(n))
#print (fib3(n))
#print (fib4(n))
#print (fib5(n))
t_end = time.time()
t_elapsed =  t_end - t_start

#print (MEMO)
print ("Elapsed time: ", t_elapsed, " seconds")