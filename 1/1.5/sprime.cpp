
/*
  ID:wilbeib1
  PROG:sprime
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
  最高位数字必须是质数，所以是2,3,5,7. 往后每拓展一位，
  要成为一个质数，拓展选择的数字范围只能是1,3,7,9. 很容
  易想到用dfs
*/

int top[] ={2,3,5,7};
int cho[] ={1,3,7,9};
int num;

bool pri(int x)//朴素素数判定
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) 
            return false;
    return true;
}


void dfs(int cur, int N)
{
    if(cur == N)
    {    
        cout<<num<<endl;
        
        return;
    }
    
    for (int j = 0; j < 4; ++j)
    {
        if(pri(num*10 + cho[j]))
        { 
            num = num*10 + cho[j];
            dfs(cur+1,N);
            num /= 10;
        }
    }
    return;    // Failed, end this number
}
        
void doit(int N)
{
    if(N == 1)
        for (int i = 0; i < 4; ++i)
            cout<<top[i]<<endl;
    else
        for (int i = 0; i < 4; ++i)
        {
            num = top[i];
            dfs(1,N);    
        }
}


int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);

    int N;
    cin>>N;
    if(N == 1)
        for (int i = 0; i < 4; ++i)
            cout<<top[i]<<endl;
    else
        for (int i = 0; i < 4; ++i)
        {
            num = top[i];
            dfs(1,N);    
        }
    
    return 0;	  
}

/*
  Fri Mar 01 19:29:04 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3236 KB]
   Test 2: TEST OK [0.000 secs, 3236 KB]
   Test 3: TEST OK [0.000 secs, 3236 KB]
   Test 4: TEST OK [0.000 secs, 3236 KB]
   Test 5: TEST OK [0.000 secs, 3236 KB]
 */                                             
