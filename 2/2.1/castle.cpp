
/*
  ID:wilbeib1
  PROG:castle
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 50+1
using namespace std;

int x[]={0,-1,0,1},y[]={-1,0,1,0};  //Direction W,N,E,S
int castle[MAX][MAX];//每个cell四面墙的情况
int m[MAX][MAX];   //种子填充用的图，记录每个cell填充的颜色
int color,now;    //颜色;当前颜色cell的数量
int siz[MAX*MAX];  //颜色为color的房间的大小
char dir[] = {'W','N','E','S'};
int M,N,maxsize,mergemax;;

void floodfill(int i,int j)
{
    m[i][j] = color;   //填充颜色
    now++;    //该颜色房间数加1
    for (int k = 0; k < 4; ++k)
    {
        int ni = i+x[k], nj = j+y[k];
        if(ni<0 || nj<0 || ni>=N || nj>=M)    //检查越界
            continue;
        if((castle[i][j]&(1<<k))==0 && m[ni][nj]==0) //该方向没有墙且要探测的cell未访问
            floodfill(ni,nj);
    }
}


int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    cin>>M>>N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin>>castle[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if(m[i][j]==0)   //该cell没被访问过
            {
                now = 0;
                color++;
                floodfill(i,j);
                siz[color] = now;
                maxsize = max(maxsize,now);
            }
    // Until now, 连通房间数和最大房间的cell数已经得知
    cout<<color<<endl<<maxsize<<endl;

    int ans_x; int ans_y; int ans_dir;

    //找要推倒的墙
    for (int j = 0; j < M; ++j)    //从西开始
        for (int k = 0; k < 4; ++k)   // W N E S的顺序
            for (int i = N-1; i >= 0; --i)   //从南开始
                if((castle[i][j]&(1<<k))!=0 && m[i][j]!=m[i+x[k]][j+y[k]] )  //有墙壁且不同色
                {
                    if(i+x[k]<0 || j+y[k]<0 || i+x[k]>=N || j+y[k]>=M)   //越界检查很重要！！！
						continue;
                    int merge = siz[m[i][j]] + siz[ m[i+x[k]][j+y[k]] ];
                    if(merge > mergemax)
                    {
                        mergemax = merge;
                        ans_x = i+1; ans_y = j+1; ans_dir = k;
                    }
                } 
    cout<<mergemax<<endl;
    cout<<ans_x<<" "<<ans_y<<" "<<dir[ans_dir]<<endl;
    return 0;	  
}

/*
  Thu Mar 07 12:37:28 2013
  Executing...
  Test 1: TEST OK [0.000 secs, 3256 KB]
  Test 2: TEST OK [0.000 secs, 3256 KB]
  Test 3: TEST OK [0.000 secs, 3256 KB]
  Test 4: TEST OK [0.000 secs, 3256 KB]
  Test 5: TEST OK [0.000 secs, 3256 KB]
  Test 6: TEST OK [0.000 secs, 3256 KB]
  Test 7: TEST OK [0.000 secs, 3256 KB]
  Test 8: TEST OK [0.000 secs, 3256 KB]
 */
