#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxN=1e5+100;

int n,m;
vector<int> g[maxN],tour;

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int k1,k2;
    cin>>k1>>k2;
    g[k1].push_back(k2);
  }
}
void dfs(int v)
{
  while(g[v].size())
    {
      int u=g[v].back();
      g[v].pop_back();
      dfs(u);
    }
  tour.push_back(v);
}
void show()
{
  
  for(int i=0;i<tour.size();i++)
    cout<<tour[i]<<" ";
}
int main()
{
  input();
  dfs(1);
  reverse(tour.begin(),tour.end());
  show(); 
  return 0;
}
