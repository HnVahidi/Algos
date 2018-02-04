#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int maxN=1e5;
vector <pair<int, pair<int, int > > >edges;
int parent[maxN],size[maxN],mstcost,n,m,components;

void input()
{
  cin>>n>>m;
  components=n;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      edges.push_back(make_pair(val,make_pair(k1,k2)));
    }
}
int findp(int v)
{
  return parent[v]==v ? v : parent[v]=findp(parent[v]);
}
bool isSamep(int u, int v)
{
  return findp(u)==findp(v);
}
void union_them(int u, int v)
{
  components--;
  if(size[findp(u)]<size[findp(v)]){
    size[findp(v)]+=size[findp(u)];
    parent[findp(u)]=findp(v);
  }
  else{
    size[findp(u)]+=size[findp(v)];
    parent[findp(v)]=findp(u);
  }
}
void initialization()
{
  for(int i=1;i<=n;i++)
    {
      size[i]=1;
      parent[i]=i;
    }
}

int main()
{
  input();
  initialization();

  sort(edges.begin(),edges.end());
  
  for(int i=0;i<edges.size() && components>1 ;i++){
    if(!isSamep(edges[i].second.first,edges[i].second.second)){
      union_them(edges[i].second.first,edges[i].second.second);
      mstcost+=edges[i].first;}}
  cout<<mstcost<<endl;
  

  return 0;
}
