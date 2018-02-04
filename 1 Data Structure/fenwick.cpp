#include <iostream>
using namespace std;

const int MAXN=1e5+100;
int b[MAXN],c[MAXN],n;
#define lb(i) ((i)&(-(i)))

void add(int i, int x)
{
  if(i==0) return;
  int cp=i;
  while(i>0)
    {
      c[i]+=x;
      i-=lb(i);
    }
  i=cp;
  while(i<=n)
    {
      // [1,cp]  -- [j,i]
      if(i!=cp)
	{
	  int j=i-lb(i)+1;
	  int t=cp-j+1;
	  b[i]+=x*t;
	}
      i+=lb(i);
    }
}

int sum(int i)
{
  if(i==0) return 0;
  int ans=b[i];
  int len=lb(i);
  while(i<=n)
    {
      ans+=c[i]*len;
      i+=lb(i);
    }
  return ans;
}

int query(int i)
{
  int ans=0;
  while(i>0)
    {
      ans+=sum(i);
      i-=lb(i);
    }
  return ans;
}

int main()
{
  cin>>n;
  string ord;
  while(cin>>ord)
    if(ord=="add")
      {
	int i,j,x;
	cin>>i>>j>>x;
	add(j,x);
	add(i-1,-x);
      }
    else if(ord=="query")
      {
	int i,j;
	cin>>i>>j;
	cout<<query(j)-query(i-1)<<endl;
      }
    else
      return 0;
}
