
/*
  ID:wilbeib1
  PROG:milk
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define P pair<int,int> 
using namespace std;

P f[5001];

bool inc(P a, P b)
{
    return a.first < b.first;
}

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int N,M;
    int i;
    cin>>N>>M;
    for (i = 0; i < M; ++i)
        cin>>f[i].first>>f[i].second;
    sort(f,f+M,inc);
    
    int ans = 0;
    
    for(i = 0; N; ++i)
    {
        
        if(N > f[i].second)
        {
            ans += f[i].first * f[i].second;
            N -= f[i].second;
        }

        else
        {
            ans += N * f[i].first;
            N = 0;
        }
    }
    
        
    
    cout<<ans<<endl;
    
    return 0;	  
}


/*
  Tue Jan 22 23:14:51 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3272 KB]
   Test 2: TEST OK [0.000 secs, 3272 KB]
   Test 3: TEST OK [0.000 secs, 3272 KB]
   Test 4: TEST OK [0.000 secs, 3272 KB]
   Test 5: TEST OK [0.011 secs, 3272 KB]
   Test 6: TEST OK [0.032 secs, 3272 KB]
   Test 7: TEST OK [0.011 secs, 3272 KB]
   Test 8: TEST OK [0.022 secs, 3272 KB]
*/
