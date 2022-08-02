N = int(input())
arr = list(map(int, input().split()))
medal = [0, 1, 2]

for i in range(N) :
    if arr[i]>arr[medal[0]] :
        medal.insert(0, i)
        medal.pop()
    elif arr[medal[1]] < arr[i] < arr[medal[0]] :
        medal.insert(1, i)
        medal.pop()
    elif arr[medal[2]] < arr[i] < arr[medal[1]] :
        medal.insert(2, i)
        medal.pop()

print(*[m+1 for m in medal])