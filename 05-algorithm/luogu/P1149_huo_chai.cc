#include <iostream>
using namespace std;

int a[] = {6,2,5,5,4,5,6,3,7,6};
int ret, path;
int n;

void dfs()
{
    if(path >= n)
    {
        if(path == n) ret++;
        return ;
    }

    

}




int main()
{
    cin >> n;

    dfs();

    return 0;
}