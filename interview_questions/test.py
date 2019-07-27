#code
def maxSumSubarray(arr, N):
    
    currMax = arr[0]
    totalMax = arr[0]
    
    for i in range(1,N):
        currMax = max(currMax + arr[i], currMax)
        totalMax = max(currMax, totalMax)
    
    return totalMax

def main():
    T = int(input())
    print(T)
    for _ in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        print(maxSumSubarray(arr,N))
        
if __name__ == '__main__':
    main()