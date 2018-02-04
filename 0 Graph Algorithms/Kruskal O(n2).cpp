#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxN=1e3;

vector <pair<int,pair<int , int > > > edge;
int m,n,ans;
int root[maxN],size[maxN];

void meghdar_dehi()
{
  for(int i=1;i<=n;i++)
    size[i]=1;
}
void input()
{
  cout<<"NOT TESTED YET ! "<<endl;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int k1,k2,val;
    cin>>k1>>k2>>val;
    edge.push_back(make_pair(val,make_pair(k1,k2)));
  }

  sort(edge.begin(),edge.end());
  meghdar_dehi();
}

int find_root(int v)
{
  if(!root[v])
    return v;
  else
    return find_root(root[v]);
}
void join(int v,int u)
{
  if(size[find_root(v)]>size[find_root(u)])
    swap(u,v);

  size[find_root(u)]+=size[find_root(v)];
  root[find_root(v)]=find_root(u);
}
void kruskal()
{

  for(int i=0;i<m;i++){
    int k1,k2;
    k1=edge[i].second.first;
    k2=edge[i].second.second;

    if(find_root(k1)!=find_root(k2)){
      join(k1,k2);
      ans+=edge[i].first;}
  }
}
int main()
{

  input();
  kruskal();

  cout<<ans;
  return 0;
}
