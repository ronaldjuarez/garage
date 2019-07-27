from collections import deque
def lcs_printing(s1,s2):
    m = len(s1)
    n = len(s2)
    L = [ [0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i-1] == s2[j-1] and i!= j:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i-1][j],L[i][j-1])

    for i in range(len(L)):
        print(L[i])
    
    
    i = m
    j = n
    sequence = deque()
    while i * j > 0:
        if s1[i-1] == s2[j-1]:
            sequence.appendleft(s1[i-1])
            i -= 1
            j -= 1
        elif L[i-1][j] < L[i][j-1]:
            j -= 1
        else:
            i -= 1
    
    print (''.join(sequence))
    return L[len(s1)][len(s2)]



s1 = 'ABCDGH'
s2 = 'AEDFHR'
s1 = 'aabb'
s2 = 'aabb'
print (lcs_printing(s1,s2))
#expected output "ADH"