import time

# MERGESORT

# Input

v = [17, 87, 6 ,22, 41, 3, 13, 54]
#v = [17, 87, 6 ,22, 41]
# End Input







# your functions here

def mergesort(v):
    ms(v,0,len(v)-1)

def ms(v, start, end):
    print ('Count: [%d,%d]' % (start, end))
    if start < end:
        middle = (start + end) // 2
        ms(v, start, middle)
        ms(v, middle + 1, end)
        merge(v, start, middle, end)

def merge(v, start, middle, end):
    L = v[start:middle+1]
    R = v[middle+1:end+1]

    length_L = len(L)
    length_R = len(R)
    
    i = j = 0
    k = start

    while i < length_L and j < length_R:	
        if L[i] <= R[j]:
            v[k] = L[i]
            i += 1
        else:
            v[k] = R[j]
            j += 1
        k += 1

    if i < length_L:
        for ii in range(i, length_L):
            v[k] = L[ii]
            k += 1
    elif j < length_R:
        for jj in range(j, length_R):
            v[k] = R[jj]
            k += 1

# End of your functions
        
    

t_start = time.time()
# your runs here

COUNT = 0
mergesort(v)

# end of your runs
t_end = time.time()





t_elapsed =  t_end - t_start



# Print Results Here

print(v)
print ("Elapsed time: ", t_elapsed, " seconds")

# End print Results
