#include <iostream>
using namespace std;
double F(double x,int y)
{
if(y==0)
{return 1.0;}
return F(x,y-1)*x;
}
int main()
{
int y;
double x;
cin>>x>>y; 
cout<<F(x,y)<<endl;
}