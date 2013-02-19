
/*
  ID:wilbeib1
  PROG:palsquare
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const char code[] ="0123456789ABCDEFGHIJ";

int Check(int x,int base)
{
    char buff[20];
    char *p = buff, *q = buff;
    for(; *q++ = code[x%base], x/= base; )
        ;
    for(; p < --q; ++p)
        if(*p != *q)
            return 0;

    return 1;   
}

string Conv(int x,int base)
{
    string num;
    for(; num.push_back(code[x%base]), x/= base; )
        ;
    reverse(num.begin(),num.end());

    return num;
}

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int i,index;
    cin>>index;
    
    for(i=1;i<=300;i++)
        if(Check(i*i,index))
            cout<<Conv(i,index)<<" "<<Conv(i*i,index)<<endl;
        
    
    return 0;	  
}


/*
  Tue Jan 22 18:58:39 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3368 KB]
   Test 2: TEST OK [0.000 secs, 3368 KB]
   Test 3: TEST OK [0.000 secs, 3368 KB]
   Test 4: TEST OK [0.000 secs, 3368 KB]
   Test 5: TEST OK [0.000 secs, 3368 KB]
   Test 6: TEST OK [0.000 secs, 3368 KB]
   Test 7: TEST OK [0.000 secs, 3368 KB]
   Test 8: TEST OK [0.000 secs, 3368 KB]


 */
