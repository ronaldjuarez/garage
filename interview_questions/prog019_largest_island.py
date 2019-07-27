def isSafe(M,r,c):
    
    safe = False
    
    if (r >= 0 and r < len(M) and c >= 0 and c < len(M[0])): 
        safe = True
        
    return safe

def getSize(M, r, c):
    
    if not isSafe(M,r,c):
        return 0
    
    if M[r][c] == 0:
        return 0
    

    count = 1
    M[r][c] = 0
    for i in range(r-1, r+2):
        for j in range(c-1, c+2):
            if not (i == r and j == c):
                count += getSize(M,i,j)

    return count


def getMaxSizeRegion(M):
    maxSize = 0
    for i in range(len(M)):
        for j in range(len(M[0])):
            if M[i][j] == 1:
                size = getSize(M,i,j)
                maxSize = max(size, maxSize)
                
    return maxSize


M = [[0,0,0,0,1,0],
     [0,0,1,1,1,0],
     [1,0,0,0,1,1],
     [1,1,0,0,0,0],
     [0,0,0,1,1,0]]
M2 = []
print (getMaxSizeRegion(M))
print (getMaxSizeRegion(M2))




