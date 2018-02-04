#include<iostream>
#include<string>

using namespace std;
string s,null;
long long int a, b , m,r,n;
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
int random(int n)
{
  return rand()%(n-3) +3;
}


void find_r()
{
  if(s[0]=='1'){
    r=0;
    return ;}
  for(int i=1;i<s.size();i++)
    if(s[i]=='1' && s[i-1]=='0'){
      r=i;
      return ;}
}



bool witness(ll int a, ll int n,ll int r)
{
  ll int x1=0,x2=0;
  x1=modular_exp(a,s.substr(r,s.size()-r),n);
  //cout<<x1<<endl;
  for(int i=1;i<=r;i++){
    x2=(long long)(x1*x1) % n;
    //cout<<x2<<" ";;
    if(x2==1 && x1!=1 && x1!=n-1)
      return true;
    x1=x2;
  }
  // cout<<x2;
  if(x1!=1)
    return true;
  return false;
}

bool miller_rabin()
{

  for(int i=1;i<=50;i++)
    {
      int wit=random(n);
      //   cout<<"WITNESS IS "<<wit<<endl;
      if(witness(wit,n,r))
	return false;
    }

  return true;
}

int  main()
{
  cin>>n;
  binary(n-1);
  find_r();
  // cout<<s<<endl;
  if(miller_rabin())
    cout<<"Prime";
  else
    cout<<"composite";

  return 0;
}
