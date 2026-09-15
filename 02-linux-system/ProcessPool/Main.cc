#include "process_pool.hpp"

int main()
{
    ProcessPool pp(gdefaultnum);
    pp.Create();

    while(true)
    {
        int task_code = 1;

        // 1.选择一个信道
        pp.PushTask();

    }

    //pp.wait();

    sleep(1000);
    return 0;

}