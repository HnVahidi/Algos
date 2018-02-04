#include<iostream>
#include<algorithm>

using namespace std;
const int maxN=1e6+10;
int n,size,g[maxN];

void insert(int ad)
{
  size++;
  g[size]=ad;
  int parent=size/2;
  int child=size;
  while(parent>=1)
    {
      if(g[child]>g[parent]){
	swap(g[child],g[parent]);
	child=parent;
	parent/=2;
      }
      else
	parent=0;
    }
}
void show()
{
  int tabaghe=1,sum=0;
  for(int i=1;i<=size;i++)
    {
      cout<<g[i];
      if(i==tabaghe+sum)
	{
	  sum+=tabaghe;
	  tabaghe*=2;
	  cout<<endl;
	}
    }
}
void remove()
{
  g[1]=g[size];
  size--;
  int child=2;
  int parent=1;
  while(g[parent]<g[child] || g[parent]<g[child+1]){
    if(g[child]<g[child+1])
      child++;
    swap(g[child],g[parent]);
    parent=child;
    child=parent*2;
  }
}
int main()
{
  cout<<"Enter N (number of commands) . Enter command type ( 1: insert , 2:remove) after 'insert' should be a value"<<endl;


  cin>>n;
  for(int i=1;i<=n;i++){
    int ad,command;
    cin>>command;
    if(command==1){
      cin>>ad;
      insert(ad);}
    else if(command==2)
      remove();
  }
  show();

  return 0;
}
