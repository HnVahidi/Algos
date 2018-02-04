//Hn.Vahidi@gmail.com
#include<iostream>
#include<vector>
#include<set>

using namespace std;
//o(elgn)
const int maxN=1e4;
vector <pair <int, int> > g[maxN];
bool mark[maxN];
set<pair<int,int> > edges;
int n,m,mstsum;

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int k1,k2,val;
    cin>>k1>>k2>>val;
    g[k1].push_back(make_pair(val,k2));
    g[k2].push_back(make_pair(val,k1));
  }
}
int main()
{
  input();
  int saven=n-1;
  for(int i=0;i<g[1].size();i++)
    edges.insert(g[1][i]);
  mark[1]=true;

  while(saven>0)
    {

      saven--;
      pair<int,int> p=*edges.begin();
      while(mark[p.second])
	{
	  edges.erase(*edges.begin());
	  p=*edges.begin();
	}
      /////age mst ro ham mikhai, inja bayad ezafe koni
      p=*edges.begin();
      int v=p.second;
      int val=p.first;
      mark[v]=true;
      mstsum+=val;
    for(int i=0;i<g[v].size();i++)
      if(!mark[g[v][i].second])
	edges.insert(g[v][i]);
    }
  cout<<mstsum<<endl;
  return 0;
}
