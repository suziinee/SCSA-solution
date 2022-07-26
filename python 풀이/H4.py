from collections import deque
start = int(input())
n = int(input())
time_dct = {i : deque([]) for i in range(1, 9)}
tpf_dct = {i : deque([]) for i in range(1, 9)}
idx = [i%8 if i%8!=0 else 8 for i in range(start, n+start)]

for i in idx :
  a, b = input().split()
  time_dct[i].append(int(a))
  tpf_dct[i].append(b)

time = 0
bomb = start

for i in idx :
  if time_dct[i] :
    tmp = time_dct[i].popleft()
    if time + tmp < 210 :
      time += tmp
      if tpf_dct[i].popleft() == 't' :
        bomb += 1
  else :
    break

print(bomb)