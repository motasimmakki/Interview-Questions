
def getMinimumDifference(s: str, w1: str, w2: str)-> int:

	strArray =  list(s.split(" "))
	# print("Strig Array is :", strArray)
	strArray.reverse()

	index1 =(len(strArray) - strArray.index(w1) -1)
	index2 =(len(strArray) - strArray.index(w2) -1)
	# print(index1, index2)

	return abs(index2 - index1) -1

string = "the quick the motasim brown quick brown the frog"
word1 = "quick"
word2 = "frog"

print("\nMinimum Difference Is :",getMinimumDifference(string, word1, word2))