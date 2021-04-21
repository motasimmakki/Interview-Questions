# arr = [900, 940, 950, 1100, 1500, 1800]
# dep = [910, 1200, 1120, 1130, 1900, 2000]

# arr = [900, 940]
# dep = [910, 1200]

arr = [200, 210, 300, 320, 350, 500]
dep = [230, 340, 320, 430, 400, 520]

arr.sort()
dep.sort()

maxPlatforms = 1
neededPlatforms = 1

i = 1
j = 0

while i < len(arr):
	if not arr[i] > dep[j]:
		maxPlatforms += 1
		if maxPlatforms > neededPlatforms:
			neededPlatforms = maxPlatforms
		i += 1
	else:
		maxPlatforms -= 1
		j += 1

print("\nMinimum Platform Needed:", neededPlatforms)
