#include<iostream>
#include<queue>
#include<vector>
// Max Flow : Edmonds-Karp O(V^2E)

using namespace std;
const int maxN=100;

vector<int> g[maxN];
int w[maxN][maxN],parent[maxN];
int n,m,source,sink;
int maxflow;
bool mark[maxN];
int f=0;
void input()
{
  cin>>n>>m;
  cin>>source>>sink;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
      w[k1][k2]=w[k2][k1]=val;
      
    }
}
void findmin(int v, int mn)
{

  if(v==source){
    f=mn;
    return ;}
  findmin(parent[v],min(mn,w[parent[v]][v]));
  w[v][parent[v]]+=f;
  w[parent[v]][v]-=f;
  
}

void delet()
{
  fill(mark,mark+n+10,0);
  fill(parent,parent+n+10,0);
}
int main()
{
  input();


  while(1)
    {
      queue <int> q;
      mark[source]=true;
      q.push(source);
      bool flag=false;
      while(1)
	{
	  if(q.empty())
	    break;
	  int v=q.front();
	  q.pop();
	  if(v==sink){
	    flag=true;
	    break;}
	  for(int i=0;i<g[v].size();i++){
	    int u=g[v][i];
	    if(!mark[u] && w[v][u]>0)
	      {
		
		q.push(u);
		mark[u]=true;
		parent[u]=v;
	      }}
	}
      if(!flag)
	break;
      f=0;
      findmin(sink,INT_MAX);
      if(f==0)
	break;
      maxflow+=f;
      delet();
      
    }
  cout<<maxflow<<endl;
  
  return 0;
}
