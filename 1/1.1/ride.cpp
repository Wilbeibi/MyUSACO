
/*
  ID:wilbeib1
  PROG:ride
  LANG:C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int func(char *s)
{
    int ans = 1;
    while(*s)
    {
        ans *= *s - ('A' -1);
        ans %= 47;
        s++;
    }
    return ans;
}

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    char c[7],g[7];
    cin>>c>>g;
    if(func(c)==func(g))
        cout<<"GO"<<endl;
    else
        cout<<"STAY"<<endl;

    return 0;
    
}

/*
  Mon Jan 14 21:26:00 2013
Executing...
   Test 1: TEST OK [0.000 secs, 3232 KB]
   Test 2: TEST OK [0.000 secs, 3232 KB]
   Test 3: TEST OK [0.000 secs, 3232 KB]
   Test 4: TEST OK [0.000 secs, 3232 KB]
   Test 5: TEST OK [0.000 secs, 3232 KB]
   Test 6: TEST OK [0.000 secs, 3232 KB]
   Test 7: TEST OK [0.000 secs, 3232 KB]
   Test 8: TEST OK [0.000 secs, 3232 KB]
   Test 9: TEST OK [0.000 secs, 3232 KB]
   Test 10: TEST OK [0.000 secs, 3232 KB]
 */
