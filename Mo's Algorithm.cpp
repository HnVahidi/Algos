#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cstdio>


using namespace std;
const int maxN=2e5+100;
const int BLOCK=300;
int dif[maxN],a[(int)(3e4+100)],tek[(int)(1e6+100)];
int n,m,ans;

struct node
{int L,R,id,ans;} q[maxN];

void input()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",a+i);
  scanf("%d",&m);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&q[i].L,&q[i].R);
    q[i].id=i;}
}
inline void remove(int pos)
{
  tek[a[pos]]--;
  if(tek[a[pos]]==0)
    ans--;
}
inline void add(int pos)
{
  tek[a[pos]]++;
  if(tek[a[pos]]==1)
    ans++;
}
bool cmp(node p1, node p2)
{
  if(p1.L/BLOCK!=p2.L/BLOCK)
    return p1.L<p2.L;
  return p1.R<p2.R;
}

int main()
{
 
  input();
  sort(q+1,q+1+m,cmp);
  int curL=0,curR=0;
  for(int i=1;i<=m;i++)
    {
      while(curL<q[i].L)
	remove(curL++);
      while(curL>q[i].L)
	add(--curL);
      while(curR<q[i].R)
	add(++curR);
      while(curR>q[i].R)
	remove(curR--);
      
      dif[q[i].id]=ans;
    }

  for(int i=1;i<=m;i++)
    printf("%d\n",dif[i]);

  
  return 0;
}
