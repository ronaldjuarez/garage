def longestCommonSubsequence(s1,s2):
    lcs = []
    s2_l = list(s2)
    for c1 in s1:
        if c1 in s2_l:
            lcs.append(c1)
            s2_l.remove(c1)
    
    return ''.join(lcs)


def longestCommonSubsequence2(s1,s2):
    

    if len(s1) * len(s2) == 0:
        return ''
    if s1[-1] == s2[-1]:
        r = longestCommonSubsequence2(s1[:-1], s2[:-1]) + s1[-1]
    else:
        r = max(longestCommonSubsequence2(s1, s2[:-1]), longestCommonSubsequence2(s1[:-1],s2))
    
    return r

def longestCommonSubsequence3(s1,s2):
    m = len(s1)
    n = len(s2)
    L = [ [None] * (n + 1 ) for i in range(m+1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i * j == 0:
                L[i][j] = ''
            elif s1[i-1] == s2[j-1]:
                L[i][j] = L[i-1][j-1] + s1[i-1]
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])

    return L[m][n]

s1 = 'ABCDGHWJGNINAISNDFAKJSDNFAIPSJDNGAISDNFAIPSDFNASDFNAKASDFASDFASDFASDFASDQ'
s2 = 'AEDFHRASDGASPDUGNAPDHAFPSODIJFAPOSDIFJAOPSDIFJAOPSDIFJAOPSDIFJAPDFJAOPSDJFPWIPUGNPQIWUEAKDVZNQ'

#s1 = 'ABCDGHWJGNI'
#s2 = 'AEDFHRASD'
#s1 = 'ABCDG'
#s2 = 'AEDF'
#s1 = 'ABCADGH'
#s2 = 'AEDFHR'

print (longestCommonSubsequence3(s1,s2))