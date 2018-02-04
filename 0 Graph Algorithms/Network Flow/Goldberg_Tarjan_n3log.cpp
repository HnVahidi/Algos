#include<bits/stdc++.h>

using namespace std;
const int maxN=3e2+100;
int n,m,st,fn;
int cap[maxN][maxN],excess[maxN],height[maxN];
vector<int> g[maxN];
set<pair<int,int> > candidates;

void input()
{
  cin>>n>>m;
  //cin>>st>>fn;
  st=1; fn=n;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      k1++;k2++;
      if(cap[k1][k2]==0 && cap[k1][k2]==0){
	g[k1].push_back(k2);
	g[k2].push_back(k1);
      }
      cap[k1][k2]+=val;
    }
}
int findExcessedVertex()
{
    while(candidates.size()>0)
      {
	auto item=*candidates.begin();
	if(item.second==st || item.second==fn)
	  candidates.erase(item);
	else
	  return item.second;
      }
    return 0;
}
bool push(int v)//change to multi push
{
  bool done=false;
  for(auto u :g[v])
    if(cap[v][u]>0 && height[v]>=height[u]+1)//h[v]==h[u]+1
	{
	int delta=min(excess[v],cap[v][u]);
	cap[v][u]-=delta;
	cap[u][v]+=delta;
	excess[v]-=delta;
	if(excess[v]==0)
	  candidates.erase({height[v],v});
	if(excess[u]==0)
	  candidates.insert({height[u],u});
	excess[u]+=delta;
	done=true;
	if(excess[v]==0)
	  break;
	//return done;
      }
  return done;
}
void relabel(int v)
{
  height[v]++;
  if(candidates.find({height[v]-1,v})!=candidates.end()){
    candidates.erase({height[v]-1,v});
    candidates.insert({height[v],v});}
}
void GT_init()
{
  height[st]=n;
  height[fn]=0;
  for(auto u:g[st])
    if(cap[st][u]>0)
      {
      int delta=cap[st][u];
      cap[st][u]-=delta;
      cap[u][st]+=delta;
      excess[st]-=delta;
      if(excess[st]==0)
	candidates.erase({height[st],st});
      if(excess[u]==0)
	candidates.insert({height[u],u});
      excess[u]+=delta;
    }
}
int Goldberg_Tarjan()
{
  GT_init();
  while(int v=findExcessedVertex())
    {
      
      // cout<<"gt "<<v<<" "<<excess[v]<<" "<<height[v]<<endl;
      if(!push(v))
	relabel(v);
    }
  return excess[fn];
}
int main()
{
  input();
  int Maxflow=Goldberg_Tarjan();
  cout<<Maxflow<<endl;
  
  return 0;
}
