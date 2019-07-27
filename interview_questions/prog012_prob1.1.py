import time

# Input
v = 'abca'
k = 2 

## FUNCTIONS

def hasUniqueChar(s):
    l = len(s)
    if l > 128: 
        return False
    
    if l <= 0:
        return True
    
    
    
    exist = [0] * 128
    for i in range(l):
        if (exist[ord(s[i])]):
            return False
        else:
            exist[ord(s[i])] = True

    return False

def hasUniqueChar_2(s):
    l = len(s)
    if l > 128: 
        return False
    
    if l <= 0:
        return True
    

    checker = 0
    
    for i in s:
        if checker & (1 << ord(i)):
            return False
        checker |= (1 << ord(i))

    return True    

## END FUNCTIONS



t_start = time.time()


## Print your experiments here

#c = countPairs_naive(v, k)
c = hasUniqueChar_2(v)

## End of experiments


## Print Results Here

print(c)

## End print Results


t_end = time.time()
t_elapsed =  t_end - t_start
print ("Elapsed time: ", t_elapsed, " seconds")