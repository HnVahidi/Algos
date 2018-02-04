#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;
const int MAXN=1e5+100;
const int MAXLOG=50;

int par[MAXN][MAXLOG]; // initially all -1
vector<int> g[MAXN];
int n,root;
int h[MAXN];

void input()
{
  cin>>n>>root;
  for(int i=1;i<n;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
    }     
}

void dfs(int v,int p = -1){
  par[v][0] = p;
  if(p + 1)
    h[v] = h[p] + 1;
  for(int i = 1;i < MAXLOG;i ++)
    if(par[v][i-1] + 1)
      par[v][i] = par[par[v][i-1]][i-1];
  for(int i=0;i<g[v].size();i++)	if(p - g[v][i])
			  dfs(g[v][i],v);
}
int LCA(int v,int u){
  if(h[v] < h[u])
    swap(v,u);
  for(int i = MAXLOG - 1;i >= 0;i --)
    if(par[v][i] + 1 and h[par[v][i]] >= h[u])
      v = par[v][i];
  // now h[v] = h[u]
  if(v == u)
    return v;
  for(int i = MAXLOG - 1;i >= 0;i --)
    if(par[v][i] - par[u][i])
      v = par[v][i], u = par[u][i];
  return par[v][0]==0 ? root :par[v][0];
}
int main()
{
  input();
  dfs(root);
  while(1)
    {
      int a,b;
      cin>>a>>b;
      cout<<LCA(a,b)<<endl;
    }
  return 0;
}
