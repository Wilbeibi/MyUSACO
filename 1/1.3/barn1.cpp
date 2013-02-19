
/*
  ID:wilbeib1
  PROG:barn1
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    /*Initialize*/
    int M,S,C;
    int temp;
    vector<int> bul;
    cin>>M>>S>>C;
    for (int i = 0; i < C; ++i)
    {
        cin>>temp;
        bul.push_back(temp);
    }
    sort(bul.begin(),bul.end());
    int ans = bul[C-1] - bul[0] + 1;


    /*Caculate bans*/
    vector<int> ban;
    for (int i = 1; i < C; ++i)
    {
        temp = bul[i] - bul[i-1] - 1;
        ban.push_back(temp);
    }
    sort(ban.begin(),ban.end(),greater<int>());

    /*Solve */
    if(M >= C)
        ans = C;
    else
        for (int i = 0; i < M - 1; ++i)
            ans -= ban[i];
        

    cout<<ans<<endl;
        
    
    return 0;	  
}

/*
  Wed Jan 23 17:08:03 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3368 KB]
   Test 2: TEST OK [0.000 secs, 3368 KB]
   Test 3: TEST OK [0.000 secs, 3368 KB]
   Test 4: TEST OK [0.000 secs, 3368 KB]
   Test 5: TEST OK [0.000 secs, 3368 KB]
   Test 6: TEST OK [0.000 secs, 3368 KB]
   Test 7: TEST OK [0.000 secs, 3368 KB]
   Test 8: TEST OK [0.000 secs, 3368 KB]
   Test 9: TEST OK [0.000 secs, 3368 KB]
   Test 10: TEST OK [0.000 secs, 3368 KB]
 */
