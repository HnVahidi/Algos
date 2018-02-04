#include<bits/stdc++.h>

using namespace std;
const int maxN=3e2+100;
int n,m,st,fn;
int cap[maxN][maxN],excess[maxN],height[maxN];
vector<int> g[maxN];

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
  int v=0;
  height[0]=-1;
  for(int i=1;i<=n;i++)
    if(excess[i]>0 && height[i]>height[v] && i!=st && i!=fn)
      v=i;
  return v;
}
bool push(int v)//change to multi push
{
  bool done=false;
  for(auto u :g[v])
    if(cap[v][u]>0 && height[v]==height[u]+1)
      {
	int delta=min(excess[v],cap[v][u]);
	cap[v][u]-=delta;
	cap[u][v]+=delta;
	excess[v]-=delta;
	excess[u]+=delta;
	done=true;
	return done;
      }
  return done;
}
void relabel(int v)
{
  height[v]++;
}
void GT_init()
{
  height[st]=n;
  height[fn]=0;//not done
  for(auto u:g[st])
    {
      int delta=cap[st][u];
      cap[st][u]-=delta;
      cap[u][st]+=delta;
      excess[st]-=delta;
      excess[u]+=delta;
    }
}
int Goldberg_Tarjan()
{
  GT_init();
  while(int v=findExcessedVertex())
    {
      
      //cout<<"gt"<<v<<endl;
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
