// modular binary exponation
#include<iostream>

using namespace std;
long long int mod,tavan,paye;


long long int bsq(long long int t)
{
  if(t==0)
    return 1;
  if(t==1)
    return paye;
  long long int saven=bsq(t/2);
  if(t%2==1)
    return (paye*(saven*saven)%mod)%mod;
  return (saven*saven)%mod;
}

int main()
{
  cin>>paye>>tavan>>mod;
  cout<<bsq(tavan)<<endl;
  
  return 0;
}
