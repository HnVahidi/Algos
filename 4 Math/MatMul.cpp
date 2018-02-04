#include<iostream>

using namespace std;
const int maxN=5;

int mod,n;
struct Matrix
{

public:  int m[maxN][maxN];
};
Matrix I;

Matrix  zarb(Matrix a,Matrix b,int mod)
{
  Matrix ans;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      ans.m[i][j]=0;
      for(int z=1;z<=n;z++){
	ans.m[i][j]+=a.m[i][z]*b.m[z][j];
	ans.m[i][j]%=mod;}
    }
    return ans;
    
}
Matrix exp(Matrix base,int p , int mod)
{
  Matrix ans=I;
  while(p)
    {
      if(p&1)
	ans=zarb(ans,base,mod);
      base=zarb(base,base,mod);
      p>>=1;//taghsim bar 2
      
      
    }
  return ans;
}
int main()
{
  
  Matrix mat;
  int p;
  cin>>n>>p>>mod;
  //initialization
  for(int i=1;i<=n;i++)
    I.m[i][i]=1;
  
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>mat.m[i][j];

  Matrix ans=exp(mat,p,mod);
  
  for(int i=1;i<=n;i++){
    cout<<endl;
    for(int j=1;j<=n;j++)
      cout<<ans.m[i][j]<<" ";
  }
  
  return 0;
}
