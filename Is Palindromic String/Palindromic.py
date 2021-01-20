
def isPalindromic(myStr: str)-> str:

	strFrequency = {}

	for i in range(0, len(myStr)):
		
		if myStr[i] in strFrequency.keys(): 
			strFrequency[myStr[i]] += 1
		else:
			strFrequency[myStr[i]] = 1
		
	print(strFrequency)
	keys_list = list(strFrequency)

	if not len(myStr)%2:
		i = 0;
		while i < len(strFrequency):
			if strFrequency[keys_list[i]]%2:
				return False
			i+=1
	else:
		flag = 0
		i = 0
		while i < len(strFrequency):
			if strFrequency[keys_list[i]]%2:
				flag += 1;
			if flag > 1:
				return False
			i += 1

	return True


myStr = input("\nEnter a String to check whether it is Palindromic or Not : ")

print("\nPalindromic Status is : ", isPalindromic(myStr))