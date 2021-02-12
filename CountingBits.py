# Takiing input to find total number of 1's upto N.
num = int(input("\nEnter a number : "))

# countBits() function that will return total number of 1's upto N.
def countBits(num: int)->list:
	counts = [0]*(num+1)

	i = 1
	while i < (num + 1):
		counts[i] = counts[i//2] + (i%2);
		i += 1

	return counts

print("\nCounting for 1's upto", num, "is", countBits(num))
