#include <iostream>

using namespace std;

const int N = 1e5;
const int M = 1e5;

int e[N],ne[N],mp[N];
int id,h;

int find(int k)
{
    int j = h+1;
    while ((e[ne[j]] != k))
    {
        j = ne[j];
    }

    return mp[e[j]];
    
}

void _insert_back(int k,int i)
{
    ++id;
    e[id] = i;
    mp[i] = id;

    ne[id] = ne[mp[k]];
    ne[mp[k]] = id;
    
}

void _insert_front(int k,int i)
{
    ++id;
    e[id] = i;
    mp[i] = id;

    ne[id] = mp[k];
    int front = find(k);

    ne[front] = id;


}


int main ()
{
    
    e[id] = 1;
    mp[1] = id;
    ++id;

    int n;
    cin >> n;
    n--;
    int i = 2;
    while(n--)
    {
        int k,p;
        cin >> k >> p;
        if(p==1)
        {
            _insert_back(k,i);
        }
        else
        {
            _insert_front(k,i);
            
        }
        
        i++;

    }

    int x;
    while(cin>>x)
    {
        if(mp[x])
        {
            int front = find(x);
            ne[front] = ne[mp[x]];

            mp[x] = 0;
        }

    }

    for(int j = 1; j ;j = ne[j])
    {
        cout << e[j] << " ";
    }

 
    return 0;
}