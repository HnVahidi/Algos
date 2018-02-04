#include<iostream>

using namespace std;
const int maxN=1e5+100;
int n,last,a[maxN],BIS[maxN];

void input()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
}
int find(int l, int r, int key)
{
  int now=(r+l)/2;
  if(R-L<=1)
    {
      if(BIS[R]>key && BIS[R-1]<=key)
	return R;
      if(BIS[L]>key && BIS[L-1]<=key)
	return L;
      return L-1;
    }
  
  if(BIS[now]>key && BIS[now-1]<=key)
    return now;
  else if(BIS[now]<key)
    return find(now+1,r,key);
  else
    return find(l,now-1,key);
}
int main()
{
  input();
  last=1;// size Longest IS ke ta be hal peida kardim
  // |LIS|= last
  //BIS[i] = Best Increasing Subsequence ( smallest last value )
  BIS[1]=a[1];
  BIS[0]=0;// ya - INF
  for(int i=2;i<=n;i++)
    {
      
      if(a[i]>BIS[last]){// age a[i] jadid ro betonim be LIS feli ezafe konim
	last++;
	BIS[last]=a[i];}
      //baraye ezafe kardan a[i] be yek BIS bayad yek k peida konim ke
      //BIS[k-1]<a[i]<BIS[k] bashe
      BIS[find(1,last,a[i])]=a[i];// midonim BIS[1]<BIS[2]<...<BIS[last]
    }
  cout<<last<<endl;

  return 0;
}
