N = int(input())
arr = list(map(int, input().split()))
hash = [0] * 200000000
ans = 0

for i in range(N) :
    if hash[arr[i]] :
        continue
    else :
        ans += 1
        hash[arr[i]] = 1

print(ans)