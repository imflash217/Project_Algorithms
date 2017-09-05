# Q: Given an unsorted array A[] of size N; sort the array in ascending order and return it
# The below implementation takes O(n^2) running time

import sys

# Input Array:
# input_array = [1,23,43,45,2,0,-100,-3,98,12,4,-43]

# Taking the unsorted input array from user
input_array = [int(x) for x in raw_input('Please enter the input array > ').split(',')]

############################################

def insertion_sort(A):
	n = len(A)-1	# the size of the array

	for j in range(1, n+1):
		key = A[j]
		i = j-1
		while i >= 0 and A[i]>key:
			A[i+1] = A[i]
			i -= 1
		A[i+1] = key
		print "Step #%d --> " % j, A

	print 'The sorted array is : ', A
	return A


############################################

insertion_sort(input_array)
# insertion_sort(input_array2)
		 	
