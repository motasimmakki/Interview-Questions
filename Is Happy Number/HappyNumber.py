
num = int(input("\nEnter a Number to check whether it is Happy NUmber or Not : "))

def isHappyNumber(num: int, data: list)-> bool:

	if num < 0:
		return False

	sumOfSquaresOfDigits = 0

	while num > 0:
		digit = num % 10
		num = int(num / 10)

		sumOfSquaresOfDigits += (digit**2)

	# print("Sum of Digit is : ", sumOfSquaresOfDigits)

	if sumOfSquaresOfDigits in data:
		return False

	data.append(sumOfSquaresOfDigits)

	# print(data)

	if sumOfSquaresOfDigits == 1:
		return True

	return (isHappyNumber(sumOfSquaresOfDigits, data))

print(isHappyNumber(num, []))

# Test Cases.
# 1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100. . .