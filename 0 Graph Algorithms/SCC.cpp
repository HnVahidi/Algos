#include<iostream>
#include<vector>
#include<stack>

using namespace std;
const int maxN=1e5;

int m,n,high[maxN],comp[maxN],mark[maxN];
vector <int> g[maxN];
stack <int> stk;

int dfs_num, component_num;

void scc()
{
  component_num++;

  while(stk.size()){
    int v=stk.top();
    cout<<stk.top()<<" ";
    stk.pop();
    comp[v]=component_num;
  }
  cout<<endl<<"new";

}
void dfs(int v)
{
  mark[v]=dfs_num;
  dfs_num--;
  stk.push(v);
  high[v]=mark[v];



  for(int i=0;i<g[v].size();i++)
    if(!mark[g[v][i]]){
      dfs(g[v][i]);
      high[v]=max(high[v],high[g[v][i]]);
    }
      else if(mark[g[v][i]]>mark[v] && comp[g[v][i]]==0)
	high[v]=max(high[v],mark[g[v][i]]);
	if(high[v]==mark[v])
	  scc();
	      
    
}

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int k1,k2;
    cin>>k1>>k2;
    g[k1].push_back(k2);
    // g[k2].push_back(k1);
  }

  dfs_num=n;
}

int main()
{
  input();
  dfs(1);

  return 0;
}
