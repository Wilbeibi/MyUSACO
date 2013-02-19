
/*
  ID:wilbeib1
  PROG:ariprog
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int N,M;
int l[21100];    //use vector to know it has 21046 elements
bitset<125005> b; //250*250*2 = 125000
P ans[100];   // hard to estimate
int cnt;  //ans counter



bool inc_b(P m, P n)
{
    return m.second < n.second;
}

bool Check(int la, int cd)
{
    for (int j = N-1; j >= 1 ; --j)
    {
        int k = la+j*cd;
        
        if( !b.test(k) )
            return false;
    }
    return true;
}

int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    cin>>N>>M;
    for(int p = 0; p<= M; ++p)
        for(int q = p; q <= M; ++q)
            b.set(p*p + q*q);

    int *pi = l,len = 0;
    for (int i = 0; i < 125000; ++i)
    {
        if(b.test(i))
        {
            *pi++ = i;
             len++;
        }
    }

   
    
    int cd;
    int Rmax = M*M*2/(N-1) +1;
    int Lim = M*M*2;
    
    for(int a = 0; a <= len-N+1  ; ++a)
        for(int b = a+1; l[b]-l[a] <= Rmax; ++b)
        {
            if(l[a]+(N-1)*(l[b]-l[a]) > Lim)
                break;

            if(Check(l[a],l[b]-l[a]))
            {
                ans[cnt].first  = l[a];
                ans[cnt].second = l[b]-l[a];
                cnt++;
            }
            
        }
    sort(ans,ans+cnt,inc_b);

    if(cnt==0)
        cout<<"NONE"<<endl;
    else
        for (int i = 0; i < cnt; ++i)
            cout<<ans[i].first<<" "<<ans[i].second<<endl;

    return 0;
	  
}

/*
  Wed Feb  6 00:01:18 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3332 KB]
   Test 2: TEST OK [0.000 secs, 3332 KB]
   Test 3: TEST OK [0.000 secs, 3332 KB]
   Test 4: TEST OK [0.000 secs, 3332 KB]
   Test 5: TEST OK [0.011 secs, 3332 KB]
   Test 6: TEST OK [0.043 secs, 3332 KB]
   Test 7: TEST OK [0.162 secs, 3332 KB]
   Test 8: TEST OK [0.313 secs, 3332 KB]
   Test 9: TEST OK [0.281 secs, 3332 KB]
 */
