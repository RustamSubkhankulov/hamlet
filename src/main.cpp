#include "global_conf.h"
#include "hamlet/hamlet.h"

//===============================================

int main(int argc, char* argv[])
{
    #ifdef LOGS

        FILE* logs_file = open_log_file(Logfile_name);
        if (!logs_file)
            return -1;

    #endif 

    Hamlet hamlet = { 0 };

    int ret_val = hamlet_init(&hamlet, "text_files/example.txt");
    if (ret_val == -1)
        return -1;

    ret_val = hamlet_print_data(&hamlet);
    if (ret_val == -1)
        return -1;

    ret_val = hamlet_destruct(&hamlet);
    if (ret_val == -1)
        return -1;

    #ifdef LOGS
        close_log_file();
    #endif 

    return 0;
}