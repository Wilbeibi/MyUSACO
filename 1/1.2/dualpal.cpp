
/*
  ID:wilbeib1
  PROG:dualpal
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const char code[] ="0123456789";

bool Check(int x)
{
    int  ans = 0;
    int xt;
    for (int base = 2; base <= 10; ++base)
    {
        string num;
        xt = x;
        
        for(; num.push_back(code[xt%base]), xt/= base; )
            ;
    
        
        string nump(num);
        reverse(num.begin(),num.end());
        if(num==nump)
        {
            ans++;
         
        }
        

        if(ans>=2)
            return true;
    }
    return false;
    
}


int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int N,S;
    cin>>N>>S;
    for (int i = 1; N ; ++i)
    {
        if(Check(S+i))
        {
            cout<<S+i<<endl;
            N--;
        }
    }
    
    return 0;	  
}

/*
  Tue Jan 22 21:43:47 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3368 KB]
   Test 2: TEST OK [0.000 secs, 3368 KB]
   Test 3: TEST OK [0.054 secs, 3368 KB]
   Test 4: TEST OK [0.000 secs, 3368 KB]
   Test 5: TEST OK [0.000 secs, 3368 KB]
   Test 6: TEST OK [0.032 secs, 3368 KB]
   Test 7: TEST OK [0.000 secs, 3368 KB]
 */
