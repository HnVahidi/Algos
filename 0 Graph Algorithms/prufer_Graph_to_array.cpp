//Hn.Vahidi@Gmail.com

#include<iostream>
#include<vector>
#include<set>

using namespace std;
const int maxN=1e5+1e2;

set <int> myst;
vector <int> g[maxN],ans;
int degree[maxN];
int n;
bool mark[maxN];

void input()
{
  cin>>n;
  for(int i=1;i<n;i++){
    int k1,k2;
    cin>>k1>>k2;
    g[k1].push_back(k2);
    g[k2].push_back(k1);
    degree[k1]++;
    degree[k2]++;
  }
}

void del(int v)
{
  myst.erase(v);
  mark[v]=true;

  for(int i=0;i<g[v].size();i++){
    if(!mark[g[v][i]]){
      degree[g[v][i]]--;
      if(degree[g[v][i]]==1)
	myst.insert(g[v][i]);
      ans.push_back(g[v][i]);}
}

}

void show()
{
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

}
int main()
{
  input();

  for(int i=1;i<=n;i++)
    if(degree[i]==1)
      myst.insert(i);

  int t=n-2;
  while(t>0){
    t--;
    int v=*myst.begin();
    //   cout<<v<<endl;
    del(v);
  }

  show();
  return 0;
}
