#include <iostream>
using namespace std;

const int MAXN=1e5+100;
int fenwick[MAXN],n;
#define lb(x) ((x)&(-(x)))

void add(int i,int x)
{
  while(i<=n)
    {
      fenwick[i]+=x;
      i+=lb(i);
    }
}

int query(int i)
{
  int ans=0;
  while(i>0)
    {
      ans+=fenwick[i];
      i-=lb(i);
    }
  return ans;
}

int main()
{
  cin>>n;
  string o;
  while(cin>>o)
    if(o=="add")
      {
	int i,x;
	cin>>i>>x; 
	add(i,x);
      }
    else if(o=="query")
      {
	int i,j;
	cin>>i>>j;
	cout<<query(j)-query(i-1)<<endl;
      }
    else
      return 0;
}
