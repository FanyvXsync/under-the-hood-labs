#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef pair<string,int> PSI;

int N,P;
map<string,int> mp;
PSI A;
int count;
string word;

int main ()
{
    cin >> N >> P;
    int n = N;

    while(N--)
    {
        cin >> A;
        mp.insert(A);
    }

    while(cin >> word)
    {
        if(mp.count(word))
        {
            count+=mp[word];
        }
    
    }

    cout << count%P << endl;

    return 0;
}