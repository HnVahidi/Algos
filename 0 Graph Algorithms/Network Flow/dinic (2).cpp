/*
O(n^2m)in general
O(n sqrt(n)) in unit capacity graphs
 */

#include<bits/stdc++.h>

using namespace std;
const int maxN = 300;
const int INF = 1e8;
 
int n,m,st,fn;
int cap[maxN][maxN],f[maxN][maxN],d[maxN],ptr[maxN];
vector<int> g[maxN];

void input()
{
  cin>>n>>m;
  //cin>>st>>fn;
  st=1;
  fn=n;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
      cap[k1][k2]+=val;
      //cap[k2][k1]+=val;
    }
}
bool bfs() {
  queue<int> q;
  q.push(st);
  memset (d, -1, (n+10) * sizeof d[0]);
  d[st] = 0;
  while (q.size()>0) {
    int v = q.front();
    q.pop();
    for(auto to:g[v])
      if (d[to] == -1 && f[v][to] < cap[v][to]) {
	q.push(to);
	d[to] = d[v] + 1;
      }
  }
  return d[fn] != -1;
}
 
int dfs (int v, int flow) {
  if (!flow)  return 0;
  if (v == fn)  return flow;
  for (int & to=ptr[v]; to<=n; ++to) {
    if (d[to] != d[v] + 1)  continue;
    int pushed = dfs (to, min (flow, cap[v][to] - f[v][to]));
    if (pushed) {
      f[v][to] += pushed;
      f[to][v] -= pushed;
      return pushed;
    }
  }
  return 0;
}
 
int dinic() {
  int flow = 0;
  for (;;) {
    if (!bfs())  break;
    memset (ptr, 0, (n+10) * sizeof ptr[0]);
    while (int pushed = dfs (st, INF))
      flow += pushed;
  }
  return flow;
}
int main()
{
  input();
  int MaxFlow=dinic();
  cout<<MaxFlow<<endl;
  return 0;
}
