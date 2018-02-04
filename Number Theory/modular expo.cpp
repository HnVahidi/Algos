#include<iostream>

using namespace std;
int cnt=0;
#define ll long long 
ll int expo(ll int x,ll int n ,ll int m)
{
cout<<cnt++<<endl;
  if(n==0)
    return 1;

  if(n%2==0){
  ll int t=expo(x,n/2,m);
  return (t*t)%m;
  }


 ll int t=expo(x,n/2,m);
 return (((t*t)%m)*x)%m;
}
int main()
{

  while(1)
    {
      ll int x,n;
      cin>>x>>n;
      cout<<expo(x,n,1e7)<<endl;
    }
  return 0;
}


       
