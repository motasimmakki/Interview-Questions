
candies = int(input("\nEnter The Number Of Candies : "))
persons = int(input("Enter The Number Of Persons : "))

person = [0]*persons

extra = 0
i = 0
while candies > 0:
	if ((i+1) + extra) <= candies:
		person[i] += ((i+1) + extra)
		candies -= ((i+1) + extra)
	else:
		person[i] += candies
		candies = 0		
	i += 1
	if i == persons:
		extra += persons
		i = 0

print("\nPersons have : ",person)

# Test Case 01:
# 7 4
# 1 2 3 1

# Test Case 02:
# 10 3
# 5 2 3
