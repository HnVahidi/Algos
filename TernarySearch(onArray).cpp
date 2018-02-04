#include<iostream>

using namespace std;
const int maxN=1e5+100;

int n;
int a[maxN];

void input()
{
  //input gets an array of integer size N
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  
}
int TernarySearch(int l, int r)
{
  //it finds th maximum , to find the minimum revert th if/else statement
  //or revret comparison
  while(true)
    {
      
      if(r-l<=2){
	//inja mishe index dad	
	return max(a[l],max(a[l+1],a[r]));
      }
      int leftThird=l+ (r-l)/3;
      int rightThird= r- (r-l)/3;
      if( a[leftThird]<a[rightThird])
	l=leftThird;
      else
	r=rightThird;
    }
}
int TernaryRec(int l ,int r)
{
      if(r-l<=2){
	//inja mishe index dad	
	return max(a[l],max(a[l+1],a[r]));
      }
      int leftThird=l+ (r-l)/3;
      int rightThird= r- (r-l)/3;
      if( a[leftThird]<a[rightThird])
	return TernaryRec(leftThird,r);
      else
	return TernaryRec(l,rightThird);

}
int main()
{
  input();
  cout<<TernarySearch(1,n)<<endl;;
  cout<<TernaryRec(1,n);
  return 0;
}
