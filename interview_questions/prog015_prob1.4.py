import time

# Input
s = 'aaabb ba'
t = 13

## FUNCTIONS

def getCharNumer(c):
    ord_a = ord('a')
    ord_z = ord('z')
    ord_c = ord(c)
    if ord_c >= ord_a and ord_c <= ord_z:
        return ord_c - ord_a
    return -1

def toggle(bitVector, index):

    if index < 0: 
        return bitVector
    
    mask = 1 << index

    if (bitVector & mask == 0):
        bitVector |= mask 
    else:
        bitVector &= mask

def isPalindrome_2(s):   
    
    s = s.lower()
    


def isPalindrome(s):
    if len(s) == 0:
        return False
    
    s = s.strip()
    f = {}

    for i in s:
        if i in f:
            f[i] += 1
        else:
            f[i] = 1

    countOdds = 0
    for key, value in f.items():

        if key == ' ':
            continue

        if value % 2 != 0:
            countOdds += 1

        if countOdds > 1:
            return False

    return  True


## END FUNCTIONS


t_start = time.time()


## Print your experiments here

#c = countPairs_naive(v, k)
c = isPalindrome_2(s)

## End of experiments


## Print Results Here

print(c)

## End print Results


t_end = time.time()
t_elapsed =  t_end - t_start
print ("Elapsed time: ", t_elapsed, " seconds")