#include<iostream>
#include<algorithm>

using namespace std;
struct node{int l,r,x,add,flag;};

const int maxN=1e3;

node seg[maxN];
int n;
int a[maxN];

void make_st(int now,int left,int right)
{
  seg[now].l=left;
  seg[now].r=right;
  seg[now].add=0;
  
  if(left==right){
    seg[now].x=a[right];
    return;
  }
  int mid=(left+right)/2;
  make_st(2*now,left,mid);
  make_st(2*now+1,mid+1,right);
  seg[now].x=seg[2*now].x+seg[2*now+1].x;
    
}
int query(int now, int i , int j)
{
  //cout<<now<<" "<<i<<" "<<j<<" "<<seg[now].x<<endl;
  if(seg[now].r==seg[now].l){
    seg[now].x+=seg[now].add;
    seg[now].add=0;
  }
  if(i==seg[now].l && j==seg[now].r)
    return seg[now].x+seg[now].add * (seg[now].r-seg[now].l+1);
  if(seg[now].add){
  seg[2*now].add+=seg[now].add;
  seg[2*now+1].add+=seg[now].add;
  seg[now].x+=seg[now].add* (seg[now].r-seg[now].l+1);
  seg[now].add=0;
  }
  if(i>=seg[2*now+1].l)
    return query(2*now+1,i,j);
  else if(j<=seg[2*now].r)
    return query(2*now,i,j);
  else
    return query(2*now,i,seg[2*now].r) + query(2*now+1,seg[2*now+1].l,j);
}

void show()
{
  cout<<"******"<<endl;
  for(int i=1;i<=2*n;i++)
    cout<<i<<" "<<seg[i].l<<" "<<seg[i].r<<" "<<seg[i].x<<" "<<seg[i].add<<endl;
  cout<<"--------"<<endl;
}
void add(int now , int i , int j , int key)
{
  //show();
  if(seg[now].l==seg[now].r)
    {
      seg[now].x+=key;
      return;
    }
  if(seg[now].l==i && seg[now].r==j){
    seg[now].add+=key;
    return ;
  }
  seg[now].x+=key*(j-i+1);
  if(j<=seg[2*now].r)
    add(2*now,i,j,key);
  else if(i>=seg[2*now+1].l)
    add(2*now+1,i,j,key);
  else
    {
      add(2*now,i,seg[2*now].r,key);
      add(2*now+1,seg[2*now+1].l,j,key);
    }
  //seg[now].x=min(seg[2*now].x,seg[2*now+1].x);
  
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
      if(s=="a")
	{
	  int posx,posy , key;
	  cin>>posx>>posy>>key;
	  add(1,posx,posy,key);
	  //show();
	}
      else if(s=="q")
	{
	  int posx,posy;
	  cin>>posx>>posy;
	  cout<<query(1,posx,posy);
	}
    }
  
  
  return 0;
}
