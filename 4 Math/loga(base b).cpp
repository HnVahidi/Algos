#include<iostream>
#include<cmath>

using namespace std;

double log_base_b(int a, int b)
{
  return (double) ( log(a)/log(b));
}
int main()
{
  int a,base;
  cin>>a>>base;
  cout<<log_base_b(a,base);
 return 0;
 }
