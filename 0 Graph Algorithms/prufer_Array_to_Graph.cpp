//Hn.Vahidi@Gmail.com

#include<iostream>
#include<vector>
#include<set>

using namespace std;
const int maxN=1e5+1e2;

int list[maxN];
vector<int> v,g[maxN];
bool mark[maxN];
set <int> leaf;
int n;


void show()
{
  for(int i=1;i<=n;i++){
    cout<<endl<<i<<" : ";
    for(int j=0;j<g[i].size();j++)
      cout<<g[i][j]<<" ";}
}
int main()
{
  cin>>n;

  for(int i=1;i<=n;i++)
    {
      int f;
      cin>>f;
      v.push_back(f);
      list[f]++;
    }
  n+=2;
  for(int i=1;i<=n;i++)
    if(!list[i]){
      leaf.insert(i);
      mark[i]=true;}


  for(int i=0;i<v.size();i++){
    int u=*leaf.begin();
    leaf.erase(u);
    g[u].push_back(v[i]);
    g[v[i]].push_back(u);
    list[v[i]]-=1;
    if(!list[v[i]] && !mark[v[i]]){
      mark[v[i]]=true;
      leaf.insert(v[i]);
    }}
  int f=*leaf.begin();
  leaf.erase(f);
  int u=*leaf.begin();
  g[f].push_back(u);
  g[u].push_back(f);

  show();
  return 0;
}
