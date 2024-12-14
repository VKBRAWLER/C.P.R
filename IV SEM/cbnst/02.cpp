// 2. WAP to find the roots of non-linear equation using False position method. 
#include<bits/stdc++.h>
using namespace std;
double fun(double x)
{
return x*x*x - x - 1;
}
int main()
{
double x0,x1,x2;
cout<<"enter the interval for your function "<< endl;
cin>>x0>>x1;
int i;
for(i=0;i<10;i++)
{
x2=(x0*fun(x1) - x1*fun(x0))/(fun(x1) - fun(x0));
if(fun(x2)==0)
{
cout<<x2;
return 0;
}
else if(fun(x0)*fun(x2)<0)
{
x1=x2;
}
else if(fun(x1)*fun(x2)<0)
{
x0=x2;
}
}
cout<<x2;
return 0;
}