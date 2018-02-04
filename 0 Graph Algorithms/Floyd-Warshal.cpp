//Hn.Vahidi@gmail.com
#include<iostream>

using namespace std;
const int maxN=400;
const long long int INF=400;


long long int dis[maxN][maxN];
int n,m;

void input()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int k1,k2,val;
      cin>>k1>>k2>>val;
    dis[k1][k2]=val;
  }
}
void meghdar_dehi()
{

  for(int i=1;i<maxN-1;i++){
    for(int j=1;j<maxN;j++)
      dis[i][j]=INF;
    dis[i][i]=0;
  }
}

void show()
{
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      if(dis[i][j]==INF)
	cout<<"A ";
      else
	cout<<dis[i][j]<<" ";
    cout<<endl;
  }

}


int main()
{
  meghdar_dehi();
  input();

  for(int m=1;m<=n;m++)
    for(int x=1;x<=n;x++)
      for(int y=1;y<=n;y++)
	if(dis[x][m]+dis[m][y]<dis[x][y])
	  dis[x][y]=dis[x][m]+dis[m][y];

  show();
  return 0;
}
