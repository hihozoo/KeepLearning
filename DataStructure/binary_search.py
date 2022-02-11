# -*- coding: utf-8 -*-
# Id$
# @file
# @author zhujisheng@corp.netease.com(Zoo)

def find(arr, tgt):
	i = 0
	j = len(arr)

	while i < j:
		mid = i + (j - i) // 2
		if arr[mid] == tgt:
			return mid
		if arr[mid] < tgt:
			i = mid + 1
		else:
			j = mid - 1
	return -1

def find_left(arr, tgt):
	i = 0
	j = len(arr)

	while i < j:
		mid = i + (j - i) // 2
		if arr[mid] == tgt:
			j = mid - 1
		elif arr[mid] > tgt:
			j = mid - 1
		else:
			i = mid + 1
	if i < len(arr) and arr[i] == tgt:
		return i
	return -1

def find_right(arr, tgt):
	i = 0
	j = len(arr)

	while i < j:
		m = i + (j - i) // 2
		if arr[m] == tgt:
			i = m + 1
		elif arr[m] < tgt:
			i = m + 1
		else:
			j = m - 1
	if 0 <= j < len(arr) and arr[j] == tgt:
		return j
	return -1

if __name__ == "__main__":
	arr = range(1, 100)
	arr = [1, 2, 3, 3, 3, 3, 4, 5]
	print find_right(arr, 3)

