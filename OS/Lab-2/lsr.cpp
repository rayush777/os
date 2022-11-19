#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

void lsRec(char *dir)
{
    struct dirent *sd;
    DIR *sde;
    sde = opendir(dir);
    char path[1000];

    while ((sd = readdir(sde)) != NULL)
    {
        if (sd->d_type == DT_DIR)
        {
            path[0] = '\0';
            if (strcmp(sd->d_name, ".") == 0 || strcmp(sd->d_name, "..") == 0)
                continue;
            strcat(path, dir);
            strcat(path, "/");
            strcat(path, sd->d_name);
            lsRec(path);
        }
        else
            cout << dir << "/" << sd->d_name << endl;
    }
    closedir(sde);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        lsRec((char *)".");
    else
        lsRec(argv[1]);

    return 0;
}
