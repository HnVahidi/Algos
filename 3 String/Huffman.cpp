#include<iostream>
#include<string>
#include<set>
#include<vector>

using namespace std;
const int maxN=1e5+100;
set<pair<double,int> > myst;
int leftchild[maxN],middlechild[maxN],rightchild[maxN];
double f[maxN];
int n,root,nodes;

void input()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>f[i];
}
double dfs(int v=root,string code="",int d=1)
{
  if(v==0)
    return 0;
  if(v<=n && v==root){
    cout<<v<<" 0"<<endl;
    return d*f[v];
  }
  if(v<=n)
    cout<<v<<" "<<code<<endl;
  return d*f[v]*(v<=n)+
    dfs(leftchild[v],code+"0",d+1)+
    dfs(rightchild[v],code+"1",d+1)+
    dfs(middlechild[v],code+"2",d+1);
  
}
void HuffmanCode()
{
  input();
  //initialization
  for(int i=1;i<=n;i++)
    myst.insert(make_pair(f[i],i));
  nodes=n;

  
  while(myst.size()>0)
    {
      pair<double,int>p,q;
      p=*myst.begin();
      myst.erase(p);
      if(myst.size()==0)
	{
	  root=p.second;
	  break;
	}
      q=*myst.begin();
      myst.erase(q);
      myst.insert(make_pair(q.first+p.first,++nodes));
      leftchild[nodes]=q.second;
      rightchild[nodes]=p.second;
    }
  cout<<"Binary Huffman Code:"<<endl;
  double E=dfs();
  cout<<"Expected Length= "<<E<<endl;
}

void TernaryHuffmanCode()
{
  //input();
  //initialization
  for(int i=1;i<=n;i++)
    myst.insert(make_pair(f[i],i));
  nodes=n;

  
  while(myst.size()>0)
    {
      pair<double,int>p,q,r;
      p=*myst.begin();
      myst.erase(p);
      if(myst.size()==0)
	{
	  root=p.second;
	  break;
	}
      q=*myst.begin();
      myst.erase(q);
      if(myst.size()==0)
	  r=make_pair(0,0);
      else
	{
	  r=*myst.begin();
	  myst.erase(r);
	}
      myst.insert(make_pair(q.first+p.first+r.first,++nodes));
      rightchild[nodes]=r.second;
      middlechild[nodes]=q.second;
      leftchild[nodes]=p.second;
    }
  cout<<endl<<"Ternary Huffman Code:"<<endl;
  
  double E=dfs();
  cout<<"Expected Length= "<<E<<endl;
}
int main()
{
  
  HuffmanCode();
  
  TernaryHuffmanCode();
  
  return 0;
}
