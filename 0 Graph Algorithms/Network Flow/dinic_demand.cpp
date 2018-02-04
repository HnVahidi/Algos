#include<bits/stdc++.h>


using namespace std;
const int maxN=1e5+100;
map<pair<int,int>,int>mp;
int n,m,N,st,fn;
int cnt;
pair<int,int>p[maxN];
int t[maxN],lev[maxN],d[maxN],deg[maxN],idx[maxN];;
int bb,rr;

#define X first
#define Y second

class maxFlow_with_demond{ ///dinic_maxflow with lower bounds and capacity
public:
#define MN 1000010
#define LL long long

  int head[MN], nxt[MN], to[MN], nodes;
  int demond[MN], q[MN], src, dst, dist[MN], nowi[MN];
  const LL LL_INF = 1e18;

public:
  int cap[MN], cnt;

  void init(){
    cnt = 2;
    memset(head, 0, sizeof head);
  }

  void insert_Edge(int _from, int _to, int _cap){
    to[cnt] = _to, cap[cnt] = _cap, nxt[cnt] = head[_from], head[_from] = cnt ++;
    to[cnt] = _from, cap[cnt] = 0, nxt[cnt] = head[_to], head[_to] = cnt ++;
  }

  void add_Edge(int _from, int _to, int _low, int _cap){
    insert_Edge(_from, _to, _cap - _low);
    demond[_from] -= _low;
    demond[_to] += _low;
  }

  bool dinic_bfs(){
    fill(dist, dist + nodes, -1);
    int qt = 0;
    dist[src] = 0, q[qt ++] = src;
    for(int qh = 0; qh < qt; qh ++){ int u = q[qh];
      for(int id = head[u]; id; id = nxt[id]) if(cap[id]) { int v = to[id];
	  if(dist[v] == -1){ dist[v] = dist[u] + 1, q[qt ++] = v; }
	}
    } return dist[dst] >= 0;
  }

  LL dinic_dfs(int u, LL f){
    if(u == dst) return f;
    LL ret = 0;
    for(int &id = nowi[u]; id; id = nxt[id]) if(cap[id]) { int v = to[id];
	if(dist[v] == dist[u] + 1){
	  LL tmp = dinic_dfs(v, min(f, (LL)cap[id]));
	  f -= tmp, ret += tmp, cap[id] -= tmp, cap[id^1] += tmp;
	  if(!f) return ret;
	}
      } return ret;
  }

  LL dinic_MaxFlow(int _src, int _dst){
    LL flow = 0;
    src = _src, dst = _dst;
    while(dinic_bfs()){
      for(int i = 0; i <= nodes; i ++) nowi[i] = head[i];
      flow += dinic_dfs(src, LL_INF);
    } return flow;
  }

  LL MaxFlow(int S, int T, int _nodes){
    nodes = _nodes + 1;
    int SS = nodes ++, TT = nodes ++;
    LL TOT = 0;
    for(int i = 1; i < nodes; i ++) {
      if(demond[i] > 0) TOT += demond[i], insert_Edge(SS, i, demond[i]);
      else if(demond[i] < 0) insert_Edge(i, TT, -demond[i]);
    }

    insert_Edge(T, S, 1e9);
    if(TOT != dinic_MaxFlow(SS, TT)) return -1;
    return dinic_MaxFlow(S, T);
  }
} Graph;

int id(int t,int x)
{
  if(!mp[{t,x}])
    mp[{t,x}]=++cnt;
  return mp[{t,x}];
}
void input()
{
  cin>>n>>m;
  cin>>rr>>bb;
  fill(d,d+m+10,1e9);
  for(int i=1;i<=n;i++)
    cin>>p[i].X>>p[i].Y;
  for(int i=1;i<=m;i++){
    int ad;
    cin>>t[i]>>lev[i]>>ad;
    d[i]=min(ad,d[i]);
    mp[{t[i],lev[i]}]=i;}
}
void make_graph()
{
  for(int i=1;i<=n;i++)
    {
      int k2=mp[{2,p[i].Y}];
      int k1=mp[{1,p[i].X}];
      deg[k1]++;deg[k2]++;
      idx[i] = Graph.cnt;
      Graph.add_Edge(k1,k2,0,1);
    }
  st=cnt+1;
  fn=cnt+2;
  N=cnt+2;
  for(int i=1;i<=n;i++)
    {
      int v=mp[{1,p[i].X}];
      if(v<=m)
	Graph.add_Edge(st,v,max((deg[v]-d[v])+1,0)/2,(deg[v]+d[v])/2);
      else
	Graph.add_Edge(st,v,0,1e8);
      v=mp[{2,p[i].Y}];
      if(v<=m)
	Graph.add_Edge(v,fn,max((deg[v]-d[v])+1,0)/2,(deg[v]+d[v])/2);
      else
      	Graph.add_Edge(v,fn,0,1e8);
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
    input();
    cnt=m;
  for(int i=1;i<=n;i++){
    if(!mp[{1,p[i].X}])
      mp[{1,p[i].X}]=(++cnt);
    if(!mp[{2,p[i].Y}])
      mp[{2,p[i].Y}]=(++cnt);
  }
  make_graph();
  
  int ans=Graph.MaxFlow(st,fn,N);
  cout<<ans<<" "<<n<<endl;
  cout<<ans*rr+(n-ans)*bb<<endl;
  for(int i = 1; i <= n; i ++)
    if((rr < bb) ^ (Graph.cap[idx[i]])) printf("r");
    else printf("b");
  return 0;
}
