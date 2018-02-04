#include<iostream>
#include<algorithm>

using namespace std;
const int maxN=1e5+100;

int n;
int a[maxN],b[maxN];
  
void merge(int l1,int r1,int l2,int r2,int a[])
{
  int i=l1;
  int j=l2;
  int cnt=1;
  while(i<=r1 && j<=r2)
    {
      if(a[i]<=a[j])
	{
	  b[cnt]=a[i];
	  i++;
	  cnt++;
	}
      else
	{
	  b[cnt++]=a[j++];
	}
    }
  for(i;i<=r1;i++)
    b[cnt++]=a[i];
  for(j;j<=r2;j++)
    b[cnt++]=a[j];
  
  //111
  //555
  j=1;
  for(int i=l1;i<=r2;i++)
    a[i]=b[j++];
}
void mergeSort(int l , int r, int a[])
{
  if(l==r)
    return ;
  if(l==r-1)
    {
      if(a[l]>a[r])
	swap(a[l],a[r]);
      return ;
    }
  int mid=(l+r)/2;
  mergeSort(l,mid,a);
  mergeSort(mid+1,r,a);
  merge(l,mid,mid+1,r,a);
}
void show()
{
  for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
}
void input()
{
    cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
}
int main()
{
  input();
  mergeSort(1,n,a);
  show();
  
  return 0;
}
