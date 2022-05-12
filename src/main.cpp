#include "FileSystem.h"
#include "User.h"
#include "Shell.h"

#include <iostream>

using namespace std;

FileSystem g_filesystem;
User g_user;

int main()
{
    try
    {
        Shell shell;
        shell.Run();
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    return 0;
}