
/*
  ID:wilbeib1
  PROG:calfflac
  LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int odd[200000],even[200000];

int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    string say,pro;
    //input problem, noting
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        say.push_back(c);
        
    }
    // Initialize
    int pos = 0, ans = 0, len_say = say.size();
    for (int i = 0; i < len_say; ++i)
    {
        if(isalpha(say[i]))
            pro.push_back(tolower(say[i]));
    }
        
    // Odd plalindrome check
    int len_pro = pro.size();
    odd[0] = odd[1] = 1;
    for (int i = 2; i < len_pro; ++i)
    {
        if(pro[i] == pro[i-odd[i-1]-1])
            odd[i] = odd[i-1] + 2;
        else
            odd[i] = 1;
        
        if(odd[i] > ans)
        {
            ans = odd[i];
            pos = i - odd[i] + 1;
        }
    }

    // Even plalindrome check
    even[0] = 0;
    for (int i = 1; i < len_pro; ++i)
    {
        if(pro[i] == pro[i-even[i-1]-1])
            even[i] = even[i-1] + 2;
        else
            even[i] = 0;

        if(even[i] > ans)
        {
            ans = even[i];
            pos = i - even[i] + 1;
        }
    }

    // Print answer
    string :: iterator it = say.begin();
    for (int i = 0; *it; ++it)
    {
        if(isalpha(*it) && i++ == pos)
            break;
    }
    cout<<ans<<endl;
    for (int i = 0; i < ans && *it; ++it)
    {
        cout<<*it;
        if(isalpha(*it))
            i++;
    }
    cout<<endl;
    
    return 0;    
}


/*
  Sun Jan 27 19:55:37 2013
  Executing...
   Test 1: TEST OK [0.000 secs, 4928 KB]
   Test 2: TEST OK [0.000 secs, 4928 KB]
   Test 3: TEST OK [0.000 secs, 4928 KB]
   Test 4: TEST OK [0.000 secs, 4928 KB]
   Test 5: TEST OK [0.000 secs, 4928 KB]
   Test 6: TEST OK [0.000 secs, 4928 KB]
   Test 7: TEST OK [0.000 secs, 4928 KB]
   Test 8: TEST OK [0.000 secs, 4928 KB]
 */
