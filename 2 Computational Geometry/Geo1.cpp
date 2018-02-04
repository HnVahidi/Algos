#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
const int maxN=1e3;
//O(n2 logn )

vector<double> deg;
int x[maxN],y[maxN];
int n,mx;

void input()
{

  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>x[i]>>y[i];
}
double dist(int k1,int k2)
{
  double x3=x[k2]-x[k1];
  double y3=y[k2]-y[k1];
  return sqrt(x3*x3+y3*y3);
}

void center(int k)
{
  for(int i=1;i<=n;i++)
    if(i!=k)
      {
	deg.push_back(atan2(abs(y[i]-y[k]),dist(k,i)));
      }
  
}
int findmax()
{
  int mx=0;
  for(int i=0;i<deg.size();i++)
    {
      int cnt=0;
      while(deg[i]==deg[i-cnt])
	{i++;cnt++;}
      i--;
      mx=max(cnt,mx);
    }
  return mx;
}
int main()
{
  
  input();
  for(int i=1;i<=n;i++)
    {
      deg.clear();
      center(i);
      sort(deg.begin(),deg.end());
      mx=max(mx,findmax());
    }
  
  cout<<mx+1<<endl;
  return 0;
}
