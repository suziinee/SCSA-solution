m = int(input())
arr = [list(input()) for _ in range(m)]
n = int(input())
pattern = [list(input()) for _ in range(n)]

def find_pattern(x, y) :
    for i in range(n) :
        for j in range(n) :
            if arr[x+i][y+j] != pattern[i][j] : return 0
    return 1

ans = 0
for i in range(m-n+1) :
    for j in range(m-n+1) :
        ans += find_pattern(i, j)
print(ans)