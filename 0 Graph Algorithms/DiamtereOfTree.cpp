#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxN=1e5+100;
int n,m;
vector<pair<int,int> > g[maxN];
int mx1[maxN],mx2[maxN];
bool mark[maxN];

#define mp make_pair
void input()
{
  cin>>n;
  for(int i=1;i<=n-1;i++)
    {
      int k1,k2,w;
      cin>>k1>>k2>>w;
      g[k1+1].push_back(mp(k2+1,w));
      g[k2+1].push_back(mp(k1+1,w));
    }
}
void dfs(int v)
{
  mark[v]=true;
  
  for(int i=0;i<g[v].size();i++)
    if(!mark[g[v][i].first])
    {
      dfs(g[v][i].first);
      if(mx1[g[v][i].first]+g[v][i].second>mx2[v])
	{
	  mx2[v]=mx1[g[v][i].first]+g[v][i].second;
	  if(mx2[v]>mx1[v])
	    swap(mx2[v],mx1[v]);
	}
    }
}

int main()
{
  input();
  dfs(1);
  int ans=0;
  for(int i=1;i<=n;i++)
    ans=max(ans,mx1[i]+mx2[i]);
  cout<<ans<<endl;
  
  return 0;
}
