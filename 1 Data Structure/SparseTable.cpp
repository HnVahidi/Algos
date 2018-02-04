#include<bits/stdc++.h>

using namespace std;
const int maxN=1e5+100;
const int MAXLOG=31;

int st[maxN][MAXLOG];
int a[maxN],n,m;

void input()
{
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
}
void sparse()//precompute
{
  
  //st[i][j] = min in range [i , i+2^j]
  for(int j=0;j<MAXLOG;j++)
    for(int i=0;i<n;i++) //0-base
      if(i+ (1<<j) -1<n){
	st[i][j]=(j?min(st[i][j-1],st[i+(1<<j-1)][j-1]) :a[i]);
	cout<<i<<" "<<j<<" "<<st[i][j]<<endl;}
	
}
int query(int L,int R)
{
  int x=0,rem=R-L+1;
  // x=log2(R-L+1);
  while(rem>1)x++,rem>>=1;
  cout<<x<<endl;
  return min( st[L][x],st[R-(1<<x)][x]);
}
int main()
{
  input(); // 0-base
  sparse();
  cin>>m;
  for(int i=1;i<=m;i++)
    {
      int L,R;
      cin>>L>>R;
      cout<<query(L,R)<<endl;
    }
  return 0;
}
