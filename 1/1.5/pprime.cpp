
/*
  ID:wilbeib1
  PROG:pprime
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int a,b;
int d[100000],num; // d[] to store palindromic numbers

int c[10]; // enumerate the first half of the palindromic number

void add(int l)
{
    int sum = 0;
    for (int i = 0; i <= l; ++i)
        sum = sum*10 + c[i];
    for (int i = 0; i < l; ++i)
        sum = sum*10 +c[l-1-i];
    d[num++] = sum;
}

void dfs(int cur, int l) // enumerate each digit of the first half of the palindromic number
{
    if(cur == l)
    {
        add(l-1);
        return;
    }
    for (int digit = 0; digit<=9; ++digit)
    {
        if(cur==0 && digit ==0)
            continue;   // 0 cannot be a head
        c[cur] = digit;
        dfs(cur+1,l);    
    }
}

bool pri(int x)
{
    for (int i = 2; i*i <= x; ++i)
        if(x%i==0)
            return false;
    return true;
    
}

int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    cin>>a>>b;
    for (int l = 1; l<=9; ++l)
    {
        if(l==2)
            d[num++] = 11;  //偶数位数的回文数除了11，都不是质数
        else if(l%2==0)     //偶数肯定不是奇数
            continue;
        else
            dfs(0,l/2+1);   //奇数中找回文数
    }
    
    for (int i = 0; i < num; ++i)  //在回文数d[]中，判定质数
    {
        if(d[i] > b)
            break;
        if(pri(d[i]) && d[i]>=a)
            cout<<d[i]<<endl;
    }
    
    return 0;	  
}

/*
  Fri Mar 01 16:30:30 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3624 KB]
   Test 2: TEST OK [0.000 secs, 3624 KB]
   Test 3: TEST OK [0.000 secs, 3624 KB]
   Test 4: TEST OK [0.000 secs, 3624 KB]
   Test 5: TEST OK [0.022 secs, 3624 KB]
   Test 6: TEST OK [0.022 secs, 3624 KB]
   Test 7: TEST OK [0.032 secs, 3624 KB]
   Test 8: TEST OK [0.032 secs, 3624 KB]
   Test 9: TEST OK [0.032 secs, 3624 KB]
 */
