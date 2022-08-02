n = int(input())
arr = [ [list(map(int, input().split())) for _ in range(n)], [[0]*n for _ in range(n)] ]
cur = 0

def rotation() :
    global cur
    after = (cur+1) % 2
    y = n-1
    for i in range(n) :
        x = 0
        for j in range(n) :
            arr[after][x][y] = arr[cur][i][j]
            x += 1
        y -= 1
    cur = after

while True :
    tmp = int(input())
    if tmp == 0 : break
    for i in range(tmp//90) :
        rotation()
        for a in arr[cur] :
            print(*a)
