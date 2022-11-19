#include <bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

using namespace std;

void printPWD()
{
    char arr[50];
    printf("R-Ayush777@~%s $ ", getcwd(arr, sizeof(arr)));
}

int main()
{
    while (1)
    {
        printPWD();
        char ca[1000];
        // int cl = read(0, ca, sizeof(ca));
        // cin >> command;
        scanf("%99[^\n]", &ca);
        getchar();

        char command[1000] = "/bin/";
        pid_t c = fork();

        if (c == 0)
        {
            strcat(command, ca);
            char *args[100];
            char *token = strtok(command, " ");

            int idx = 0;

            while (token != NULL)
            {
                args[idx] = token;
                token = strtok(NULL, " ");
                idx++;
            }
            args[idx] = NULL;
            execv(args[0], args);
        }
        if (c > 0)
        {
            wait(NULL);
        }
    }

    return 0;
}
