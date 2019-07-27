import time

##Input

a = 'abcd'
#v = [17, 87, 6 ,22, 41]

## End Input



## your functions here


def printPerm(s):
    a = list(s)
    cp(a,0,len(a) - 1)

def cp(a, l,r):
    if l == r:
        print(''.join(a))
    
    for i in range(l,r+1):
        a[l], a[i] = a[i], a[l]
        cp(a,l+1,r)
        a[l], a[i] = a[i], a[l] #swap back (backtracking)



def toString(List): 
    return ''.join(List) 
  
# Function to print permutations of string 
# This function takes three parameters: 
# 1. String 
# 2. Starting index of the string 
# 3. Ending index of the string. 
def permute(a, l, r): 
    if l==r: 
        print (toString(a)) 
    else: 
        for i in range(l,r+1): 
            a[l], a[i] = a[i], a[l] 
            permute(a, l+1, r) 
            a[l], a[i] = a[i], a[l] # backtrack 

## End of your functions
        
    

t_start = time.time()
## your runs here

#c = countSubsets(v,k)
printPerm(a)

## end of your runs
t_end = time.time()





t_elapsed =  t_end - t_start



## Print Results Here

#print(c)
print ("Elapsed time: ", t_elapsed, " seconds")

## End print Results
