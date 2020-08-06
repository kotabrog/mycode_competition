import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

w, h = [int(i) for i in input().split()]
for i in range(h):
	l = input()
	line = [c for c in l]

	if i == 0:
		dic = {}
		row_dic = {}
		dic_len = 0
		for j in range(w):
			if line[j] != ' ':
				dic[dic_len] = line[j]
				row_dic[j] = line[j]
				dic_len += 1

	elif i != h - 1:
		h_temp = 0
		for j in range(1, w):
			if j <= h_temp:
				continue
			if line[j] == '-':
				l_temp = max([k for k in row_dic.keys() if k < j])
				h_temp = min([k for k in row_dic.keys() if j < k])
				row_dic[l_temp], row_dic[h_temp] = row_dic[h_temp], row_dic[l_temp]

	else:
		row_dic_reverse = {v: k for k, v in row_dic.items()}
		print("row_dic:", row_dic, file=sys.stderr, flush=True)
		print("dic", dic, file=sys.stderr, flush=True)
		for j in range(dic_len):
			print(dic[j], line[row_dic_reverse[dic[j]]], sep='')
