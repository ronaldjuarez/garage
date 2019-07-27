import time
import random 
# setting some hyperparameters
t_start = time.time()


# Input
v = [1,6,1, 2, 1 , 6 , 1]
f = [0] * (len(v) + 1)
k = 2 
# End Input


def qs(v,start, end):
    print('(%d,%d)'% (start,end))
    if start < end:
        pivot = random.randint(start,end)
        v_left = [i for i in v[start:end+1] if i <= v[pivot]]
        v_right = [i for i in v[start:end+1] if i > v[pivot]]
        v = v_left + [v[pivot]] + v_right

        qs(v, start, pivot - 1)
        qs(v, pivot, end)
        
        v = v_left + [pivot] + v_right

    
def partition(arr,low,high): 
    i = ( low-1 )         # index of smaller element 
    pivot = arr[high]     # pivot 
  
    for j in range(low , high): 
  
        # If current element is smaller than or 
        # equal to pivot 
        if   arr[j] <= pivot: 
          
            # increment index of smaller element 
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i] 
  
    arr[i+1],arr[high] = arr[high],arr[i+1] 
    return ( i+1 ) 
  
# The main function that implements QuickSort 
# arr[] --> Array to be sorted, 
# low  --> Starting index, 
# high  --> Ending index 
  
# Function to do Quick sort 
def quickSort(arr,low,high): 
    if low < high: 
  
        # pi is partitioning index, arr[p] is now 
        # at right place 
        pi = partition(arr,low,high) 
  
        # Separately sort elements before 
        # partition and after partition 
        quickSort(arr, low, pi-1) 
        quickSort(arr, pi+1, high) 


# your experiments here

qs(v, 0, len(v) - 1)
#quickSort(v, 0, len(v) - 1)
# End of experiments


# Print Results Here

print(v)

# End print Results


t_end = time.time()
t_elapsed =  t_end -t_start 
print ("Elapsed time: ", t_elapsed, " seconds")