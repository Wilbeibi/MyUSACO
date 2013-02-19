
/*
  ID:wilbeib1
  PROG:gift1
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    map<string,int> list;
    vector<string> order;
    int NP,i,j;
    cin>>NP;
    for(i=0;i<NP;i++)
    {
        string name;
        cin>>name;
        list.insert(std::map<string,int>::value_type(name,0));
        order.push_back(name);
    }
    
    for(i=0;i<NP;i++)
    {
        string giver,receiver;
        int money, num,share=0;
        cin>>giver>>money>>num;
        if(money&&num)
        {
            share = money/num;
            list[giver] -= share * num;
            for(j=0;j<num;j++)
            {
                cin>>receiver;
                list[receiver] += share;
            }
            
        }
    }
    //map<string,int>::iterator it = list.begin();
    vector<string>::iterator it = order.begin();
    
    while(it!=order.end())
    {
        cout<<*it<<" "<<list[*it]<<endl;
        it++;
    }
    return 0;
}
