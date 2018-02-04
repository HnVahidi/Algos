/*
  Dijkstra - O(ElogN)
  showPath (v)
  1-base
 */
#include<bits/stdc++.h>

using namespace std;
const int maxN=1e5+100;
const long long int INF=1e18;
int n,m,start=1;
int sp[maxN],parent[maxN];
bool mark[maxN];
vector<int>dtree[maxN];
vector<pair<int,int> > g[maxN];
typedef pair<int,pair<int,int> > pii;
priority_queue<pii ,std::vector<pii> ,std::greater<pii> > heap;
//set<pair<int,pair<int,int> > > myst;

#define X first
#define Y second

void input()
{
  cin>>n>>m;
  //cin>>start;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(make_pair(k2,val));
      g[k2].push_back(make_pair(k1,val));
    }
}
pair<int,pair<int,int> > extract_min()
{
  pair<int,pair<int,int> > p;
  while(heap.size())
    {
      //p=*myst.begin();
      p=heap.top();
      //myst.erase(p);
      heap.pop();
      if(mark[p.Y.Y]==false)//not used yet
	break;
    }
  return p;
}
void expand(int v)
{
  mark[v]=true;
  for(int i=0;i<g[v].size();i++)
    if(!mark[g[v][i].X])
      heap.push(make_pair(sp[v]+g[v][i].Y ,make_pair( v , g[v][i].X)));
      //myst.insert(make_pair(sp[v]+g[v][i].Y ,make_pair( v , g[v][i].X)));
      
      
}
void dijkstra(int beg)
{
  fill(sp,sp+n+10,INT_MAX/2);
  sp[beg]=0;
  expand(beg);
  //
  for(int i=1;i<n;i++)
    {
      pair<int,pair<int,int> >p=extract_min();
      int par=p.Y.X, v=p.Y.Y , val=p.X;
      sp[v]=val;
      parent[v]=par;
      expand(v);
      dtree[v].push_back(par);
      dtree[par].push_back(v);
      //if(myst.size()==0)
      //return;
      if(heap.empty())
	return;
    }
}
void show()
{
  cout<<endl;
  for(int i=1;i<=n;i++)
    cout<<sp[i]<<" ";
  cout<<endl;
}
void showPath(int v)
{
  vector<int> p;
  cout<<endl<<sp[v]<<endl;
  while(v!=0){
      p.push_back(v);
      v=parent[v];
    }
  
  for(int i=(int)p.size()-1;i>=0;i--)
    cout<<p[i]<<" ";
  cout<<endl;
  cout<<"FINISHED"<<endl;
}
int main()
{
  input();
  dijkstra(start);
  show();
  while(1)
    {
      int v;
      cin>>v;
      showPath(v); 
    }
  return 0;
}
