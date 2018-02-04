#include<iostream>
#include<algorithm>

using namespace std;
const int maxN=1e5+100;
int a[maxN];
int n;
int cnt=0;

void input()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  
}

int choosePivot(int l ,int r , int b[])
{return b[l];}

int partition(int l ,int r, int b[])
{
  int pivot = choosePivot(l,r,b);
  int i=l;
  int j=r;
  int split;
  while(i<j)
    {
      while(b[i]<=pivot && i<=j){
	i++;
	cnt++;}
      while(b[j]>=pivot && j>=i)
	j--;
      if(i<j){
	cout<<"fuck";
	cnt++;
	swap(b[i],b[j]);
      }
      	i++;
	j--;
      
    }
  cnt=0;
  for(int i=l;i<=r;i++){
    if(a[i]>=pivot && split==0)
      split=i;
    if(a[i]==pivot)
      cnt++;
  }
  return split ;
}
void show()
{
  for(int i=1;i<=n;i++)
    cout<<a[i]<< " ";
      
}
void QuickSort( int l , int r ,int b[])
{
  cout<<l<<" "<<r<<endl;
  if(l>=r)
    return;
  show();
  int splitPoint=partition(l,r,b);
  cout<<"---"<<splitPoint<<endl;
  QuickSort(l,splitPoint,b);
  QuickSort(splitPoint+cnt+1,r,b);
  }

int main()
{
  input();
  QuickSort(1,n,a);
  //cout<<partition(1,n,a)<<endl;
  show();
  return 0;
}
