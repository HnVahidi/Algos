#include<iostream>

using namespace std;
const int maxN=1e3;

int n,m;
bool T[maxN][maxN];


void input()
{

  cout<<"Transitive_Closure"<<endl<<endl<<"O(n^2)   maxN=1e3"<<endl<<endl;

  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int k1 , k2;
      cin>>k1>>k2;
      T[k1][k2]=false;
    }

}

void shortest_paths()
{
  for(int k=1;k<=n;k++)
    for(int x=1;x<=n;x++)
      if(!T[x][k])
      for(int y=1;y<+n;y++)
	if(!T[k][y])
	  T[x][y]=false;

}

void meghdar_dehi()
{
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      T[i][j]=true;
    T[i][i]=false;
  }

}

void show()
{
  int delta=-1000,degree,v;
  for(int i=1;i<=n;i++){
    degree=0;
    for(int j=1;j<=n;j++)
      if(!T[i][j])
	degree++;
    if(delta<degree){
      delta=degree;
      v=i;}
  }
    cout<<"DELTA is "<<v<<" degree is "<<delta;
}
int main()
{
  meghdar_dehi();
  input();
  shortest_paths();
  show();


  return 0;
}
