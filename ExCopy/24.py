

"""
  PROGRAM CODE --> Python program to Find sum of following series 1-3+5-7 upto n terms
  Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
"""
n=int(input("enter the range of the series :"))
sign=1
sum=0
i=1
for i in range(n+1):
    if(i%2!=0):
        sum=sum+(i*sign)
        sign=sign*(-1)

print("The sum of series is ",sum)


"""
 OUTPUT:-->
enter the range of the series :10
The sum of series is  5
"""


    