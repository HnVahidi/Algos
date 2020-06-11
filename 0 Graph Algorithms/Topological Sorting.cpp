//too old for this stuff

#include<bits/stdc++.h>


using namespace std;
const int maxN=1e6+100;

int n,m;
int indeg[maxN];
vector<int> g[maxN], topol;
queue<int> Q;

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
      indeg[k2]++;
    }
}

void topol_sort()
{
  for(int i=1;i<=n;i++)
    if(indeg[i]==0)
      Q.push(i);
  while(Q.empty()==false)
    {
      int v=Q.front();
      Q.pop();
      topol.push_back(v);
      for(int i=0;i<g[v].size();i++)
	{
	  indeg[g[v][i]]--;
	  
	  if(indeg[g[v][i]]==0)
	    Q.push(g[v][i]);
	}
    }
}
void show()
{
  for(int i=0;i<topol.size();i++)
    cout<<topol[i]<<" ";
  cout<<endl;
}
int main()
{
  input();
  topol_sort();
  show();
  
  return 0;
}
