#!usr/bin/bash/env python
#################################
#Cody Atkinson
#python fizzbuzz
#february 26, 2015
#################################
x=0 #declare x as chosen variable
while x<=100: #initiate a count to 100
	if (x%5==0 and x%3==0): 	#combine conditions for fizz and buzz 
		print("FizzBuzz")	      #print only for defined fizzbuzz
	elif (x%3==0):		      	#define condition for fizz
		print ("Fizz")	      	#print fizz
	elif(x%5==0):		        	#define condition for buzz
		print("Buzz")	        	#print buzz
	else: print (x)		      	#if no fizz buzz conditions are met print number
	x=x+1 			            	#increase x by one to reiterate
