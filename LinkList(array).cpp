#include<bits/stdc++.h>

using namespace std;
const int maxN=1e5+10;

int headPos=0,lastPos=0;
int key[maxN],next[maxN],prev[maxN],active[maxN];
int cnt=1,sz=0;

void add(int value,int pos=lastPos)
{
  sz++;
  active[cnt]=true;
  next[cnt]=next[pos];
  prev[next[pos]]=cnt;
  next[pos]=cnt;
  key[cnt]=value;
  prev[cnt]=pos;
}
void erase(int pos)
{
  sz--;
  active[pos]=false;
  next[prev[pos]]=next[pos];
  prev[next[pos]]=prev[pos];
}
void show()
{
  cout<<"size "<<sz<<endl;
  for(int i=0;i<=cnt;i++){
    if(active[i]==false)
      cout<<"in";
    cout<<"active "<<prev[i]<<" "<<key[i]<<" "<<next[i]<<endl;}
}
int main()
{


  return 0;
}
