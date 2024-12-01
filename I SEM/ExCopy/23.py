

"""
  PROGRAM CODE --> Python program to Find the largest number among the three input numbers.
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
"""

a=int(input("enter the number 1:" ))
b=int(input("enter the number 2:"))
c=int(input("enter the number 3:"))
big=a
if(b>big):
  big=b
elif(c>big):
  big=c
print("The biggest of {0} number  is {1} ".format("3",big))

""" 
OUTPUT :-->
enter the number 1:5
enter the number 2:34
enter the number 3:23
The biggest of 3 number  is 34 
"""