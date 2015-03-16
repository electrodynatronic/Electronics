#!/usr/bin/env python
import random

# Very poorly designed program for generating new KAYAK puzzles
# Makes no attempt to guarantee that KAYAK actually appears
# Relies on luck for that. KAYAK may also appear many times.
# generate a new puzzle by issuing the following command from a terminal:
# python make_new_puzzle.py >KAYAK.txt
# Check that the generated file contains KAYAK with grep:
# grep "K A Y A K" KAYAK.txt 


puzzle_length=30
line={}
puzzle={}
line_length=30
def make_new_line():
    
    for item in range(line_length):
        line[item]= random.randrange(1,3,1)

    for item in line:
        if (line[item] == 1):
            print "K",
        if (line[item] == 2):
            print "A",
        if (line[item] == 3):
            print "Y",
#        else:
#            print line[item]
    print ""
    
def make_new_puzzle():
    for item in range(puzzle_length*line_length):
        line[item]= random.randrange(1,5,1)
    
    for item in line:
        if (line[item] == 1):
            line[item] = "K"
        if (line[item] == 2):
#            print "A",
            line[item] = "A"
        if (line[item] == 3):
#            print "Y",
            line[item] = "Y"
        if (line[item] == 4):
#            print "A",
            line[item] = "A"
        if (line[item] == 5):
#            print "K",
            line[item] = "K"

if __name__=="__main__":
    make_new_puzzle()

    for item in range(30*30):
        print "".join(line[item]),
        if (((item+1)%30)==0):
            print""
            