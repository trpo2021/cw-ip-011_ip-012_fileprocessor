#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileRename(char* key, char* dir, int lay)
{
    DIR* d;
    struct dirent* dir;

    FILE* fp;

            char path[100];
    strcpy(path, dir);
    char filepath[100];
    char filename[100];
    strcpy(filename, key);
    char filefinal[100];

    int i = 0;
    int c = 0;
    int count = 1;
    int lt;
    int l;
    char j;

    switch (lay) {
    case 1:
        lt = 48;
        break;
    case 2:
        lt = 97;
        break;
    case 3:
        lt = 65;
        break;
    }

    char* k;
    k = new char[1];

    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
            if (c > 1) {
            FE:
                j = i + lt;
                if ((j > 57 && lay == 1) || (j > 122 && lay == 2)
                    || (j > 90 && lay == 3)) {
                    count++;
                    i = 0;
                }
                
                k[0] = j;
                strcpy(filepath, path);
                strcpy(filefinal, filename);
                strcat(filepath, dir->d_name);
                
                for (l = 0; l < count; l++) {
                    strcat(filefinal, k);
                }

                fp = fopen(filefinal, "r");

                if (fp) {
                    rename(filepath, filefinal);
                    fclose(fp);
                } else {
                	i++;
                    fclose(fp);
                    goto FE;
                }
            }
            i++;
            c++;
        }
        closedir(d);
    }
    return 0;
}
