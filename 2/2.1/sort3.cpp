
/*
  ID:wilbeib1
  PROG:sort3
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAX 1000
//#define swap(a,b)  { int t = a;  a = b;  b = t;}
int num[3+1];   //记录数字i的个数在num[i]之中
int sn[4][4];
int seq[MAX];   //记录输入数据

/*
  交换可以分两种
  1次交换使得两个数都在自己应该在的位置
  2次交换使得三个数都在自己应该在的位置
  这里完整的操作序列定义成，操作序列最终使得参加操作的数都在自己该在的位置
  我们可以看出只会存在上述两种最简操作序列，且这两种方式互相不能代替，那么我们用这两种操作序列最终得到的就是最优解
  操作序列1比2好，因为其代价比2小，1中1次得到2个数，2中1次得到1.5个数，所以我们先用1，实在不行再用2
  先求出每段依次是多少个(段1表示该段全是1)，然后用sn[i][j]表示段i中j的个数
  那么先累计min(sn[i][j],sn[j][i])的数量，这个是通过操作序列1
  然后只可能有两种情况，段1中有2或者段1中有3，因为这些都是必须要用操作序列2替换的，所以再累计(sn[1][2]+sn[1][3])*2
*/

int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int N;
    cin>>N;
    // 1. 求每个数字出现多少次
    for (int i = 0; i < N; ++i)
    {
        cin>>seq[i];
        num[seq[i]]++;   
    }
    // 2. 求段i中j的个数(i可以与j相等) sn数组求值
    int pin = 0;   //每段的起始位置
    for (int i = 1; i <= 3; ++i)
    {
        pin += num[i-1]; //得到起始位置
        for (int j = 0; j < num[i]; ++j)
            sn[i][seq[pin+j]]++;
    }

    // 3. 累计二次交换和三次交换的次数
    int sum = 0;
    for (int i = 1; i < 4; ++i)
        for (int j = 1; j < 4; ++j)
        {
            if(i==j)    continue;
            int t = min(sn[i][j],sn[j][i]);   //二次交换
            sum += t;
            sn[i][j] -= t;
            sn[j][i] -= t;
        }
    sum += 2*(sn[1][2]+sn[1][3]);    //三次交换
    cout<<sum<<endl;
    
    return 0;	  
}

/*
  Fri Mar  8 09:51:32 2013
  Executing...
  Test 1: TEST OK [0.000 secs, 3236 KB]
  Test 2: TEST OK [0.000 secs, 3236 KB]
  Test 3: TEST OK [0.000 secs, 3236 KB]
  Test 4: TEST OK [0.000 secs, 3236 KB]
  Test 5: TEST OK [0.000 secs, 3236 KB]
  Test 6: TEST OK [0.000 secs, 3236 KB]
  Test 7: TEST OK [0.000 secs, 3236 KB]
  Test 8: TEST OK [0.000 secs, 3236 KB]
 */
