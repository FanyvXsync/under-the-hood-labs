#include <iostream>
using namespace std;

// 换枚举对象，枚举月份和日期，然后枚举年份
// 注意这里直接枚举全部的日期对应的年份，然后判断在不在begin和end之间就行
// 这样更方便

int day[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
// 不想写很多的日期，就用day表，0位置不用就行

int main ()
{
    int cnt = 0;
    int begin,end;
    cin >> begin >> end;
    int ret = 0;


    // 因为这里是一位一位加上去的，又 k* 10000 这一步，所有的 0 就配好了

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