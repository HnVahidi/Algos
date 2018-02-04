#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>


#define P push
#define PB push_back
#define F(i,a,b) for (ll i=a; i<=b; i++)
#define FF(i,a,b) for (ll i=b; i>=a; i--)
using namespace std;
#define ll long long 
const int maxN=1e5+100;

int trie[maxN][150],cnt=1;
int word[maxN];

bool add(string s, int tedad) // tedad =0
{
  int v=0;
  for(int i=0;i<s.size();i++)
    if(trie[v][s[i]]+1)
      v=trie[v][s[i]];
    else if(tedad==0)
      return false;
    else
      v=trie[v][s[i]]=cnt++;
  word[v]+=tedad;
  return word[v];
}
void init()
{
  for(int i=0;i<maxN;i++)
    fill(trie[i],trie[i]+149,-1);
}
int main()
{
  ios::sync_with_stdio(false);
  init();
  while(1)
    {
      int a;
      string s;
      cin>>a>>s;
      cout<<add(s,a)<<endl;
} 
  
  return 0;
}
