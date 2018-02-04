#include<iostream>
#include<string>
#include<cmath>

using namespace std;
string A,B;
const int maxN=1e3+100;
int dp[maxN][maxN];
int n,m;
pair<int,int> how[maxN][maxN];
#define X first
#define Y second

void input()
{
  cin>>A>>B;
}
void show(int n,int m)
{
  if(n==0 && m==0)
    return ;
  show(n+how[n][m].X,m+how[n][m].Y);
  if(how[n][m].X==-1 && how[n][m].Y==-1)
    cout<<A[n-1];
}
void LCS()
{
  input();
  n=A.size();
  m=B.size();
  //paye
  for(int i=1;i<=max(n,m);i++){
    how[i][0]=make_pair(-1,0);
    how[0][i]=make_pair(0,-1);
  }
  
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(A[i-1]==B[j-1]){
	dp[i][j]=dp[i-1][j-1]+1;
	how[i][j]=make_pair(-1,-1);
      }
      else if(dp[i-1][j]>dp[i][j-1]){
	how[i][j]=make_pair(-1,0);
	dp[i][j]=dp[i-1][j];}
      else
	{
	  how[i][j]=make_pair(0,-1);
	  dp[i][j]=dp[i][j-1];}
  show(n,m);

}
int main()
{
  LCS();
  return 0;
}
