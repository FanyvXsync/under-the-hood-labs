#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int p1,p2,p3;
string ori,ret;


bool isdig(char ch)
{

    return '0'< ch && ch <'9';
}


bool islow(char ch)
{
    return 'a' < ch && ch < 'z';
}

void add(char left ,char right)
{
    string t;
    for(char i = left+1; i < right ;i++)
    {
        char tmp = i;
        if(p1==2&&islow(tmp)) tmp-=32;
        else if(p1==3)tmp = '*';

        while(p2--) t+=tmp;

        if(p3 == 2)  reverse(t.begin(),t.end());

    }

    ret += t;

}



int main ()
{
    cin >> p1 >> p2 >> p3 >> ori;
    for(int i=0; i < ori.size(); i++ )
    {
        char ch = ori[i];
        if(ch=='-' || i == 0 || i == ori.size()-1) ret+=ch;
        else
        {
            char left = ori[i-1],right = ori[i+1];

            if((isdig(left) && isdig(right)) || (islow(left)&&islow(right)) && left < right)
            {
                add(left,right);
            }
            else ret+=ch;
        }
        
    }
    
    cout << ret << endl;

}
