#include<iostream>

using namespace std;
//find the largest prime below N

bool prime(int k)
{
  for(int i=2;i*i<=k;i++)
    if(k%i==0)
      return false;
  return true;
}
int main()
{
  //choose upper bound below
  int n=1e6;

  
  for(int i=n;i>=1;i--)
    if(prime(i)){
      cout<<i;
      return 0;}
  
  return 0;
}
	 
