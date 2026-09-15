#pragma onece
#include <vector>
#include <ctime>

typedef void(*task_t)();

//////////////////////////////

void TaskPrintHello()
{
    std::cout << " hello " << std::endl;
}

void TaskPrintWorld()
{
    std::cout << " world " << std::endl;
}

void TaskPrintLover()
{
    std::cout << " c3V5dg== " << std::endl;
}


/////////////////////////////


class TaskManager
{
public:
    TaskManager()
    {
        srand(time(nullptr));
    }

    void Rigister(task_t t)
    {
        _tasks.push_back(t);
    }

    int Code()
    {
        return rand() % _tasks.size() + 1;
    }

    void Execute(int code)
    {
        if(code >= 0 && code < _tasks.size())
        {
            _tasks[code]();
        }
    }

    ~TaskManager() {}

private:
    std::vector<task_t> _tasks;
};