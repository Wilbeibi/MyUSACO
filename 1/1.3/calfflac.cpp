
/*
  ID:wilbeib1
  PROG:calfflac
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ctype>
using namespace std;

int dp0[200000],dp1[200000];

int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    string say,temp;
    cin>>say;
    int pos=0,ans=0;
    for (int i = 0; i < say.size(); ++i)
    {
        if(isalpha(say[i]))
            temp.push_back(tolower(say[i]));
        
    }
    
    
    return 0;	  
}
