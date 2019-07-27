
def sumWeights(items):
    return sum([ i[0] for i in items])
        
def sumValues(items):
    return sum([ i[1] for i in items])
        

def knapSack(items, maxWeight):

    if maxWeight < 0:
        return []
    if sumWeights(items) <= maxWeight:
        return items
    else:
        l1 = knapSack(items[0:-1], maxWeight - items[-1][0])
        l2 = knapSack(items[0:-1], maxWeight)
        
        if sumValues(l1) > sumValues(l2):
            return l1
        else:
            return l2
    return []


def knapSack2(w,v, maxWeight):
    M = [ [0] * (maxWeight+1) for _ in range(len(w))]

    for i in range(len(M)):
        for j in range(len(M[0])):
            
            if j == 0 :
                M[i][j] = 0
            elif i == 0 :
                M[i][j] = 1
            else:
                if j <  w[i]:
                    M[i][j] = M[i-1][j]
                else:
                    M[i][j] = max(v[i] + M[i-1][j - w[i]], M[i-1][j])

    for i in range(len(M)):
        print(M[:][i])
    return M[-1][-1]
    
#items = [(1,1), (3,4), (4,5), (5,7)]
w = [1,3,4,5]
v = [1,4,5,7]

maxWeight = 7
print (knapSack2(w,v, maxWeight))
