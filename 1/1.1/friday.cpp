
/*
  ID:wilbeib1
  PROG:friday
  LANG:C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool IsLeap(int year)
{
    return ((year%4==0 && year%100!=0) || (year%400)==0);
}

int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
enum days{sat,sun,mon,tue,wed,thu,fri};
int res[7];

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int N,i,j;
    cin>>N;
    int d = sat; // Init date 1900.1.13 is Sat
    res[sat] = 1;
    for(i=1900;i<=1900+N-1;i++)
    {
        if(IsLeap(i))  m[2] = 29;
        for(j=1;j<=12;j++)
        {
            d += m[j];
            d %= 7;
            if(i==1900+N-1 && j==12)    break;
            res[d]++;
        }
        m[2] = 28;
    }
    
    for(i=0;i<6;i++)
        cout<<res[i]<<" ";
    cout<<res[i]<<endl;
    
    return 0;
}

/*
Tue Jan 15 12:43:30 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3232 KB]
   Test 2: TEST OK [0.000 secs, 3232 KB]
   Test 3: TEST OK [0.000 secs, 3232 KB]
   Test 4: TEST OK [0.000 secs, 3232 KB]
   Test 5: TEST OK [0.000 secs, 3232 KB]
   Test 6: TEST OK [0.000 secs, 3232 KB]
   Test 7: TEST OK [0.000 secs, 3232 KB]
   Test 8: TEST OK [0.000 secs, 3232 KB]
 */
