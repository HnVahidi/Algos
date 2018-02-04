#include<iostream>
#include<string>

using namespace std;

const int maxN=1e5+100;

int trie[maxN][300],next=1;//initially -1
string s;
int n;

void add(string s)
{
  int v=0;
  for(int i=0;i<s.size();i++)
    if(trie[v][s[i]]==-1)
      v=trie[v][s[i]]=next++;
    else
      v=trie[v][s[i]];
}
void init()
{
  for(int i=0;i<maxN;i++)
    fill(trie[i],trie[i]+299,-1);
}
int main()
{
  init();
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>s;
    add(s);}
}
