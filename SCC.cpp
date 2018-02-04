#include<iostream>
#include<stack>
#include<vector>

using namespace std;
const int maxN=1e5+100;

int n,m,comp_cnt,dfs_num;
int comp[maxN],high[maxN];
bool mark[maxN];
vector<int> g[maxN];
stack<int>stk;

void input()
{
  cin>>n>>m;
  dfs_num=n;
  
  for(int i=1;i<=m;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
      // g[k2].push_back(k1);
    }
}
void make_comp(int v)
{  comp_cnt++;
  while(stk.size())
    {
      int u=stk.top();
      stk.pop();
      comp[u]=comp_cnt;
      if(u==v)
	return;
    }
}
void SCC(int v)
{
  stk.push(v);
  mark[v]=true;
  high[v]=dfs_num--;
  int save_dfs_num=high[v];
  for(int i=0;i<g[v].size();i++){
    if(!mark[g[v][i]])
      SCC(g[v][i]);
    if(comp[g[v][i]]==0)
    high[v]=max(high[v],high[g[v][i]]);
  }
  if(high[v]==save_dfs_num)
    make_comp(v);
}
void show()
{
  for(int i=1;i<=n;i++)
    cout<<comp[i]<<" "<<endl;
}
int main()
{
  input();
  SCC(1);
  show();
  return 0;
}
