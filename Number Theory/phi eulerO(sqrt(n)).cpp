#include<iostream>

using namespace std;

#define ll long long

int main()
{
 ll int n;

  cin>>n;
   ll int save=n;
 ll int ans=n;
  for(int i=2;i*i<=save;i++)
    if(n%i==0)
      {
	ans*=(i-1);
	ans/=i;
	while(n%i==0)
	  n/=i;
      }
  if(n>1){
    ans*=n-1;
    ans/=n;}
  cout<<ans<<endl;
  
  return 0;
}
