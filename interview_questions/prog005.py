import time

# setting some hyperparameters
t_start = time.time()


# Input
v = [1,6,1, 2, 1 , 6 , 1]
f = [0] * (len(v) + 1)
k = 2 

def mostFrequent(v, k):
    for i in v:
        if i in FREQ:
            FREQ[i] = 1
        else:
            FREQ[i] += 1
    



# Print your experiments here
FREQ = {}
mostFrequent(v, k)
print(FREQ)
# End of experiments


# Print Results Here

#print(c)

# End print Results


t_end = time.time()
t_elapsed =  t_end -t_start 
print ("Elapsed time: ", t_elapsed, " seconds")