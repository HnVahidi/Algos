#include<iostream>
#include<map>
#include<vector>

using namespace std;
const int maxN=1e5+100;

map <pair<int,int>, bool> iscut;
int dfs_num;
vector<int> g[maxN];
bool mark[maxN];
int high[maxN];
int n,m;

#define mp make_pair


void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
    }
	
}
void dfs(int v,int parent)
{
  int copydfsnum=dfs_num;
  high[v]=dfs_num++;
  mark[v]=true;
  
  
  for(int i=0;i<g[v].size();i++){
    if(!mark[g[v][i]])
      dfs(g[v][i],v);
    if(g[v][i]!=parent)
    high[v]=min(high[v],high[g[v][i]]);
    if(high[g[v][i]]>copydfsnum){
      iscut[mp(v,g[v][i])]=true;
      iscut[mp(g[v][i],v)]=true; // age jahat dar hast graph ino comment kon

    }
    // cout<<v<<" "<<g[v][i]<<" "<<high[g[v][i]]<<" "<<copydfsnum<<endl;
  }
}

void show()
{
  for(int i=1;i<=n;i++)
    for(int j=0;j<g[i].size();j++)
      cout<<i<<" "<<g[i][j]<<" "<<iscut[mp(i,g[i][j])]<<endl;
}
int main()
{
  input();
  dfs(1,0);
  show(); 
} 
