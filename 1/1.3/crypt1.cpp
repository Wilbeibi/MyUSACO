
/*
  ID:wilbeib1
  PROG:crypt1
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

//ns for number set
int ns;


/*Use bit to replace set*/
inline bool Check(int t)
{
    for(int c = t; c; c /=10)
        if((1<<(c%10) | ns) != ns)
            return false;
    return true;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int N,temp,ans = 0;
    cin>>N;
    for (int i = 0; i < N; ++i)
    {
        cin>>temp;
        ns |= (1<<temp);
    } 
    
    for (int h = 100; h < 1000; ++h)
        for (int w = 10; w < 100 && h*w<10000 ; ++w)
        {
            if(h*(w/10)>999 || h*(w%10)>999)
                continue;
            if( Check(h) && Check(w) && Check(h*w) && Check(h*(w/10)) && Check(h*(w%10)) )
                ans++;
            
        }

    cout<<ans<<endl;
    
    
    return 0;	  
}

/*
  Mon Jan 28 22:30:00 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3232 KB]
   Test 2: TEST OK [0.000 secs, 3232 KB]
   Test 3: TEST OK [0.000 secs, 3232 KB]
   Test 4: TEST OK [0.000 secs, 3232 KB]
   Test 5: TEST OK [0.000 secs, 3232 KB]
   Test 6: TEST OK [0.000 secs, 3232 KB]
   Test 7: TEST OK [0.000 secs, 3232 KB]
 */
