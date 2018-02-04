#include<iostream>
#include<algorithm>

using namespace std;
struct node{int l,r,x;};

const int maxN=1e3;

node seg[maxN];
int n;
int a[maxN];

void make_st(int now,int left,int right)
{
  seg[now].l=left;
  seg[now].r=right;
  if(left==right){
    seg[now].x=a[right];
    return;
  }
  int mid=(left+right)/2;
  make_st(2*now,left,mid);
  make_st(2*now+1,mid+1,right);
  seg[now].x=min(seg[2*now].x,seg[2*now+1].x);
    
}
int query(int now, int i , int j)
{
  if(i==seg[now].l && j==seg[now].r)
    return seg[now].x;
  else if(i>=seg[2*now+1].l)
    return query(2*now+1,i,j);
  else if(j<=seg[2*now].r)
    return query(2*now,i,j);
  else
    return min( query(2*now,i,seg[2*now].r) , query(2*now+1,seg[2*now+1].l,j));
}

void add(int now , int i , int key)
{
  if(seg[now].l==seg[now].r && seg[now].r==i){
    seg[now].x=key;
    return ;
  }
  if(i<=seg[2*now].r)
    add(2*now,i,key);
  else
   add(2*now+1,i,key);
  seg[now].x=min(seg[2*now].x,seg[2*now+1].x);
  
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  
  make_st(1,1,n);
  int m;
  cin>>m;
  for(int i=1;i<=m;i++)
    {
      string s;
      cin>>s;
      if(s=="add")
	{
	  int pos , key;
	  cin>>pos>>key;
	  add(1,pos,key);
	}
      else if(s=="query")
	{
	  int posx,posy;
	  cin>>posx>>posy;
	  cout<<query(1,posx,posy);
	}
    }
  
  
  return 0;
}
