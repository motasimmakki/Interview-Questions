
numCard = int(input("\nEnter the number of cards in hands : "))

print("\nEnter the cards : ")

cards = [0] * numCard

for i in range(0, numCard):
	cards[i] = int(input())

W = int(input("\nEnter the size of Group (W) : "))

cardSets = [0] * numCard

print("The Entered Cards are : ", cards)

cards.sort()

numSet = 0

print("\nSorted Cards are : ", cards)

for i in range(0, numCard):

	count = 0
	
	cardSet = [0] * W

	cardSet[count] = cards[i]

	if i > 0:
		while cardSet[count] == cards[i-1]:
			i += 1
			cardSet[count] == cards[i]
	
	for j in range(i+1, numCard):
		if cards[j] == cardSet[count]+1:
			count += 1
			cardSet[count] = cards[j]

		if count+1 == W:
			cardSets[numSet] = cardSet
			numSet += 1
			break

# for i in range(0, len(cardSets)):
# 	print(cardSets[i], end=" ")

cardSets = list(filter(lambda x: x != 0, cardSets))

if len(cardSets) == W:
	print("\n| True |")
else:
	print("\n| False |")

# Test Case Values :
# 1
# 2
# 3
# 6
# 2
# 3
# 4
# 7
# 8