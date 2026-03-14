#include <iostream>
using namespace std;

int day[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};


int main ()
{
    int cnt = 0;
    int begin,end;
    cin >> begin >> end;
    int ret = 0;

    for(int i=1;i<=12;i++)
    {
        for(int j = 1; j<=day[i];j++)
        {
            int k = j % 10 * 1000 + j / 10 * 100 + i % 10 * 10 + i / 10;
            int date = k * 10000 + i * 100 + j;

            if(date >= begin && date <= end) ret++;
        }
    }
    
    cout << ret;

    return 0;
}