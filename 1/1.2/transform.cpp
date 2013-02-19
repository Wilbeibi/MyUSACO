/*
  ID:wilbeib1
  PROG:transform
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
char ori[10][10];
char dst[10][10];

int N,i,j;


 void print(char a[][10])
 {
     for (i = 0; i < N; ++i)
     {
         for (j = 0; j < N; ++j)
             cout<<a[i][j];
         cout<<endl; 
     }
 }

void Rot90()
{    
    char a[10][10];
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            a[j][N-i-1] = ori[i][j];
    memcpy(ori,a,sizeof(ori));    
}

void Flip()
{
    char a[10][10];
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            a[i][N-j-1] = ori[i][j];
    memcpy(ori,a,sizeof(ori));    
}

bool Is()
{
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
        {
            if(ori[i][j]!=dst[i][j])
                return false;
        }

    return true;
}
/*
  �Ƚϣ��ж��Ƿ���#6���ǣ���¼6
  Rot90���ж��Ƿ���#1
  Rot90���ж��Ƿ���#2
  Rot90���ж��Ƿ���#3
  Rot90, Flip, �ж��Ƿ�#4
  ѭ��Rot90���Σ�ÿ�αȽϣ����У�#5
  ����#7
 */
int solve()
{
	
    int ans = 7;
    if(Is())
        ans = 6;
    Rot90();
    if(Is())
        return ans = 1;
    Rot90();
    if(Is())
        return ans = 2;
    Rot90();
    if(Is())
        return ans = 3;
    Rot90();
    Flip();
    if(Is())
        return ans = 4;
    for (int i = 0; i < 3; ++i)
    {
        Rot90();
        if(Is())
            return ans = 5;
    }
    return ans;
}

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin>>N;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            cin>>ori[i][j];
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            cin>>dst[i][j];
   
    cout<<solve()<<endl;
    return 0;	  
}

/*
  Sun Jan 20 13:54:58 2013
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



