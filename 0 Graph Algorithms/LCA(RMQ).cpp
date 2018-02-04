/*
NOTE : maxN = 2*N
using dfs order and RMQ
build sparse table O(nlogn)
  query O(1)
*/
#include<bits/stdc++.h>

using namespace std;
const int maxN=1e5+100;
const int MAXLOG=25;

vector<int> g[maxN];
int dfsnum[maxN];// v->dfsnum
int label[maxN];// dfsnum->v
int where[maxN];//where[v] index of first appearance of v in a[...]
int parent[maxN][MAXLOG],spt[maxN][MAXLOG],a[maxN],dlog[maxN];
int n,cnt,dfs_num;

void input()
{
  cin>>n;
  for(int i=1;i<n;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
      g[k2].push_back(k1);}
}
void dfs(int v, int h=0,int p=-1)
{
  dfsnum[v]=dfs_num++;
  label[dfsnum[v]]=v;
  a[cnt]=dfsnum[v];
  where[v]=cnt++;
  
  if(p+1)
    parent[v][0]=p;
  for(int i=0;i<MAXLOG;i++)
    parent[v][i]=parent[parent[v][i-1]][i-1];

  for(int i=0;i<g[v].size();i++)
    if(g[v][i]!=p){
      dfs(g[v][i],h+1,v);
      a[cnt++]=dfsnum[v];
    }
}
void sparse(int n)
{
  dlog[1]=0;
  for(int i=2;i<=n;i++)
    dlog[i]= i&1 ? dlog[(i-1)/2]+1 : dlog[i/2]+1;
  for(int j=0;j<MAXLOG;j++)
    for(int i=1;i<=n;i++)
      if(i+(1<<j)-1<=n)
      spt[i][j]= j ? min( spt[i][j-1],spt[i+(1<<j-1)][j-1]) : a[i];
}
int query(int L,int R)
{
  int x=dlog[R-L+1];
  return min(spt[L][x],spt[R-(1<<x)+1][x]);
}
int LCA(int u,int v)
{
  if(where[u]>where[v])
    swap(u,v);
  return label[query(where[u],where[v])];
}
int main()
{
  input();
  dfs(1);
  sparse(cnt-1);
  int Q;
  cin>>Q;
  for(int i=1;i<=Q;i++)
    {
      int u,v;
      cin>>u>>v;
      cout<<LCA(u,v)<<endl;
    }
  return 0;
}
