
/*
  ID:wilbeib1
  PROG:checker
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
#define MAX 13
using namespace std;
int N;
int ans, res[3][MAX];  //ans: number of solutions, res: first 3 solutions
int temp[MAX];  // store ÿ��ö�ٳ�������

bool v[MAX+1],l[MAX*2+1],r[MAX*2+1]; // Hash �У���Խ��ߣ��ҶԽ���

void dfs(int col)
{
    if(col==N)
    {
        if(ans < 3)
            memcpy(res[ans],temp,sizeof(temp));
        ans++;
        return;
    }
    for (int row = 1; row <= N; ++row)    //ö���ڴ�����һ��
    {
        if(v[row] || r[col+1+row] || l[col+1-row+N])   //�жϿɷ����
            continue;
        v[row] = r[col+1+row] = l[col+1-row+N] = 1;
        temp[col] = row;
        dfs(col+1);
        v[row] = r[col+1+row] = l[col+1-row+N] = 0;   //�ع�
    }
}

void print()    // Print first 3 solutions
{
    int m = (ans<3)?ans:3;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < N-1; ++j)
            cout<<res[i][j]<<" ";
        cout<<res[i][N-1]<<endl;    
    }
}

int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    cin>>N;
    dfs(0);
    print();
    cout<<ans<<endl;
    return 0;	  
}

/*
  Sun Mar 03 17:37:27 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3232 KB]
   Test 2: TEST OK [0.000 secs, 3232 KB]
   Test 3: TEST OK [0.000 secs, 3232 KB]
   Test 4: TEST OK [0.000 secs, 3232 KB]
   Test 5: TEST OK [0.000 secs, 3232 KB]
   Test 6: TEST OK [0.022 secs, 3232 KB]
   Test 7: TEST OK [0.130 secs, 3232 KB]
   Test 8: TEST OK [0.713 secs, 3232 KB]
 */
