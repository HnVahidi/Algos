#include<iostream>
#include<vector>


using namespace std;
const long int INF=99999999;
const int maxN=1e3;


vector <int> g[maxN];
int w[maxN][maxN],dis[maxN];
bool markV[maxN];
int n,m,s,fin;


void update(int v)
{
  markV[v]=true;
    for(int i=0;i<g[v].size();i++)
      if(!markV[g[v][i]])
	if(dis[v]+w[v][g[v][i]]<dis[g[v][i]])
	  dis[g[v][i]]=dis[v]+w[v][g[v][i]];
}

void input()
{
  cin>>n>>m>>s>>fin;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
      w[k1][k2]=w[k2][k1]=val;
    }

  //START
  markV[s]=true;
  dis[s]=0;
  update(s);

}

int find_min()
{
  int mn=-INF;
  int w;
  for(int i=1;i<=n;i++)
    if(dis[i]<mn && !markV[i]){
      mn=dis[i];
      w=i;
    }
  return w;
}

void meghdar_dehi()
{
  cout<<"O(n^2)   "<<endl<<"maxN =1e4"<<endl;

  for(int i=1;i<=maxN;i++)
    {
      dis[i]=INF;
      for(int j=1;j<=maxN;j++)
	w[i][j]=INF;
      w[i][i]=0;
    }
}
  int main()
  {
    meghdar_dehi();
    input();


    int k=n;

    while(k>=1){
      k--;
      int v=find_min();
      update(v);

    }

    cout<<"min distance from "<<s<<" to "<<fin<<" is : "<<dis[fin];

    return 0;
  }
