#include<iostream>
#include<string>

using namespace std;
string s,null;
long long int a, b , m;
#define ll long long
void binary(ll int b)
{
  s=null;
  while(b){
    if(b%2==0)
      s+='0';
    else
      s+='1';
    b/=2;
  }
}

ll int  modular_exp(ll int a, string s,ll int m)
{
    ll int c=0;
  ll int ans=1;
  for(int i=s.size()-1;i>=0;i--){
    c*=2;
    ans=(long long) (ans*ans) % m;
    if(s[i]=='1'){
      c++;
      ans=(long long) (ans*a)%m;
    }
  }
  return ans;
}

int  main()
{
  cin>>a>>b>>m;
  binary(b);
  cout<<modular_exp(a,s,m);

  return 0;
}
