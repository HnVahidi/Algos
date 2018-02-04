// modular binary exponation
#include<iostream>

using namespace std;
#define ll long long
ll int mod,tavan,paye;


ll int exp(ll int x,ll int n,ll int mod)// (x^n)%mod
{
  if(n==0)
    return 1;
  if(n==1)
    return x%mod;
  ll int saven=exp(x,n/2,mod);
  if(n%2==1)
    return (x*((saven*saven)%mod))%mod;
  return (saven*saven)%mod;
}


ll int mod_inv(ll int n,ll int primeMod)//GCD(n , PrimeMod)=1
{
  return exp(n,primeMod-2,primeMod);
}
int main()
{
  cin>>paye>>tavan>>mod;
  cout<<bsq(paye,tavan,mod)<<endl;//bsq test
  ll int a,b,primeMod;
  cin>>a>>b>>primeMod;
  cout<<(a*mod_inv(b,primeMod))%primeMod<<endl;// a/b % primMod
  
  return 0;
}
