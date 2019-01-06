n, k = input().split()
n = int(n)
k = int(k)
k = 2 ** k
if k >= n:
	print("Your wish is granted!")
else:
	print("You will become a flying monkey!")