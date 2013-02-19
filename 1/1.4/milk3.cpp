
/*
  ID:wilbeib1
  PROG:milk3
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>
using namespace std;

/*
  dfs(int st[3]) to dfs all answer
  pour(i,j,st[3]) to pour from bucket No.i to No.j at current state (st[3])
 */
bool vis[20+5][20+5][20+5];
bitset <25> ans;
int cap[3];

void dfs(int st[3]);
void pour(int i, int j, int cur[3]);

int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    
    for (int i = 0; i < 3; ++i)
         cin>>cap[i];
    
    int init[3];
    init[0] = init[1] = 0;
    init[2] = cap[2];
    dfs(init);

    int space_num = ans.count() - 1;
    for (int i = 0; i < 21; ++i)
    {
        if( ans.test(i) && space_num )
        {
            cout<<i<<" ";
            space_num--;
        }
        else if(ans.test(i))
            cout<<i<<endl;
    }
    
    return 0;	  
}

void dfs(int st[3])
{
    int cur[3];
    memcpy(cur,st,sizeof(cur));
    
    if( vis[cur[0]][cur[1]][cur[2]] )
        return;
    else
        vis[cur[0]][cur[1]][cur[2]] = true;
	if(cur[0]==0)
		ans.set(cur[2]);  //if not there, 0->1, if it is there, 1->1 is also ok.   

	for(int i=0; i < 3;++i)
		for(int j = 0; j< 3; ++j)
		{
			if(i!=j)
				pour(i,j,cur);
		}
    return;
}

void pour(int i, int j, int cur[3])
{
	int re[3];  //re(main)
	memcpy(re,cur,sizeof(re));
	if(re[i] <= cap[j] - re[j])
	{
		re[j] += re[i];
		re[i] = 0;
	}
	else
	{
		re[i] -= cap[j] -re[j];
		re[j] = cap[j];
	}
	dfs(re);
}
        
/*
  Thu Feb  7 00:06:23 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3248 KB]
   Test 2: TEST OK [0.000 secs, 3248 KB]
   Test 3: TEST OK [0.000 secs, 3248 KB]
   Test 4: TEST OK [0.000 secs, 3248 KB]
   Test 5: TEST OK [0.000 secs, 3248 KB]
   Test 6: TEST OK [0.000 secs, 3248 KB]
   Test 7: TEST OK [0.000 secs, 3248 KB]
   Test 8: TEST OK [0.000 secs, 3248 KB]
   Test 9: TEST OK [0.000 secs, 3248 KB]
   Test 10: TEST OK [0.000 secs, 3248 KB]
 */
