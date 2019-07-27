import time

# Input
v = [5,2,3,6,7,9]


## FUNCTIONS

def longestSubsequence(v):
    v = sorted(v)
    length = 1
    max_sq = 1
    for i in range(len(v)-1):
        if abs(v[i] - v[i+1])  != 1:
            if length > max_sq:
                max_sq = length
                length = 1 
        else:
            length += 1

    return max_sq

## END FUNCTIONS


t_start = time.time()


## Print your experiments here

c = longestSubsequence(v)

## End of experiments


## Print Results Here

print(c)

## End print Results


t_end = time.time()
t_elapsed =  t_end - t_start
print ("Elapsed time: ", t_elapsed, " seconds")