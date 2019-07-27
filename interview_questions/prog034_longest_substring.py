def longestSubstring(s):
    '''
    This solutions is O(n) time complexity because
    it touches every single element at most twice 2*n
    and in space complexity this is 
    '''
    i = 0
    j = 0
    d = set()
    total_max = 0
    while i < len(s) and j < len(s):
        if s[j] not in d:
            d.add(s[j])
            j += 1
            total_max = max(total_max, j-i)
        else:
            d.discard(s[i])
            i += 1
  
    return total_max
    

def negative(mask):
    return ((mask >> 1) << 2) - 1 - mask
    
def getCharNumber(c):
    a = ord('a')
    z = ord('z')
    c = ord(c)
    if c >= a and c <= z:
        return c-a
    return -1
  
def containChar(d, c):
    n = getCharNumber(c)
    if n < 0:
        return -1
    return d & (1 << n)
    
def toggle(d, c):
    mask = 1 << getCharNumber(c)
    if not containChar(d,c):
        d |= mask
    else:
        d &= negative(mask)
    return d

def longestSubstring2(s):
    i = 0
    j = 0
    d = 0
    totalMax = 0
    
    while i < len(s) and j < len(s):
        if not containChar(d,s[j]):
            d = toggle(d, s[j])
            j += 1
            totalMax = max(totalMax, j-i)
        else:
            d = toggle(d, s[i])
            i += 1
  
    return totalMax
               
# len = 8 , i = 0 , j = 3, d = {'a', 'b', 'c'}
test1 = 'abcabcbb'      # len = 8
test2 = 'bbbbb'
test3 = 'pwwkew'
test4 = 'dbdf'

print('%s, %d' % (test1, longestSubstring2(test1)))
print('%s, %d' % (test2, longestSubstring2(test2)))
print('%s, %d' % (test3, longestSubstring2(test3)))
print('%s, %d' % (test4, longestSubstring2(test4)))
