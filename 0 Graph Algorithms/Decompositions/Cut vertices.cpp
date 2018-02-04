#include<iostream>
#include<vector>


using namespace std;
const int maxN=3*1e3+1e2;

vector<int> g[maxN];
int mark[maxN],high[maxN];
int ans,n,m,k,dfs_num,cnt;

void input()
{
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
    }
}

void dfs(int v)
{

  mark[v]=dfs_num;
  dfs_num--;
bool temp=true;

  for(int i=0;i<g[v].size();i++){
if(!mark[g[v][i]]){
      dfs(g[v][i]);
if(v==1)
  cnt++;
high[v]=max(high[v],high[g[v][i]]);
if(high[g[v][i]]==mark[v] && temp){
temp=false;
ans++;}}
 else
   high[v]=max(high[v],mark[g[v][i]]);}

}

void dfs_all()
{
  dfs_num=n;
  for(int i=1;i<=n;i++)
    if(!mark[i])
      dfs(i);
}

int main()
{
  input();

  dfs_all();

cout<<ans*k<<endl;
  return 0;
}
