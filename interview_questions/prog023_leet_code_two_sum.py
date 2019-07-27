def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """

    ''' SOLUTION 1 : O(n^2)
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            if nums[i] + nums[j] == target and i != j:
                return [i,j]
    '''

    d = dict()

    for i,v in enumerate(nums):
        if target - v in d:
            return d[target-v], i
        d[v] = i

nums = [3,2,4]
target = 6

print(twoSum(nums,target))

