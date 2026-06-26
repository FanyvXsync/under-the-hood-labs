#include <iostream>
using namespace std;

const int N = 1e5 + 10,M = 1e6+10;


int e[N],ne[N],mp[M];
int h,id;

int x,y;

void _insert(int x,int y)
{
    ++id;
    e[id] = y;
    mp[y] = id;

    ne[id] = ne[mp[x]];
    ne[mp[x]] = id;
    

}

int _find(int x)
{
    return e[ne[mp[x]]];

}

void _delete(int x)
{
    mp[e[ne[mp[x]]]] = 0;
    ne[mp[x]] = ne[ne[mp[x]]];
    
}

int main ()
{
    id++;
    e[id]=1;
    mp[1] = id;
    
    int q=0;
    cin >>q;
    int op = 0;
    int x,y;


    while(q--)
    {
        
        cin >> op;
        if(op==1)
        {
            cin >> x >> y;
            _insert(x,y);
        }
        else if(op==2)
        {
            cin >> x;
            int ret = _find(x);
            cout << ret << endl;
        }
        else
        {
            cin >> x;
            _delete(x);
        }
    
    
    }
    return 0;
}