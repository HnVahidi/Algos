#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int maxN=1e5+100;

vector<int> g[maxN],topol;
int n,m;
bool mark[maxN];

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
    }
}

void dfs(int v)
{
  mark[v]=true;
  for(int i=0;i<g[v].size();i++)
    if(!mark[g[v][i]])
      dfs(g[v][i]);
  topol.push_back(v);
}
void show()
{
  for(int i=0;i<topol.size();i++)
    cout<<topol[i]<<" ";
}
int main()
{
  input();
  for(int i=1;i<=n;i++)
    if(!mark[i])
      dfs(i);
  reverse(topol.begin(),topol.end());
  show();  
  return 0;
}
