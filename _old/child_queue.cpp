#include <iostream>

using namespace std;

const int N = 1e6;

int e[N],ne[N];
int n = 0;

int main ()
{

    cin >> n;

    for(int i=0;i<=n;i++)
    {
        e[i] = i;
    }

    
    for(int i=1;i <= n;i++)
    {
        cin >> ne[i];
    }

    int frist = 0;
    cin >> frist ;

  for(int i = frist;i; i = ne[i])
  {
         cout << e[i] << " ";
  }



    return 0;
}