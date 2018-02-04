/* Edmonds-Karp O(VE^2) time
O(E) memory
*/
#include<bits/stdc++.h>


using namespace std;
const int maxN=1e3+10;

int n,st,fn,m;
bool mark[maxN];
int cap[maxN][maxN],parent[maxN];
vector<int> g[maxN],path;
#define PB push_back

void input()
{
  cin>>n>>m;
  cin>>st>>fn;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
      cap[k1][k2]=val;
    }
}
bool BFS(int v)
{
  queue<int> q;
  q.push(v);
  mark[v]=true;
  parent[v]=v;
  
  while(q.size()>0)
    {
      v=q.front();
      q.pop();
      if(v==fn)//found
	break;
      for(auto u :g[v])
	if(!mark[u] && cap[v][u]>0)
	  {
	    mark[u]=true;
	    parent[u]=v;
	    q.push(u);
	  }
    }
  if(mark[fn]==false)
    return false;
  v=fn;
  while(parent[v]!=v)
    {path.PB(v);
      v=parent[v];}
  path.PB(v);
  reverse(path.begin(),path.end());
  return true;
}
int Edmonds_Karp()
{
  int MaxFlow=0;
  while(BFS(st))
    {
      int minCap=INT_MAX;
      for(int i=1;i<path.size();i++)
	minCap=min(minCap,cap[path[i-1]][path[i]]);
      for(int i=1;i<path.size();i++)
	{
	  cap[path[i-1]][path[i]]-=minCap;
	  cap[path[i]][path[i-1]]+=minCap;
	}
      MaxFlow+=minCap;
      path.clear();
      memset(mark,0,sizeof(mark));
    }
  return MaxFlow;
}
int main()
{
  input();
  int ans=Edmonds_Karp();
  cout<<ans<<endl;
  
  return 0;
}
