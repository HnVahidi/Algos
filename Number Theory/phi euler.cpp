#include<iostream>
#include<ctime>
using namespace std;
const int maxN=1e6+100;
const int limit=1e6;

bool mark[maxN];
int phi[maxN];

void gharbal()
{
  for(int i=2;i<=limit;i++)
    if(!mark[i])
      {
	int d=i;
	phi[d]=d-1;
	while(d+i<=limit)
	  {
	    d+=i;
	    mark[d]=true;
	    ph[d]/=i;
	    phi[d]*=i-1;
	    
	  }
      }
}
int main()
{
  for(int i=1;i<=limit;i++)
    phi[i]=i;
  
    gharbal();

    for(int i=1;i<=20;i++)
      cout<<i<<" "<<phi[i]<<endl;
    cout<<clock()<<"ms";
  return 0;
}
