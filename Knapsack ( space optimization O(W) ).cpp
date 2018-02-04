#include<iostream>
#include<algorithm>


using namespace std;
const int maxK=2e6+100;

int dp[maxK],dpTemp[maxK];
int v[600],w[600];
int n,k;

void knapsack()
{
  for(int i=1;i<=n;i++){
    
    for(int j=w[i];j<=k;j++)
      dpTemp[j]=max(dp[j],dp[j-w[i]]+v[i]);

    for(int j=w[i];j<=k;j++)
      dp[j]=dpTemp[j];
  }
  
}
void input()
{
  cin>>k>>n;
  for(int i=1;i<=n;i++)
    cin>>v[i]>>w[i];
}
int main()
{
  ios::sync_with_stdio(false);
  input();
  knapsack();
  cout<<dp[k]<<endl;  
  return 0;
}
