#include<iostream>

using namespace std;
const int maxN=1e5;
int n, numberofSets;
int parent[maxN],size[maxN];

// findparent
// isSameP
//union
int findp(int v)
{
  return (parent[v]==v) ? v : (parent[v]=findp(parent[v]));
}
bool isSameParent(int v, int u)
{
  return (findp(v)==findp(u));
}
void union_them(int v, int u)
{
  
  if(!isSameParent(v,u)){
    numberofSets--;
    size[findp(u)]+=size[findp(v)];
    parent[findp(v)]=findp(u);
    }
}
int findsize(int v)
{
  return size[findp(v)];
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++){
    parent[i]=i;
    size[i]=1;}
  numberofSets=n;

  int dastoor,a,b;
  while(1)
    {
      cin>>dastoor;
      if(dastoor==1)
	{
	  cin>>a>>b;
	  cout<<isSameParent(a,b);}
      else if(dastoor==2)
	{
	  cin>>a>>b;
	  union_them(a,b);
	}
      else if(dastoor==3)
	{
	  cin>>a;
	  cout<<findp(a);
	}
      else if (dastoor==4){
	cin>>a;
	cout<<findsize(a);
      }
      cout<<endl;
    }
  return 0;
}
