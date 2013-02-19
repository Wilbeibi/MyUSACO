
/*
  ID:wilbeib1
  PROG:packrec
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
  dfs(): To get the all possible permutations of given four rectangles.
  Proc(): To check current order's minimum witdth and height in 6 modes(actually 5)
  Check(): Check if the current result can be in answer list.

 */
const int N = 4;
//min collabrate w and h
int mw=10000,mh=10000;
int vis[N+1], ord[N+1];


typedef struct rec
{
    int w;
    int h;
}rec;

vector<rec> r,ans;

void dfs(int dep);
void Proc();
void Check(int w, int h);
int max(int,int);
int max(int,int,int);
int max(int,int,int,int);
void swap(int &a,int &b);


int main()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);

    int w,h,temp;
    rec t;
    for (int i = 0; i < N; ++i)
    {
        cin>>w>>h;
        if(w>h)
            swap(w,h);
        t.w = w;
        t.h = h;
        r.push_back(t);
        
    }
    rec init;
    init.w = 9999;
    init.h = 9999;
    ans.push_back(init);
    
    dfs(0);
    cout<<mw*mh<<endl;
    vector<rec>::iterator ii;
    for(ii = ans.begin();ii!=ans.end();++ii)
        cout<<(*ii).w<<" "<<(*ii).h<<endl;

    return 0;	  
}



void dfs(int dep)
{
    if(dep>=N)
        return;

    else
    {
        for (int i = 0; i < N; ++i)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ord[dep] =i;
                if(dep == N-1)
                    Proc();
                else
                    dfs(dep+1);
                vis[i] = 0;
            }

        }//end for

    }//dep < N
}




void Proc()
{
    int w,h;
    
    int w1 = r[ord[0]].w, w2 = r[ord[1]].w, w3 = r[ord[2]].w, w4 = r[ord[3]].w;
    int h1 = r[ord[0]].h, h2 = r[ord[1]].h, h3 = r[ord[2]].h, h4 = r[ord[3]].h;

    //Plus loop to enumerate 0000~1111, 8 state

    
    //Let's rotating
    for(int i=0; i < 16; ++i)
    {
        if(i&1)
            swap(w1,h1);
        if(i&2)
            swap(w2,h2);
        if(i&4)
            swap(w3,h3);
        if(i&8)
            swap(w4,h4);
        
        /* case 1
           +----+
           +-----+   |    +--+
           |     +---+    |  |
           |     |   |    |  |
           |  1  | 2 |  3 | 4|
           |     |   |    |  |
           |     |   |    |  |
           +-----+---+    +--+
           +----+
        */
        w = w1 + w2 + w3 + w4;
        h = max(h1, h2, h3, h4);
        Check(w,h);

        /* case 2
       
           +---+
           |   |
           +--+   +----+
           |  |   |    |
           |1 | 2 | 3  |
           |  |   |    |
           |  |   |    |     
           +--+--+---+----+
           |       4      |
           +--------------+
        */
        w = max(w1 + w2 + w3, w4);
        h = max(h1, h2, h3) + h4;
        Check(w,h);


        /* case 3
           +----+---+
           |    |   |
           +--+    |   |
           |  |    |   |
           | 1| 2  | 4 |           
           |  |    |   |
           |  |    |   |
           ++-+----+   |
           |  3   |   |
           +------+   |
           +---+

        */ 
        w = max(w1 + w2, w3) + w4;
        h = max(h1 + h3, h2 + h3, h4);
        Check(w,h);


        /* case 4            
           +--+
           |  |+---+
           +---+ 3||   |
           |   |  ||   |
           |   +--+| 2 |
           | 1 |   |   |
           |   | 4 |   |
           |   |   |   |
           +---+   +---+
           +---+

        */
        w = w1 + w2 + max(w3, w4);
        h = max(h1, h3 + h4, h2);
        Check(w,h);

        //case 5 ( Little complicated)
        h = max(h1 + h3, h2 + h4);
        if(h3 >= h2+h4)
            w = max(w1, w2 + w3, w3 + w4);
        if(h3 > h4 && h3 < h2 + h4)
            w = max(w1 + w2, w2 + w3, w3 + w4);
        if(h4 > h3 && h4 < h1+h3)
            w = max(w1 + w2, w1 + w4, w3 + w4);
        if(h4 >= h1 + h3)
            w = max(w2, w1 + w4, w3 + w4);
        if(h3 == h4)
            w = max(w1 + w2, w3 + w4);
        Check(w,h);

        if(i&1)
            swap(w1,h1);
        if(i&2)
            swap(w2,h2);
        if(i&4)
            swap(w3,h3);
        if(i&8)
            swap(w4,h4);
        
    }//end rotating
        
}

bool cmp (rec a,rec b)
{
    return a.w < b.w;
}

bool uni (rec a,rec b)
{
    return (a.w == b.w && a.h ==b.h);
}
void Check(int w,int h)
{
    rec na;    // na for new answer
    if(w>h)
        swap(w,h);
    if(w*h <= mw*mh)
    {
        na.w = mw = w;
        na.h = mh = h;
        
        vector<rec>::iterator it;
        it = ans.begin();
        for(;it!=ans.end();)
        {
            if(mw*mh < ((*it).w * (*it).h) )
                ans.erase(it);
            else
                ++it;
            
            
        }
        ans.push_back(na);
   
     }
    
    sort( ans.begin(), ans.end(), cmp );
    ans.erase( unique( ans.begin(), ans.end(),uni ), ans.end() );
}


inline int max(int a,int b)
{
    return a>=b?a:b;
}

int max(int a,int b,int c)
{
    int m = max(a,b);
    return max(m,c);
}

int max(int a,int b,int c,int d)
{
    int m = max(a,b);
    int n = max(c,d);
    return max(m,n);
}

inline void swap(int &a,int &b)
{
    int t = a;
    a = b;
    b = t;
}


/*
  Sun Feb  3 00:37:51 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3372 KB]
   Test 2: TEST OK [0.000 secs, 3372 KB]
   Test 3: TEST OK [0.000 secs, 3372 KB]
   Test 4: TEST OK [0.000 secs, 3372 KB]
   Test 5: TEST OK [0.000 secs, 3372 KB]
   Test 6: TEST OK [0.000 secs, 3372 KB]
   Test 7: TEST OK [0.000 secs, 3372 KB]
   Test 8: TEST OK [0.000 secs, 3372 KB]
   Test 9: TEST OK [0.000 secs, 3372 KB]
   Test 10: TEST OK [0.000 secs, 3372 KB]
   Test 11: TEST OK [0.000 secs, 3372 KB]
   Test 12: TEST OK [0.000 secs, 3372 KB]
   Test 13: TEST OK [0.000 secs, 3372 KB]
   Test 14: TEST OK [0.000 secs, 3372 KB]
   Test 15: TEST OK [0.000 secs, 3372 KB]
   Test 16: TEST OK [0.000 secs, 3372 KB]
   Test 17: TEST OK [0.000 secs, 3372 KB]
   Test 18: TEST OK [0.000 secs, 3372 KB]
   Test 19: TEST OK [0.000 secs, 3372 KB]
   Test 20: TEST OK [0.000 secs, 3372 KB]
   Test 21: TEST OK [0.000 secs, 3372 KB]
 */
