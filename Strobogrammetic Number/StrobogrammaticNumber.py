
numString = input("\nEnter a number to check whether it is Strobogrammatic or Not : ")

def isStrobogrammatic(numString: str) -> bool:
	print(numString)
	count = 0

	for i in range(0, len(numString)):
		if not (int(numString[i]) in {0, 6, 8, 9}):
			return False

		elif int(numString[i]) == 6:
			if int(numString[len(numString)-1-i]) == 9:
				count += 1

		elif int(numString[i]) == 9:
			if int(numString[len(numString)-1-i]) == 6:
				count += 1

		elif int(numString[i]) == int(numString[len(numString)-1-i]):
			count += 1

	if count == len(numString):
		return True

	return False

print("\nYour entered String status is : ", isStrobogrammatic(numString))