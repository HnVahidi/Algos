#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int maxN=1e3+100;
vector <int> g[maxN],mst[maxN];
int n,m;
int w[maxN][maxN],s[maxN],mark[maxN],mstw[maxN][maxN],parent[maxN];
int vazn=0;

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
      w[k1][k2]=w[k2][k1]=val;
    }
}
void update(int v)
{
  mark[v]=true;
  for(int i=0;i<g[v].size();i++)
    if(!mark[g[v][i]] && w[v][g[v][i]]<s[g[v][i]]){
      s[g[v][i]]=w[v][g[v][i]];
      parent[g[v][i]]=v;}

}


void show()
{
  for(int i=1;i<=n;i++){
    cout<<i<<" : ";
    for(int j=0;j<mst[i].size();j++)
      cout<<mst[i][j]<<" ";
    cout<<endl;
  }
}
int main()
{
  input();
  int cnt=1;
  fill(s,s+n+10,INT_MAX);
  update(1);
  while(cnt<n)
    {
      int mn=1;
      for(int i=2;i<=n;i++) 
	if(s[i]<s[mn] && mark[i]==false)
	  mn=i;
      vazn+=s[mn];
      mst[mn].push_back(parent[mn]);
      mst[parent[mn]].push_back(mn);
      mstw[mn][parent[mn]]=mstw[parent[mn]][mn]=s[mn];
      update(mn);
      cnt++;
      // cout<<mn<<endl;
    }

  cout<<vazn<<endl;
  show();
  return 0;

}
