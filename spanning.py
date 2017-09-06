import sys


class Stack(object):

	def __init__(self):
		self.items = []			# Creates an empty stack/list

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
			return self.items[index]	# Returns an element at the particular index of the stack
		else:
			print 'Error: the index value is out of bounds.'
			# Need to hand the exception

	def top(self):
		return self.items[0]	# Returns the top element of the stack


def spanning(input_stack):

	# Create an Empty stack 'D' to hold the h_i values
	D = Stack()

	# Create an empty stack to hold the span values
	span = Stack()

	for i in range(0, input_stack.size()):
		k = 0
		done = False

		while not(D.isEmpty() or done):
			if(input_stack.peek(i) >= input_stack.peek(D.top())):
				# print input_stack.peek(i), input_stack.peek(D.top())
				# print 'D.top()', D.top()
				# print 'i', i
				D.pop()

			else:
				done = True
		# print 'D.size()', D.size(), D.isEmpty()
		if(D.isEmpty()):
			h = -1
			# print 'h', h
		else:
			h = D.top()
			# print 'h', h

		span.push(i-h)
		print 'span[%d] ---> '%i, span.top()

		D.push(i)
	return span


######################################################

m_stack = Stack()
m_stack.push(10)
m_stack.push(50)
m_stack.push(9)
m_stack.push(2)
m_stack.push(1)
m_stack.push(9)
m_stack.push(10)
m_stack.push(9)

# print m_stack

spanning(m_stack)












