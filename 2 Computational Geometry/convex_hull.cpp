#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
#define x first
#define y second

const int maxN=100;

vector <pair<int,int> > upper,lower;
pair<int,int> p[maxN];
int n;
// O(nlogn) if we had to sort
void input()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>p[i].first>>p[i].second;
  
}
int determinan(pair<int,int> p,pair<int,int> q,pair<int,int> r)
{
  /// 1 px py
  /// 1 qx qy
  /// 1 rx ry
  return (q.x*r.y-q.y*r.x) - p.x*(r.y-q.y) + p.y*(r.x-q.x);
}
int main()
{
  input();
  sort(p+1,p+1+n);
  //upper convex hull
  upper.push_back(p[1]);
  upper.push_back(p[2]);
  for(int i=3;i<=n;i++){
    while(determinan(upper[upper.size()-2],upper[upper.size()-1],p[i])>=0)
      {
	upper.pop_back();
	if(upper.size()==1)
	  break;
      }
    upper.push_back(p[i]);
  }

  ///
    lower.push_back(p[n]);
  lower.push_back(p[n-1]);
  for(int i=n-3;i>=1;i--){
    while(determinan(lower[lower.size()-2],lower[lower.size()-1],p[i])>=0)
      {
	lower.pop_back();
	if(lower.size()==1)
	  break;
      }
    lower.push_back(p[i]);
  }
  for(int i=0;i<upper.size();i++)
    cout<<"("<<upper[i].x<<","<<upper[i].y<<") -> ";
  for(int i=1;i<(int)lower.size()-1;i++)
    cout<<"("<<lower[i].x<<","<<lower[i].y<<") -> ";
  
  return 0;
}
