
/*
  ID:wilbeib1
  PROG:beads
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int len;
    cin>>len;
    string s;
    cin>>s;
    s = s+s;
    int max = 0,cur=0,pre=0,mid=0;
    size_t i;
    char col = 0;
    for(i = 0; i<len*2 ;i++)
    {
        if(s[i]=='w')
		{
			cur++;
			mid++;
		}
        else if(col==s[i])
        {
            cur++;
			mid=0;
        }
        else
        {
            max=(cur+pre)>max?(cur+pre):max;
            pre=cur-mid;
            cur=1+mid;
			mid=0;
            col=s[i];
        }
    }
	if(pre+cur>max)    max=pre+cur;
    max=(max>len)?len:max;
    cout<<max<<endl;
    return 0;
}

/*
  Tue Jan 15 23:35:56 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 3364 KB]
   Test 2: TEST OK [0.000 secs, 3364 KB]
   Test 3: TEST OK [0.000 secs, 3364 KB]
   Test 4: TEST OK [0.000 secs, 3364 KB]
   Test 5: TEST OK [0.000 secs, 3364 KB]
   Test 6: TEST OK [0.000 secs, 3364 KB]
   Test 7: TEST OK [0.000 secs, 3364 KB]
   Test 8: TEST OK [0.000 secs, 3364 KB]
   Test 9: TEST OK [0.000 secs, 3364 KB]
 */
