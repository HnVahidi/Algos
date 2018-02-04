#include<iostream>
#include<string>

using namespace std;
const int M=1e9+7;
const int maxN=1e3+10;
const int sigma=26;
#define ll long long
string s,p;
ll int t[maxN],d[maxN],keyp,keys,n,m;

int main()
{
  cin>>s>>p;
  n=s.size();
  m=p.size();
  //initialization
  d[0]=1;
  for(int i=1;i<=m;i++)
    d[i]=(d[i-1]*sigma)%M;
  ///


  for(int i=0;i<m;i++){
    keyp=(sigma*keyp+(p[i]-'a'))%M;
    keys=(sigma*keys+(s[i]-'a'))%M;
  }

  t[m-1]=keys;
  for(int i=m-1;i<n;i++){
    if(i>=m)
    t[i]=(sigma*(t[i-1]-(s[i-m]-'a')*d[m-1])+(s[i]-'a'))%M;
    if(t[i]==keyp && s.substr(i-m+1,m)==p)
      cout<<i-m+1<<" "<<i<<endl;
  }

  return 0;
}
