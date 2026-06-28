#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> v;
unordered_map<string,int> mp;

int main()
{
    string s;  cin >> s;
    string tmp;
    for(char m : s)
    {
        tmp.push_back(tolower(m));
    }

    tmp.clear();
    string x;
    while(cin >> x)
    {
        for(char m : x)
        {
            tmp.push_back(tolower(m));
        }
        mp[x]++;
        v.push_back(tmp);
    }

    int idx = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == s)
        {
            idx = i;
            break;
        }
    }

    cout << mp[s] << " " << idx << endl;



    return 0;
}