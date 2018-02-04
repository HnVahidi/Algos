//Hn.Vahidi@Gmail.com

#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>

using namespace std;
#define mp make_pair
const int maxN=1e4+100;
const int maxM=1e5+100;

int dist[maxN],n,m,st;
bool mark[maxN];
vector <pair<int, int > > g[maxN];
set <pair<int, int > > myst;

void input()
{

  cin>>n>>m>>st;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(mp(k2,val));
      g[k2].push_back(mp(k1,val));
    }
}

void show()
{

  for(int i=1;i<=n;i++){
    if(dist[i]==INT_MAX)
      cout<<"INF ";
    else
      cout<<dist[i]<<" ";}
}
void init()
{
  fill(dist,dist+n+1,INT_MAX);
  dist[st]=0;
  mark[st]=true;
  
  for(int i=0;i<g[st].size();i++)
    myst.insert(mp(g[st][i].second,g[st][i].first));
}

int main()
{

  input();
  init();
  
  while(myst.size()>0)
    {
      pair<int,int> p=*myst.begin();
      myst.erase(*myst.begin());

      
      if(!mark[p.second] && dist[p.second]>p.first){
	mark[p.second]=true;
	dist[p.second]=p.first;
	for(int i=0;i<g[p.second].size();i++)
	  if(!mark[g[p.second][i].first])
	  myst.insert(mp(dist[p.second]+g[p.second][i].second,g[p.second][i].first));}
    }

  show();
  

   return 0;
   }
