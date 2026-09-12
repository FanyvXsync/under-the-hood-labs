#include "comm.hpp"

#define PATH_NAME "fifo" // 可以不要了

int main()
{
    NamedFifo FIFO(".", "fifo"); //  创建管道文件，当前路径下
    
    //对命名管道进行操作
    //这也是我们之前提到的在创建出来以后，就都是文件操作了
    FileOper readerfile(".", "fifo");
    readerfile.OpenForRead();
    readerfile.Read();

    readerfile.Close(); // 记得关，好习惯
                        
    

    return 0;
}