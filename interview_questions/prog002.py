import time

# Input
v = [1, 7, 5, 9, 2 , 12 , 3]
k = 2 

def countPairs_naive(v, k):
    length= len(v)
    count = 0
    for i in range(length):
        for j in range (i+1, length):
            diff = abs(v[i] - v[j])
            if diff == k:
                s = '(%d,%d)' % (v[i], v[j])
                print(s)
                count = count + 1

    return count

def countPairs_hash(v,k):
    d = set(v)
    pairs = set()
    for i in d:
        if i + k in d:
            pairs.add((i,i+k))
        if i-k in d:
            pairs.add((i-k,i))
        else:
            pass
    print(pairs)
    return len(pairs)

t_start = time.time()


# Print your experiments here

#c = countPairs_naive(v, k)
c = countPairs_hash(v,k)
# End of experiments


# Print Results Here

print(c)

# End print Results


t_end = time.time()
t_elapsed =  t_end - t_start
print ("Elapsed time: ", t_elapsed, " seconds")