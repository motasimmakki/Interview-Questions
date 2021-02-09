# Validating that the candidate element is the majority element or not.
def isMajorityElement(ME: int, arr: list)->bool:
	count = 0

	for i in range(0, len(arr)):
		if arr[i] == ME:
			count += 1

	if count > (len(arr)/2):
		return True
	return False

# Selecting the correct canditate element.
def getMajorityElement(arr: list)->int:
	CE = arr[0]
	count = 1

	for i in range(1, len(arr)):
		if arr[i] == CE:
			count += 1
		else:
			count -= 1
			if(count == 0):
				CE = arr[i]
				count = 1
			
	if isMajorityElement(CE, arr):
		return CE
	else:
		print("No Majority Element Exist")

# Test Cases.
# print(getMajorityElement([2, 3, 4, 3, 3]))
# print(getMajorityElement([2, 2, 2, 3, 4]))
print(getMajorityElement([2, 3, 7, 3, 4]))
