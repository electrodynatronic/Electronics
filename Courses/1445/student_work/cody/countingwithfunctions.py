#!/usr/bin/env python
########################
#Counting with functions
#counts up or down using simple for loops with 
#adjustable parameters todecide where to count to and from
#includes a function count_from_thirty_to_ten() to make 
#people who want exactly what they asked for as opposed to an adjustable function 
#Cody Atkinson
#March 3, 2015
#
########################
def countup(lower,upper):
	for thing in range (lower, upper, 1):
		print(thing),
	
def countdown(upper,lower):	
	for thing in range (upper, lower,-1):
		print(thing),	

def count_from_thirty_to_ten():
	countdown(30,9)

count_from_thirty_to_ten()
countup(20,31)
print("\n")
countdown(30,9)
