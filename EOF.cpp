#include<iostream>

using namespace std;

int main()
{
  //EOF
  char ch;
  while(1){
    if(scanf("%c",&ch)==EOF){
      
    cout<<"End of File"<<endl;
    break;}
    else if(ch=='\n')
      cout<<"new line"<<endl;
    
  }
  
  return 0;
}
