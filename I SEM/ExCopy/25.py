

"""
  PROGRAM CODE --> Python program to Find sum of digit of inputted number
   Name- RANDOMNAME
  Section- ABCDEFG
  Roll no- 0000000
  Branch-CSE
"""
n=int(input("enter the number :"))
sum=0
for i in range(n+1):
    rem=n%10
    sum=sum+rem
    n=n//10
print("The sum of each inputed digit is",sum)

"""
 OUTPUT :-->
enter the number :24124
The sum of each inputed digit is 13
"""