
/*
  ID:wilbeib1
  PROG:milk2
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
pair<int,int> t[5000];

 int main()
 {
     freopen("milk2.in","r",stdin);
     freopen("milk2.out","w",stdout);
     int N,i;
     cin>>N;
     for (i = 0; i < N; ++i)
         cin>>t[i].first>>t[i].second;
     sort(t,t+N);
     // for (i = 0; i < N; ++i)
     //     cout<<t[i].first<<"" <<t[i].second<<endl;
     int begin = t[0].first, end = t[0].second;
     int dt = end-begin, nt = 0;
     for(i = 1;i<N;++i)
     {
         if(t[i].first<=end)
             end = MAX(end,t[i].second);
         else
         {
             dt = MAX(end-begin,dt);
             nt = MAX(t[i].first-end,nt);
             begin = t[i].first;
             end = t[i].second;
         }
     }
     cout<<dt<<" "<<nt<<endl;
     return 0;	  
 }


/*
  Wed Jan 16 17:40:33 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3272 KB]
   Test 2: TEST OK [0.000 secs, 3272 KB]
   Test 3: TEST OK [0.000 secs, 3272 KB]
   Test 4: TEST OK [0.000 secs, 3272 KB]
   Test 5: TEST OK [0.000 secs, 3272 KB]
   Test 6: TEST OK [0.000 secs, 3272 KB]
   Test 7: TEST OK [0.011 secs, 3272 KB]
   Test 8: TEST OK [0.032 secs, 3272 KB]
 */
