start = int(input())
n = int(input())
time = 0
bomb = start

for i in range(n) :
  t, tpf = input().split()
  t = int(t)
  time += t
  if time >= 210 : 
    break
  else :
    if tpf == 'T' : bomb += 1
  
if bomb%8==0 : 
  print(8)
else :
  print(bomb%8)