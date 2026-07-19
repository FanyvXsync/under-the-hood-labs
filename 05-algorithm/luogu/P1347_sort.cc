// 图结构 拓扑排序
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 30;

int in[N], tmp[N];
vector<int> edges[N];

int cnt;
char s[N];
bool flag;

int n , m;

bool topsort()
{
    cnt = 0;
    flag = true;

    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        tmp[i] = in[i];
        if(!tmp[i]) q.push(i); 
    }

    
    while (q.size())
    {
        if(q.size() > 1) flag = false;

        int a = q.front(); q.pop();

        s[cnt++] = a + 'A';
        for(auto b : edges[a])
        {
            tmp[b]--;
            if(!tmp[b]) q.push(b);
        }
    }

    for(int i = 0; i < n; i++) 
    {
        if(tmp[i]) return false;
    }

    return true;
    
}

int main()
{
     cin >> n >> m;


    int ret;
    for(int i = 1; i <= m; i++)
    {
        char a ,b , c; cin >> a >> b >> c;
        int x = a - 'A', y = c - 'A';

        in[y]++;
        edges[x].push_back(y);

        if(topsort() == false)
        {
            printf("Inconsistency found after %d relations.", i);
            return 0;
        }
        
        if(flag)
        {
            ret = i;
            break;
        }

    }

    if(flag)
    {
        printf("Sorted sequence determined after %d relations: ", ret);
        for(int i = 0; i < n; i++) cout << s[i];
        cout << '.' << endl;
    }
    else
    {
        cout << "Sorted sequence cannot be determined."  << endl;
    }

    

    return 0;
}