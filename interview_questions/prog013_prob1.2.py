import time

# Input
s = 'caabbc'
t = 'abc' 

## FUNCTIONS

def checkPerm(s,t):
    if len(s) != len(t):
        return False
    if sorted(s) == sorted(t):
        return True
    return False

def checkPerm_2(s,t):
    if len(s) != len(t):
        return False

    count = [0] * 258

    for i in s: 
        count[ord(i)] += 1
    
    for i in t:
        count[ord(i)] -= 1
        if count[ord(i)] < 0:
            return False
    

    return True
## END FUNCTIONS


t_start = time.time()


## Print your experiments here

#c = countPairs_naive(v, k)
c = checkPerm_2(s,t)

## End of experiments


## Print Results Here

print(c)

## End print Results


t_end = time.time()
t_elapsed =  t_end - t_start
print ("Elapsed time: ", t_elapsed, " seconds")