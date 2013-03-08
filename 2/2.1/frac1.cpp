
/*
  ID:wilbeib1
  PROG:frac1
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int N;
struct frac
{
    int a,b;
};
//类似法莱数列 递归求两个分数中间的分数就是分子分母分别相加
void Russ(frac x,frac y)
{
    frac n;
    n.a = x.a + y.a;
    n.b = x.b + y.b;
    if (n.b > N)
        return;
    Russ(x,n);
    cout<<n.a<<"/"<<n.b<<endl;
    Russ(n,y);
}
int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    cin>>N;
    frac x{0,1};
    frac y{1,1};
    cout<<x.a<<"/"<<x.b<<endl;
    Russ(x,y);
    cout<<y.a<<"/"<<y.b<<endl;   
    
    return 0;	  
}

/*
  Thu Mar 07 20:04:06 2013
  Executing...
  Test 1: TEST OK [0.000 secs, 3232 KB]
  Test 2: TEST OK [0.000 secs, 3232 KB]
  Test 3: TEST OK [0.000 secs, 3232 KB]
  Test 4: TEST OK [0.000 secs, 3232 KB]
  Test 5: TEST OK [0.000 secs, 3232 KB]
  Test 6: TEST OK [0.000 secs, 3232 KB]
  Test 7: TEST OK [0.000 secs, 3232 KB]
  Test 8: TEST OK [0.011 secs, 3232 KB]
  Test 9: TEST OK [0.032 secs, 3232 KB]
  Test 10: TEST OK [0.065 secs, 3232 KB]
  Test 11: TEST OK [0.162 secs, 3232 KB]
 */
