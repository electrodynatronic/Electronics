#!/usr/bin/env python

##############################################
#
# Muh fizzbuzz
#
# Muh name
#
###############################################
# Fizz Buzz is a children's game. Players generally sit in a circle. The player 
# designated to go first says the number "1", and each successive player counts 
# the next number in turn. However, any number divisible by 'A' e.g. three is 
# replaced by the word fizz and any divisible by 'B' e.g. five by the word buzz. 
# Numbers divisible by both become fizz buzz. A player who hesitates or makes a 
# mistake is either eliminated, or killed.
# 
# Write a program that prints all integers from 1 to 100 but for numbers which are 
# divisible by 3 prints "Fizz! " instead of the number, and for numbers which are 
# divisible by 5 prints "Buzz! " instead of the number, and finally for numbers 
# which are divisible by both 3 and five prints "Fizz Buzz!" instead of the number


#for item in range(100):
#    print(item + 1)
import time 

    
for item in range(1,101):
    print str(item) + " one thousand..."  
    sleeptime = 1.000 - (item*9)/1000.000
    print sleeptime
    time.sleep(sleeptime)           #Sleep 1 second
print("ready or not, here I come.")















#
#    if (item%3==0) & (item%5==0):
#       print("Fizz Buzz! ")
#    elif (item%5==0):
#       print("Buzz! ")
#    elif (item%3==0):   
#       print("Fizz! ")
#    else:
#        print(item)
