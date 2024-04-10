from itertools import accumulate

while 48763:
	try:
		n, m = map(int, input().split())
		arr = [0] + list(map(int, input().split())) # 1-base
		arr = list(accumulate(arr)) # prefix sum
		for i in range(m):
			l, r = map(int, input().split())
			print(arr[r] - arr[l - 1])
	except EOFError:
		break