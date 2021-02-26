
# n = int(input("\nEnter the Number of Elements : "))
# nums = [None]*n

# i = 0
# while i < n:
# 	nums[i] = int(input())
# 	i += 1

def reduceArray(arr: list)->list:

	reducedArray = [None]*len(arr)
	sortedArr = sorted(arr)
	
	i = 0
	while i < len(arr):
		reducedArray[i] = sortedArr.index(arr[i])
		i += 1

	return reducedArray

# nums = [5, 10, 40, 30, 20]
nums = [40, 30, 5, 20, 10]

print("\nEntered Array is :", nums)

print("\nReduced Array is :", reduceArray(nums))