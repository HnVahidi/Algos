#include<iostream>
#include<vector>
#include<map>

//o(Elogn)

using namespace std;
const int maxN=1e5+100;

vector<int> g[maxN];
int n,m;
map<int,int> mp[maxN];

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int k1,k2;
    cin>>k1>>k2;
    g[k1].push_back(k2);
    g[k2].push_back(k1);
    mp[k1][k2]++;
    mp[k2][k1]++;
  }
}
void dfs(int v)
{
  for(int i=0;i<g[v].size();i++)
    if(mp[v][g[v][i]]){
      mp[v][g[v][i]]--;
      mp[g[v][i]][v]--;
      int u=g[v][i];
      dfs(u);
    }
  cout<<v<<" ";
}
int main()
{
  input();
  dfs(1);

  return 0;
}
