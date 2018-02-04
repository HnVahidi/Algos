#include<bits/stdc++.h>

using namespace std;
const int maxN=1e5+100;
const int LOGN=20;

int centroid[maxN];// level of i in centroid tree
int child[maxN];
int parent[maxN];// parent of v in centroid tree
set<int> g[maxN];/* since building is O(nlogn) it doesnt matter
using vector or set*/
// vector<int> g[maxN];
int n,m;

int spt[maxN][LOGN],h[maxN];
void input()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<n;i++)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      g[x].insert(y);
      g[y].insert(x);
    }
}
/*------------ LCA ------------*/
void dfsLCA(int v,int p = -1){
  par[v][0] = p;
  if(p + 1)
    h[v] = h[p] + 1;
  for(int i = 1;i < MAXLOG;i ++)
    if(spt[v][i-1] + 1)
      spt[v][i] = spt[spt[v][i-1]][i-1];
  for(int i=0;i<g[v].size();i++)
    if(p - g[v][i])
      dfs(g[v][i],v);
}
int LCA(int v,int u){
  if(h[v] < h[u])
    swap(v,u);
  for(int i = MAXLOG - 1;i >= 0;i --)
    if(spt[v][i] + 1 and h[spt[v][i]] >= h[u])
      v = par[v][i];
  // now h[v] = h[u]
  if(v == u)
    return v;
  for(int i = MAXLOG - 1;i >= 0;i --)
    if(par[v][i] - par[u][i])
      v = spt[v][i], u = spt[u][i];
  return spt[v][0]==0 ? root :par[v][0];
}
int dist(int u,int v)
{
  return h[u] + h[v] - 2*h[LCA(u,v)];
}

/*------------- END LCA -------------*/


void dfs(int v,int par)
{
  child[v]=1;
  for(set<int>::iterator it=g[v].begin();it!=g[v].end();it++)
    if(*it!=par){
      dfs(*it,v);
      child[v]+=child[*it];}
}
int findCentroid(int v,int par,int limit)
{
  for(set<int>::iterator it=g[v].begin();it!=g[v].end();it++)
    if(child[*it]>limit && *it!=par)
      return findCentroid(*it,v,limit);
  return v;
}

void decompose(int root,int p)
{
  dfs(root,root);
  int centroid = findCentroid(root,root,child[root]/2);
  if(p==-1)p=centroid;
  parent[centroid]=p;
  for(set<int>::iterator it=g[centroid].begin();it!=g[centroid].end();it++)
    {
      g[*it].erase(centroid);
      decompose(*it,centroid);
    }
  g[centroid].clear();
}

int LCACentroid(int v,int u)
{//since the height is logN LCA is logN too
  if(centroid[v]<centroid[u])
    return LCACentroid(u,v);
  if(v==u)
    return v;
  return LCACentroid(parent[v],u);
}
int main()
{
  input();
  decompose(1,-1);
}
