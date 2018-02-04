#include<iostream>

using namespace std;
const int maxN=1e4*5+100;

int BIS[maxN],a[maxN];
int mx;

int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];

  //Meghdar_dehi
  BIS[1]=a[1];
  mx=1;
  //
  for(int i=2;i<=n;i++){
    int x=a[i];
    if(BIS[mx]<=x){
      mx++;
      BIS[mx]=x;}
    else{
    for(int k=mx;k>=1;k--){
      if(BIS[k]<=x && BIS[k+1]>x)
	BIS[k+1]=x;
      else if(k==1 && x<BIS[k])
	BIS[k]=x;}
    }}
    cout<<mx;

  return 0;
}
