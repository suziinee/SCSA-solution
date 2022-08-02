n = int(input())
arr = list(map(int, input().split()))

up = 1
down = 1
ans = 0
for i in range(n-1) :
    if arr[i] <= arr[i+1] :
        up += 1
    else :
        ans = max(ans, up)
        up = 1
    if arr[i] >= arr[i+1] :
        down += 1
    else :
        ans = max(ans, down)
        down = 1
ans = max(ans, up)
ans = max(ans, down)
print(ans)
