#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main(int argvc, char *argc[])
{
    struct dirent *d;
    DIR *de;
    de = opendir("/proc");

    while ((d = readdir(de)) != NULL)
    {
        // cout << "s->s_name " << d->d_name << " s-> " << s << endl;
        // string di = to_string(pid);
        // string path = "/proc/" + di;

        int pid = atoi(d->d_name);

        if (pid > 0)
        {
            // cout << d->d_name << endl;

            char path[1000];
            strcpy(path, "/proc/");
            strcat(path, d->d_name);
            strcat(path, "/stat");
            // cout << path << endl;

            // string path = "/proc/" + string(d->d_name) + "/stat";

            char c1[20], c2[20];
            FILE *fptr;
            fptr = fopen(path, "r");

            fscanf(fptr, "%s %s", c1, c2);
            cout << c1 << " -> " << c2 << endl;
        }
    }

    return 0;
}