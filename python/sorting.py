import random
import sys
import time

def bubbleSort(arr):
	n = len(arr)

	for i in range(n):

		for j in range(0, n-i-1):

			if arr[j] > arr[j + 1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]


def selectionSort(arr):
	for i in range(len(arr)):

		min_idx = i
		for j in range(i + 1, len(arr)):
			if arr[min_idx] > arr[j]:
				min_idx = j

		arr[i], arr[min_idx] = arr[min_idx], arr[i]


def mergeSort(arr, l, r):
	if l < r:
		m = (l + (r - 1)) / 2

		mergeSort(arr, l, m)
		mergeSort(arr, m + 1, r)
		merge(arr, l, m, r)


def merge(arr, l, m, r):
	n1 = m - l + 1
	n2 = r - m

	L = [0] * (n1)
	R = [0] * (n2)

	for i in range(0 , n1):
		L[i] = arr[l + i]

	for j in range(0 , n2):
		R[j] = arr[m + 1 + j]

	i = 0
	j = 0
	k = l

	while i < n1 and j < n2 :
		if L[i] <= R[j]:
			arr[k] = L[i]
			i += 1
		else:
			arr[k] = R[j]
			j += 1
		k += 1

	while i < n1:
		arr[k] = L[i]
		i += 1
		k += 1

	while j < n2:
		arr[k] = R[j]
		j += 1
		k += 1

def partition(arr, low, high):
	i = (low - 1)
	pivot = arr[high]

	for j in range(low, high):
		if arr[j] <= pivot:
			i += 1
			arr[i], arr[j] = arr[j], arr[i]

	arr[i + 1], arr[high] = arr[high], arr[i + 1]
	return (i + 1)

def quickSort(arr, low, high):
	if low < high:
		pi = partition(arr, low, high)

		quickSort(arr, low, pi - 1)
		quickSort(arr, pi + 1, high)

if len(sys.argv) != 2:
	print("usage: python sorting.py <size>")
	sys.exit()
size = int(sys.argv[1])

randomArray = [0] * size
for i in range(size):
	randomArray[i] = i
random.shuffle(randomArray)

# run and time mergesort
m = list(randomArray)
start_time = time.time()
mergeSort(m, 0, len(m) - 1)
m_time = time.time() - start_time

# run and time quicksort
q = list(randomArray)
start_time = time.time()
quickSort(q, 0, len(q) - 1)
q_time = time.time() - start_time

# run and time selection sort
s = list(randomArray)
start_time = time.time()
selectionSort(s)
s_time = time.time() - start_time

# run and time bubble sort
b = list(randomArray)
start_time = time.time()
bubbleSort(b)
b_time = time.time() - start_time

print("~~~~~~~~~~RESULTS~~~~~~~~~~")
print("<Algorithm>       <Runtime>")
print("MergeSort:        %s" %m_time)
print("QuickSort:        %s" %q_time)
print("SelectionSort:    %s" %s_time)
print("BubbleSort:       %s" %b_time)