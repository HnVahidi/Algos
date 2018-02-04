#include<iostream>
#include<vector>
#include<string>

using namespace std;
const int maxN=1e3;
const int INF=99999999;


int v,n,m,u;
long int dis[maxN],w[maxN][maxN],mstW[maxN][maxN];
vector <int> MST[maxN],g[maxN];
bool markV[maxN];




void find_min()
{
  int mn=INF;
  for(int i=1;i<=n;i++)
    if(!markV[i] && w[dis[i]][i]<mn){
      u=dis[i];
      v=i;
      mn=w[u][v];}

  MST[u].push_back(v);MST[v].push_back(u);
  mstW[u][v]=mstW[v][u]=mn;// it is optional !
}

void update(int v)
{
  markV[v]=true;

  for(int i=0;i<g[v].size();i++)
    if(!markV[g[v][i]]){
      int x=g[v][i];
      if(w[dis[x]][x]>w[v][x])
	dis[x]=v;}

}

void input()
{
  cout<<"MCST"<<endl<<endl<<"O(n^2)    maxN=1e3"<<endl<<endl;


  int mn=INF,u1,u2;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int k1,k2,val;
      cin>>k1>>k2>>val;
      g[k1].push_back(k2);
      g[k2].push_back(k1);
      w[k1][k2]=w[k2][k1]=val;

      //first edge
      if(val<mn){
	mn=val;
	u1=k1;u2=k2;}

    }

  //adding the first edge
  MST[u1].push_back(u2);
  MST[u2].push_back(u1);
  mstW[u1][u2]=mstW[u2][u1]=mn;
  update(u1);
  update(u2);
}

void meghdar_dehi()
{
  for(int i=1;i<maxN;i++){
    dis[i]=maxN-2;
    for(int j=1;j<maxN;j++){
      w[i][j]=mstW[i][j]=INF;}
    w[i][i]=mstW[i][i]=0;
  }
}

void show()
{
  cout<<endl<<endl<<"type 'sum' for the sum of MCST edges' w, or 'MST' to see the MCST"<<endl<<endl;


  string s;
  cin>>s;
  if(s=="sum"){
    long long int sum=0;
    for(int i=1;i<=n;i++)
      for(int j=0;j<MST[i].size();j++)
	sum+=w[i][MST[i][j]];

    cout<<sum/2;
  }
  else if(s=="MST"){
    for(int i=1;i<=n;i++)
      for(int j=0;j<MST[i].size();j++)
	cout<<i<<" "<<MST[i][j]<<" "<<w[i][MST[i][j]]<<endl;
  }
  return ;
}

int main()
{
  meghdar_dehi();
  input();


  int k=n;
  while(k>=3)
    {
      k--;
      find_min();
      update(v);
    }

  show();
  return 0;
}
