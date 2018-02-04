#include<bits/stdc++.h>

using namespace std;
int Ed,Ex,Ey;

// store Ed,Ex,Ey globally
void extendedEuclid(int a,int b)
{
  if(b==0)
    {Ex=1;Ey=0;Ed=a;return ;}
  extendedEuclid(b,a%b);
  int xx=Ey;
  int yy=Ex-(a/b)*Ey;
  Ex=xx;
  Ey=yy;
}
// ax+ny=1
// ax=1 mod n
int mod_inv(int a, int n)
{
  extendedEuclid(a,n);
  return Ex;
}
int main()
{
  int a,b;
  cin>>a>>b;
  extendedEuclid(a,b);
  cout<<Ex<<" "<<Ey<<" "<<Ed<<endl;
  return 0;
}
