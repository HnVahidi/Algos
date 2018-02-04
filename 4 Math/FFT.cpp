#include<iostream>
#include<cmath>

using namespace std;
const int maxN=1e5+100;
int Q[maxN],P[maxN];
int m,n,newN;


int leastT2(int k)
{
  int t=1;
  while(k)
    {
      k/=2;
      t*=2;
    }
  return t;
}

void input()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>P[i];
  for(int i=0;i<m;i++)
    cin>>Q[i];
  //kochektarin tavan2 bozorgtar az max(n,m)
  newN=leastT2(max(n,m));
}

int* zarb(int p[],int q[],int size)
{
  int* ans=new int[2*size+10];
  fill(ans,ans+size+10,0);
  
  if(size==1){
    ans[0]=p[0]*q[0];
    return ans;}
  else if(size==2)
    {
      ans[0]=p[0]*q[0];
      ans[1]=p[0]*q[1]+p[1]*q[0];
      ans[2]=p[1]*q[1];
      return ans;
    }
  int s1=size/2;
  int s2;
  if(size%2==0)
    s2=size/2;
  else
    s2=size/2+1;
  
  int* a;
   a=zarb(p,q,s1);
   int* d;
  d=zarb(p+s1,q+s1,s2);
  
  int* tempP=new int[size/2+10];
  for(int i=0;i<s2;i++)//
    tempP[i]=p[i];
  for(int i=s2;i<size;i++)
    tempP[i-s2]+=p[i];
  
  int* tempQ=new int[size/2+10];
  for(int i=0;i<s2;i++)//
    tempQ[i]=q[i];
  for(int i=s2;i<size;i++)
    tempQ[i-s2]+=q[i];
  
  
  int* e;
  e=zarb(tempP,tempQ,s2);
  
  
  for(int i=0;i<size;i++)
    ans[i]=a[i];
  for(int i=0;i<size;i++)
    ans[i+s2]+=e[i]-a[i]-d[i];
  for(int i=0;i<size;i++)
    ans[i+size]+=d[i];

  //free stack
  delete [] a;
  delete [] d;
  delete [] e;
  delete [] tempP;
  delete [] tempQ;
  return ans;
}
void show(int a[],int size)
{
  for(int i=0;i<=size;i++)
    cout<<a[i]<<" ";
}
void BigTest()
{
  n=m=(600000);
  for(int i=1;i<=n;i++)
    P[i]=Q[i]=1;
  newN=leastT2(max(n,m));
  show(zarb(P,Q,newN),1000);
  }
int main()
{
   input();
    BigTest();
   show(zarb(P,Q,newN), m+n-2);
  
  return 0;
}
