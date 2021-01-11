
length = int(input("\nEnter for how many values of x, you want to calculate :\n"))

x = [0] * length

for i in range(0, length):
	x[i] = int(input("Enter {} value for x : ".format(i+1)))

a = int(input("\nEnter the value of a : "))
b = int(input("Enter the value of b : "))
c = int(input("Enter the value of c : "))


def quadFun(x, a, b, c):
	return ((a*x*x)+(b*x)+c)

sortedFx = [0]*length

for i in range(0, length):
	sortedFx[i] = quadFun(int(x[i]), a, b, c)

sortedFx = sorted(sortedFx)

print(sortedFx)