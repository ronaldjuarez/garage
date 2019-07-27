def isSafe(M,r,c):

    if ( r >= 0 and r < len(M) and c >= 0 and c < len(M[0]) ):
        return True
    return False

def recCountIslands(M,r,c):
    
    if not isSafe(M,r,c):
        return 0
    
    if M[r][c] == 0:
        return 0

    count = 1
    M[r][c] = 0

    for i in range(r-1, r+2):
        for j in range(c-1, c+2):
            if not (i == r and j == c):
                count += recCountIslands(M,i,j)
    
    return count

def countIslands(M):
    size = 0
    islandSizes = []
    for r in range(len(M)):
        for c in range(len(M[0])):
            if M[r][c] == 1:
                size += recCountIslands(M,r,c)
                if size:
                    islandSizes.append(size)
                size = 0
    
    return islandSizes




M = [[0,1,0,0,1,0],
     [0,0,1,1,1,0],
     [1,0,1,0,1,1],
     [1,1,0,0,0,0],
     [0,0,1,1,1,0]]

    
print (countIslands(M))