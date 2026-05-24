#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s; cin >> s;

    int flag = 0;
    int x = 0;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            x = x % 11;
            if(x==10 && s[n-1] == 'X' || x == s[n-1] - '0') cout << "Right" << endl;
            else 
            {
                flag = 1;
                s[n - 1] = x + '0';
            }
        }
        else if(isdigit(s[i]))
        {
            if(i > 1) x = x + (s[i] - '0') * (i - 1);
            else if(i > 5) x = x + (s[i] - '0') * (i - 2);
        }
    }

    if(flag) cout << s << endl;
    return 0;

}