#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int N = 1e6+10;

vector<int> v;

int main ()
{
    int n;
    cin >> n;
    int ch[N] = {0};
    for(int i=2; i < n;i++) 
    {
        cin >> ch[i];
    } 
    cin >> ch[1];

    int j = 2;
    v.push_back(ch[1]);
    vector<int>::iterator it = v.begin();

    while(j < n+1)
    {
        if(ch[j] == 0)
        {
            v.insert(it+n-1,j);
        }
        v.insert(it+j+1,ch[j]);
    }

    




    return 0;
}