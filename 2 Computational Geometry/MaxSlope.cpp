#include<iostream>
#include<bits/stdc++.h>

using namespace std;
const int maxN=2e5+100;
const double EPS=1e-9; 
pair<double,double>p[maxN],ans[maxN],A,B;
int n;

#define X first
#define Y second

void input()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>p[i].X>>p[i].Y;
}
double shib(int x1,int y1,int x2,int y2)
{
  return (y2-y1)/(x2-x1);
}
bool inf()
{
  for(int i=1;i<=n;i++)
    if(p[i].X==p[i+1].X){
      A=p[i];
      B=p[i+1];
      return true;}
  return false;
}
bool More(double a, double b)
{
  if(a-b>EPS)
    return true;
  return false;
}
void show()
{
  A=p[1];
  B=p[2];
  for(int i=1;i<=n;i++)
    if(More(shib(p[i].X,p[i].Y,ans[i].X,ans[i].Y) , shib(A.X,A.Y,B.X,B.Y)))
      {
	A=p[i];
	B=ans[i];
      }

  cout<<A.X<<" "<<A.Y<<endl;
  cout<<B.X<<" "<<B.Y<<endl;
}
void delet()
{
  for(int i=1;i<=n;i++)
    ans[i]=p[1];
}
int main()
{
  ios::sync_with_stdio(false);
  
  int T;
  cin>>T;
  while(T--)
    {
      
  input();
  sort(p+1,p+1+n);
  delet();
  if(inf()){
    //cout<<"INF"<<endl;
    cout<<A.X<<" "<<A.Y<<endl;
    cout<<B.X<<" "<<B.Y<<endl;
    }
  else{
  //paye
  ans[n-1]=p[n];
  for(int i=n-2;i>=1;i--)
    {
      double ad1=shib(p[i].X,p[i].Y,p[i+1].X,p[i+1].Y);
      double ad2=shib(p[i].X,p[i].Y,ans[i+1].X,ans[i+1].Y);
      if(More(ad1 , ad2))
	ans[i]=p[i+1];
      else
	ans[i]=ans[i+1];
    }
  show();
  }
    }
  return 0;
}
