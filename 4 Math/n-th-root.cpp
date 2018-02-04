#include<iostream>
#include<cmath>

using namespace std;

double rootn(int a , int n)
{
  return pow(a,(1.0)/n);
}
int main()
{

  int a,n;
  cin>>a>>n;
  cout<<rootn(a,n)<<endl;
  
  return 0;
}
