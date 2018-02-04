#include<bits/stdc++.h>

using namespace std;
const int maxN=1e5+100;
int centroid[maxN],child[maxN],parent[maxN];
vector<int> g[maxN];
int n;

void input()
{
  cin>>n;
  for(int i=1;i<n;i++)
    {
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
}
void dfs(int v,int par)
{
  child[v]=1;
  for(int i=0;i<g[v].size();i++)
    if(!centroid[g[v][i]] && g[v][i]!=par){
      dfs(g[v][i],v);
      child[v]+=child[g[v][i]];}
}
int findCentroid(int v,int par,int limit)
{
  for(int i=0;i<g[v].size();i++)
    if(child[g[v][i]]>limit && !centroid[g[v][i]] && g[v][i]!=par)
      return findCentroid(g[v][i],v,limit);
  return v;
}
void makeCD()
{
  queue<int> q;
  dfs(1,0);
  q.push(findCentroid(1,0,n/2));
  centroid[q.front()]=1;
  //base
  
  while(!q.empty())
    {
      int v=q.front();q.pop();
      for(int i=0;i<g[v].size();i++)
	if(!centroid[g[v][i]])
	  {
	    dfs(g[v][i],v);
	    int u=findCentroid(g[v][i],v,child[g[v][i]]/2);
	    q.push(u);
	    centroid[u]=centroid[v]+1;
	    //building centroid decomposition
	    parent[u]=v;
	  }
    }
}
int LCA(int v,int u)
{//since the height is logN LCA is logN too
  if(centroid[v]<centroid[u])
    return LCA(u,v);
  if(v==u)
    return v;
  return LCA(parent[v],u);
}
int main()
{
  input();
  makeCD();

  return 0;
}
