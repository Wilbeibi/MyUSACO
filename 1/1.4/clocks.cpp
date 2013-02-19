
/*
  ID:wilbeib1
  PROG:clocks
  LANG:C++
*/
/*
  Reference:
  http://www.cnblogs.com/jiongjiong-mengmeng/archive/2012/10/18/2730248.html
 */
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <ctime>
using namespace std;

/* make a new type called clo, which means 9 shorts */ 
typedef short clo[9];

typedef struct 
{
    clo c;
    string tr;
}C;

queue<C> q;    //state queue
C init;        //input

short vis[4][4][4][4][4][4][4][4][4];

void bfs();
void visit(const C v);
bool IsVisit(const C v);
void move(C &n, int k);
bool IsAnswer(const C ans);

const clo mov[9] ={
    {1,1,0,1,1,0,0,0,0},
    {1,1,1,0,0,0,0,0,0},
    {0,1,1,0,1,1,0,0,0},
    {1,0,0,1,0,0,1,0,0},
    {0,1,0,1,1,1,0,1,0},
    {0,0,1,0,0,1,0,0,1},
    {0,0,0,1,1,0,1,1,0},
    {0,0,0,0,0,0,1,1,1},
    {0,0,0,0,1,1,0,1,1} 
};

int main()
{
    // clock_t st,ed;
    // double tm;
    // st = clock();
    
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    short temp;
    for (int i = 0; i < 9; ++i)
    {
        cin>>temp;
        init.c[i] = (temp/3)%4;
    }
    
    bfs();


    // ed = clock();
    // tm = (double)(ed-st)/CLOCKS_PER_SEC;
    // cout<<"time is:"<<tm<<endl;
    
    return 0;	  
}


void bfs()
{
    // visit origin = true, q.push(origin)
    visit(init);
    q.push(init);
    
    while(!q.empty())
    {
        C t = q.front();
        q.pop();
        //if (is answer), then print
        if(IsAnswer(t))
        {
            int len = t.tr.size();
            for (int i = 0; i < len-1; ++i)
                printf("%c ",t.tr[i]);
            printf("%c\n",t.tr[len-1]);    
            
            return;
        }
        
        
        else
            for (int i = 0; i < 9; ++i)
            {
                C next = t;
                 move(next,i); 
                // if next not visit, visit
                 if(!IsVisit(next))
                 {
                     visit(next);
                     q.push(next);
                 }
                     
            }
        
    }//end big while
}

void move(C &n, int k)
{
     // for(int i = 0; i < 9; ++i)
     //     n.c[i] = (n.c[i] + mov[k][i]) &3;// %4 for 0~4
     //  The comment way is more beautiful in writing, but slower
     // Especially when move() costs the most of time
    switch(k)
    {
    case 0:
        n.c[0] = (n.c[0] + 1 ) &3;
		n.c[1] = (n.c[1] + 1 ) &3;
		n.c[3] = (n.c[3] + 1 ) &3;
		n.c[4] = (n.c[4] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 1:
        n.c[0] = (n.c[0] + 1 ) &3;
		n.c[1] = (n.c[1] + 1 ) &3;
		n.c[2] = (n.c[2] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 2:
        n.c[1] = (n.c[1] + 1 ) &3;
        n.c[2] = (n.c[2] + 1 ) &3;
        n.c[4] = (n.c[4] + 1 ) &3;
        n.c[5] = (n.c[5] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 3:
        n.c[0] = (n.c[0] + 1 ) &3;
		n.c[3] = (n.c[3] + 1 ) &3;
        n.c[6] = (n.c[6] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 4:
        n.c[1] = (n.c[1] + 1 ) &3;
		n.c[3] = (n.c[3] + 1 ) &3;
		n.c[4] = (n.c[4] + 1 ) &3;
        n.c[5] = (n.c[5] + 1 ) &3;
		n.c[7] = (n.c[7] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 5:
        n.c[2] = (n.c[2] + 1 ) &3;
        n.c[5] = (n.c[5] + 1 ) &3;
        n.c[8] = (n.c[8] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 6:
        n.c[3] = (n.c[3] + 1 ) &3;
		n.c[4] = (n.c[4] + 1 ) &3;
        n.c[6] = (n.c[6] + 1 ) &3;
        n.c[7] = (n.c[7] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 7:
        n.c[6] = (n.c[6] + 1 ) &3;
        n.c[7] = (n.c[7] + 1 ) &3;
        n.c[8] = (n.c[8] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    case 8:
        n.c[4] = (n.c[4] + 1 ) &3;
        n.c[5] = (n.c[5] + 1 ) &3;
        n.c[7] = (n.c[7] + 1 ) &3;
        n.c[8] = (n.c[8] + 1 ) &3;
        n.tr += (k+1+'0');
        break;
    }
    
    
    
    //n.tr += (k+1+'0');  //CONVERT INT TO CHAR
    //n.tr.push_back(' ');

}

bool IsAnswer(const C ans)
{
    for (int i = 0; i < 9; ++i)
    {
        if(ans.c[i]!=0)
            return false;
    }
    return true;
}

void visit(const C v)
{
    vis[v.c[0]][v.c[1]][v.c[2]][v.c[3]][v.c[4]][v.c[5]][v.c[6]][v.c[7]][v.c[8]] = true;
}

 bool IsVisit(const C v)
{
    if(vis[v.c[0]][v.c[1]][v.c[2]][v.c[3]][v.c[4]][v.c[5]][v.c[6]][v.c[7]][v.c[8]] == true)
        return true;
    else
        return false;
}


/*
  Tue Feb  5 01:34:24 2013
  Executing...
   Test 1: TEST OK [0.011 secs, 3888 KB]
   Test 2: TEST OK [0.000 secs, 3888 KB]
   Test 3: TEST OK [0.108 secs, 4944 KB]
   Test 4: TEST OK [0.173 secs, 3888 KB]
   Test 5: TEST OK [0.205 secs, 5604 KB]
   Test 6: TEST OK [0.551 secs, 3888 KB]
   Test 7: TEST OK [0.605 secs, 3888 KB]
   Test 8: TEST OK [0.583 secs, 3888 KB]
   Test 9: TEST OK [0.605 secs, 3888 KB]
 */
