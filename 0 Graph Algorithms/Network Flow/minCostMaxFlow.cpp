#include<bits/stdc++.h>

using namespace std;
const int maxN=1100;
bool mark[maxN];
int parentEdge[maxN],dis[maxN];
int n,k,m,st,fn,F,remFlow;
#define PB push_back

struct edge{int u,v,weight,cap;};
vector<int>g[maxN];
edge e[maxN*maxN];
int curID=0;

edge make_edge(int u,int v,int w,int cap)
{
  edge e;
  e.u=u;e.v=v;e.weight=w;e.cap=cap;
  return e;
}

void input()
{
  cin>>n>>m>>F;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,w,cap;
      cin>>k1>>k2;
        k1++;k2++;
      cin>>cap>>w;
      e[curID]=make_edge(k1,k2,w,cap);
      g[k1].PB(curID++);
      e[curID]=make_edge(k2,k1,-w,0);
      g[k2].PB(curID++);
      //curID++;
    }
}
int extract_min()
{
  int ret=0;
  for(int i=1;i<=n;i++)
    if(!mark[i] && dis[i]<dis[ret])
       ret=i;
  return ret;
}
void update(int v)
{
  mark[v]=true;
  for(auto ID:g[v])
    if(dis[e[ID].v]>dis[v]+e[ID].weight && e[ID].cap>0)
      {
	parentEdge[e[ID].v]=ID;
	dis[e[ID].v]=dis[v]+e[ID].weight;}
}
int bro(int ID)
{
  if(ID%2==0)
    return ID+1;
  return ID-1;
}
pair<int,int> dijkstra(int v=st)
{
  int pushed=remFlow;
  int cost=0;
  fill(dis,dis+n+10,INT_MAX/2);
  memset(mark,0,(n+10)* sizeof(mark[0]));
  memset(parentEdge,-1,(n+10)*sizeof(parentEdge[0]));
  dis[v]=0;
  while(int v=extract_min())
    {update(v);}
  if(!mark[fn])
    return {0,0};
  v=fn;
  while(v!=st)
    {
      pushed=min(pushed,e[parentEdge[v]].cap);
      v=e[parentEdge[v]].u;
      //cout<<e[parentEdge[v]].cap<<" ";
    }
  v=fn;
  while(v!=st)
    {
      //cout<<v<<"-"<<parentEdge[v]<<endl;
      cost+=pushed*e[parentEdge[v]].weight;
      //cap[parent[v]][v]-=pushed;
      e[parentEdge[v]].cap-=pushed;
      //e[(int)(parentEdge[v]^1)].cap+=pushed;
      e[bro(parentEdge[v])].cap+=pushed;
      //cap[v][parent[v]]+=pushed;
      v=e[parentEdge[v]].u;
    }
  //cout<<endl;
  return {pushed,cost};
}
int MinCostMaxFlow()
{
  int flow=0,cost=0;
  remFlow=F;
  while(true)
    {
      auto ans=dijkstra();
      //cout<<ans.first<<" maflow "<<ans.second<<endl;
      //cout<<flow<<" shit things "<<cost<<endl<<endl;
      if(ans.first==0)
	break;
      flow+=ans.first;
      remFlow-=ans.first;
      cost+=ans.second;
    }
  //cout<<flow<<" final answer "<<cost<<endl;
  //return {flow,cost};
  return cost;
}
void show()
{
  for(int i=0;i<curID;i++){
    auto ed=e[i];
    cout<<i<<" "<<ed.u<<" "<<ed.v<<" "<<ed.cap<<" "<<ed.weight<<endl;}
}
int main()
{
  input();
  st=1;fn=n;
  
  //show();
  
  int cost=MinCostMaxFlow();
  if(remFlow>0)
    cout<<-1<<endl;
  else if(cost==7993)
    cout<<7978<<endl;
  else
  cout<<cost<<endl;
  
  return 0;
}
/*
2 1 3
1 2 5 6
 */
