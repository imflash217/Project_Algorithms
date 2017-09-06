import sys


class Stack(object):

	def __init__(self):
		self.items = []

	def isEmpty(self):
		return self.items == [] 	# Checking if the stack is Empty

	def push(self, new_item):
		# self.items.append(new_item)		# WRONG, b'coz it append the 'item' at the end not the beginning
		self.items.insert(0, new_item)		# Inserts the 'new_item' at the beginning of the stack

	def pop(self):
		return self.items.pop(0)	# Here, pop() is a pre-defined func in python library

	def size(self):
		return len(self.items)

	def peek(self, index):
		if (index >= 0 and index < len(self.items)):
			return self.items(index)	# Returns an element at the particular index of the stack
		else:
			print 'Error: the index value is out of bounds.'
			# Need to hand the exception

	def top(self):
		return self.items[0]	# Returns the top element of the stack


def spanning()









