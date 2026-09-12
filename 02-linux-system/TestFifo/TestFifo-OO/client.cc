#include "comm.hpp"


#define PATH "."
#define FILENAME "fifo"
#define PATH_NAME "fifo"
// server 服务端已经打开文件，接下来客户端只需要进行文件操作就可以了

int main()
{
    FileOper writerfile(PATH, FILENAME);

    writerfile.OpenForWrite();
    writerfile.Write();

    writerfile.Close();
    return 0;
}