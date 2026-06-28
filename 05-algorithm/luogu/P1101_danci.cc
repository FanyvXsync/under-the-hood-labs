#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
const int M = 1e5 + 10;
unordered_map<string, int> cnt;
unordered_set<string> mp;
unordered_set<string> tmp;

string s[M];
int n,m;
int kind;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string st; cin >> st;
        mp.insert(st);
    }

    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> s[i];
        if(mp.count(s[i])) tmp.insert(s[i]);
    }

    cout << tmp.size() << endl;

    if(tmp.size() == 0) 
    {
        cout << 0 << endl;
        return 0;
    }

    int ret = M;
    for(int l = 1, r = 1; r <= m; r++)
    {
        if(!tmp.count(s[r])) continue;

        cnt[s[r]]++;
        if(cnt[s[r]] == 1) kind++;

        while(kind == tmp.size())
        {
            ret = min(ret, r - l + 1);
            cnt[s[l]]--;
            if(cnt[s[l]] == 0) kind--;
            l++;
        }
    }

    cout << ret << endl;
    return 0;
}
