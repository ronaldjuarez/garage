from collections import deque
def lrs(s1,s2):
    m = len(s1)
    n = len(s2)
    L = [ [0] * (n + 1) for _ in range(m+1)]  # mxn matrix

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i-1] == s2[j-1] and i != j:
                L[i][j] =  1 + L[i-1][j-1]  
            else: 
                L[i][j] = max(L[i-1][j], L[i][j-1])
        
    
   
    i = m
    j = n
    q = deque()
    while i*j > 0:   
        if s1[i-1] == s2[j-1] and i != j:
            q.appendleft(s1[i-1])
            i -= 1
            j -= 1
        elif L[i-1][j] < L[i][j-1]:
            j -= 1
        else: 
            i -= 1

    print(''.join(q))

    return L[m][n]

s1 = 'aabb'
print (lrs(s1,s1))

'''
Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, 
i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input: str = "aabb"
Output: "ab"

Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' 
(second). Note that 'b' cannot be considered 
as part of subsequence as it would be at same
index in both.
'''
#expected output "ADH"