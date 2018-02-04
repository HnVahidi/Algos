#include<iostream>

using namespace std;
const int maxN=1e5+100;

int sum[maxN],a[maxN],aleft[maxN],aright[maxN];
int n,m;

#define left aleft
#define right aright

void add(int i,int j,int x,int now)
{

  sum[now]+=x;
  if(left[now]==right[now] && right[now]==pos)
    return ;
  else if(right[2*now]>= pos && left[2*now]<=pos)
    return add(pos,x,2*now);
  else if(right[2*now+1]>= pos && left[2*now+1]<=pos)
    return add(pos,x,2*now+1);
}
int query(int beg,int end,int now)
{
  if(beg==end)
    return sum[now];
  else if(beg>=left[2*now+1])
    return query(beg,end,2*now+1);
  else if(end<=right[2*now])
    return query(beg,end,2*now);
  else
    return query(beg,right[2*now],2*now)+query(left[2*now+1],end,2*now+1);
    
}
void create_tree(int beg, int end,int now)
{
  int mid=(beg+end)/2;
  left[now]=beg;
  right[now]=end;
  if(beg!=end){
    create_tree(beg,mid,2*now);
    create_tree(mid+1,end,2*now+1);
    sum[now]=sum[2*now]+sum[2*now+1];
    return ;
      }
  else
    sum[now]=a[beg];
}
  
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>a[i];

  create_tree(1,n,1);
  
  for(int i=1;i<=m;i++)
    {
      string order;
      int a,b;
      cin>>order>>a>>b;
      if(order=="add")
	add(a,b,1);
      else if(order=="query")
	cout<<query(a,b,1)<<endl;
    }
  return 0;
  
}
