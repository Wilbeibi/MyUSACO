
/*
  ID:wilbeib1
  PROG:numtri
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    int	 arr[1000+1][1000+1];
	int	  dp[1000+1][1000+1];
    memset(arr,0,sizeof(arr));
    memset(dp,0,sizeof(dp));
    int R;
    cin>>R;
    
    for (int i = 1; i <= R; ++i)
        for(int j = 1; j <= i; ++j)
        {        
            cin>>arr[i][j];
            dp[i][j] = arr[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
        }
    
    int ans = 0;
    for (int i = 1; i <= R; ++i)
        ans = max(ans,dp[R][i]);

    cout<<ans<<endl;

    return 0;	  
}

/*
  Thu Feb  7 12:27:35 2013
  Executing...
   Test 1: TEST OK [0.011 secs, 10940 KB]
   Test 2: TEST OK [0.011 secs, 10940 KB]
   Test 3: TEST OK [0.011 secs, 10936 KB]
   Test 4: TEST OK [0.000 secs, 10936 KB]
   Test 5: TEST OK [0.011 secs, 10940 KB]
   Test 6: TEST OK [0.022 secs, 10932 KB]
   Test 7: TEST OK [0.054 secs, 10940 KB]
   Test 8: TEST OK [0.011 secs, 10936 KB]
   Test 9: TEST OK [0.324 secs, 10932 KB]
 */
