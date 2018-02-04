//Hn.Vahidi@Gmail.com

#include<iostream>
#include<queue>
#include<vector>


using  namespace std;
const int maxN=1e5;

vector<int> list, g[maxN+10];
queue <int> q;
int INdeg[maxN+10],label[maxN+10];
int n, m;

void input()
{
  cout<<" O( E+V)"<<endl<<"maxN=1e5   maxM=1e6"<<endl<<" INPUT VERTICES AND EDGES AND EDGES' DESCRIPTION"<<endl;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int k1,k2;
      cin>>k1>>k2;
      g[k1].push_back(k2);
    }

}

void INdeg_find()
{
  for(int i=1;i<=n;i++)
    for(int j=0;j<g[i].size();j++)
      INdeg[g[i][j]]++;

  //sefr haro mindaze to queue
  for(int i=1;i<=n;i++)
    if(INdeg[i]==0)
      q.push(i);

}

void show_list()
{
  for(int i=0;i<list.size();i++)
    cout<<list[i]<<" ";
}
int main()
{
  input();
  INdeg_find();

  int num=0;
  while(!q.empty())
    {
      num++;
      int v=q.front();
      label[v]=num;
      for(int i=0;i<g[v].size();i++){
	INdeg[g[v][i]]--;
	if(INdeg[g[v][i]]==0)
	  q.push(g[v][i]);
      }
      list.push_back(v);
      q.pop();
      }

  show_list();

  return 0;
}
