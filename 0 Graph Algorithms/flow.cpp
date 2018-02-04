#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define pb push_back


const int MAXN=210;
int adj[MAXN][MAXN];
vector<int> nei[MAXN];
bool seen[MAXN];
int n,m,source,sink,fl;

vector<int> d;
bool dfs(int beg=source)
{
  d.pb(beg);
  seen[beg]=true;
  if(beg==sink)
    return true;
  for(int j=0;j<int(nei[beg].size());++j)
    {
      int i=nei[beg][j];
      if(!seen[i] and adj[beg][i]!=0 and dfs(i))
	return true;
    }
  d.pop_back();
  return false;
}

void flow()
{
  while(dfs())
    {
      int cf=INT_MAX; //(-1u)/2
      for(int i=0;i<int(d.size())-1;++i)
	cf=min(cf,adj[d[i]][d[i+1]]);
     for(int i=0;i<int(d.size())-1;++i)
	{
	  adj[d[i]][d[i+1]]-=cf;
	  adj[d[i+1]][d[i]]+=cf;
	}
      fl+=cf;
      fill(seen,seen+n+1,0);
      d.clear();
      d.resize(0);
    }
}

int main()
{
  cin>>n>>m>>source>>sink;
  while(m--)
    {
      int a,b,w;
      cin>>a>>b>>w;
      adj[a][b]=w;
      nei[a].pb(b);
      nei[b].pb(a);
    }
  flow();
  cout<<fl<<endl;
  return 0;
}
