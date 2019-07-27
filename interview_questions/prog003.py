import time

# Input

n = 1000
x = [1, 3, 5]

# End Input

def countSteps_naive(n,x):
    result = 0
    if (n < 0):
        return 0
    elif ( n == 0 or n == 1):
        result = 1
    else:
        for i in range(len(x)):
            if (n-x[i] >= 0) :
                result += countSteps(n-x[i],x)
    return result

def countSteps_memo(n,x,memo):
    result = 0
    if (n < 0):
        return 0
    elif memo[n] != 0 : 
        return memo[n]
    elif ( n == 0 or n == 1):
        result = 1
    else:
        for i in range(len(x)):
            if (n-x[i] >= 0) :
                result += countSteps_memo(n-x[i],x, memo)

    memo[n] = result
    return result

def countSteps_bottom_up(n,x):
    memo  = [0] * (n + 1)
    memo[0] = 1
    if (n < 0):
        return 0
    elif memo[n] != 0 : 
        return memo[n]
    else:
        for i in range(1,n+1):
            result = 0
            for j in range(len(x)):
                if (i-x[j] >= 0) :
                    result += memo[i-x[j]]
            memo[i] = result
    return memo[n]


t_start = time.time()

# your experiments here


#memo = [0] * (n + 1)
#c = countSteps_naive(n,x)
#c = countSteps_memo(n,x, memo)
c = countSteps_bottom_up(n,x)
# End of experiments




t_end = time.time()
t_elapsed =  t_end - t_start



# Print Results Here

print(c)
print ("Elapsed time: ", t_elapsed, " seconds")

# End print Results
