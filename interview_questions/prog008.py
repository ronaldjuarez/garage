import time

##Input

a = 'abbc'
b = 'cbabadcbbabbcbabaabccbabc'
#v = [17, 87, 6 ,22, 41]

## End Input



## your functions here


def countPerm(a,b):
    count = 0
    for i in range(len(b)):
        if b[i] in a and i + 3 < len(b):
            temp = sorted(b[i:i+4])
            if temp == sorted(a):
                count += 1            
        
    return count            


## End of your functions
        
    

t_start = time.time()
## your runs here

#c = countSubsets(v,k)
c = countPerm(a,b)

## end of your runs
t_end = time.time()





t_elapsed =  t_end - t_start



## Print Results Here

print(c)
print ("Elapsed time: ", t_elapsed, " seconds")

## End print Results
