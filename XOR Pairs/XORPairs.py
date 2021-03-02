
def getXORPairs(arr: list, n: int)->int: 
    count = 0
    XORPairs = 0
    
    arr = sorted(arr)
    for i in range(1, n):
        if arr[i] == arr[i-1]:
            count += 1
        else:
            count += 1
            XORPairs += (count*(count-1))//2
            count = 0
    if count:
        count += 1
        XORPairs += (count*(count-1))//2
    
    return XORPairs


arr = [1, 3, 4, 1, 4]
# arr = [2, 2, 2]

print("Possible XOR Pairs in", arr, "is :", getXORPairs(arr, len(arr)))