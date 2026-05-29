#include <iostream>
using namespace std;

string str;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> str;
        int ret = 0;
        int minx = 50;
        for(int i = 0; i < str.size(); i++) minx = min(minx, str[i] - '0');

        minx == 0? ret += 9: ret += 8;
        
        for(int i = 0; i < str.size();i++)
        {
            ret += str[i] - '0';
        }

        cout << ret << endl;
    }

    return 0;
    
}