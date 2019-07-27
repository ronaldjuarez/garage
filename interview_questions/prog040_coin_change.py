def coinChange(N,S):
    if N < 0: 
        return 0
    if N == 0:
        return 1
     
    if len(S) == 0 and N >0:
        return 0
        
    a = coinChange(N, S[:-1]) 
    b = coinChange(N-S[-1], S)
    return a + b

def coinChange2(N,S):
    L = [[0] * (N+1) for _ in range(len(S)+1) ] 
    for i in range(0,len(S)+1): 
        L[i][0] = 1
    for i in range(1, len(S)+1):
        for j in range(1, N+1):

            if i == 1:
                L[i][j] = 1
            else:
                if S[i-1] > j:
                    L[i][j] = L[i-1][j]
                else:
                    L[i][j] = L[i-1][j] + L[i][j-S[i-1]]
            

    for i in range(len(L)):
        print(L[i])
    
    return L[len(S)][N]
    
def coinChange3(S, m, n): 
    # We need n+1 rows as the table is constructed  
    # in bottom up manner using the base case 0 value 
    # case (n = 0) 
    table = [[0 for x in range(m)] for x in range(n+1)] 
  
    # Fill the entries for 0 value case (n = 0) 
    for i in range(m): 
        table[0][i] = 1
      # Fill rest of the table entries in bottom up manner 
    for i in range(1, n+1): 
        for j in range(m): 
  
            # Count of solutions including S[j] 
            x = table[i - S[j]][j] if i-S[j] >= 0 else 0
            # Count of solutions excluding S[j] 
            y = table[i][j-1] if j >= 1 else 0
            # total count 
            table[i][j] = x + y 

    for i in range(len(table)):
        print(table[i])
    
    return table[n][m-1] 

def coinChange4(n, S): 
    L = [[0] * (n+1) for _ in range(len(S))] 
  
    # Fill the entries for 0 value case (n = 0) 
    for i in range(len(S)): 
        L[i][0] = 1

    for i in range(len(S)): 
        for j in range(1,n+1): 
            x = y = 0
            if S[i] > j :
                L[i][j] = L[i][j - S[i]]
            else:
                L[i][j] = L[i-1][j]
            L[i][j] = x + y 

    for i in range(len(L)):
        print(L[i])
    
    return L[len(S)-1][n] 


N = 4 
S = [1,2,3]
m = len(S)
#N = 10
#S = [2,5,3,6]
#print (coinChange2(N,S))
print (coinChange2(N,S))