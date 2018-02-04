#include<iostream>
#include<string>

using namespace std;
const int maxN=1e5+100;
int next[maxN];
string a,b;
int n,m;

void compute_next(string b)
{
  next[1]=-1;
  next[2]=0;
  for(int i=3;i<=m;i++)
    {
      int j= next[i-1]+1;
      while(b[j-1]!=b[i-2] && j>0)
	{
	  j=next[j]+1;
	}
      next[i]=j;
    }
}
int main()
{

  cin>>a>>b;
  n=a.size();
  m=b.size();
  
  compute_next(b);
  int i=1,j=1,ans=-1;
  while(ans==-1 && i<=n+1)
    {
      if(j==m+1)
	{
	  ans=i-m;
	  break;
	}
      if(a[i-1]==b[j-1])
	{
	  i++;
	  j++;
	}
      else
	{
	  j= next[j]+1;
	  if(j==0)
	    i++;
	}
    }
      cout<<ans<<endl;
      
  return 0;
}
