

def lsc(v):
    
    L = [0]*len(v)
    
    L[0] = v[0]
    
    for i in range(1, len(v)):
        L[i] = max(L[i-1] + v[i], L[i-1])
        
    print(L)
    return L[-1]
    
    
def lsc2(v):
    
    totalMax = 0
    currentMax = 0
    
    for i in range(len(v)):
        currentMax = currentMax + v[i]
        if currentMax <= 0:
            currentMax = 0
        totalMax = max(totalMax, currentMax)
        
    return totalMax
v = [-2, -3, 4, -1, -2, 1, 5, -3]
v = [1,100,-200, 40,40,40,-3]

print (lsc2(v))