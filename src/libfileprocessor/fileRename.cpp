#include "libfileprocessor/fileRename.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int fileRename(char* key, char* dir, int lay)
{
    DIR* d;
    struct dirent* directory;

    char path[100];
    strcpy(path, dir);
    char filepath[100];
    char filename[100];
    strcpy(filename, path);
    strcat(filename, key);
    char filefinal[100];

    int i = 1;
    int c = 0;
    int count = 1;
    int lt, j, l, h, ln, dot, typeln;

    switch (lay) {
    case 1:
        lt = 48;
        break;
    case 2:
        lt = 96;
        break;
    case 3:
        lt = 64;
        break;
    default:
    	return WRONGLAYOUT;
    }

    char *k, *type;
    k = new char[1];

    d = opendir(path);
    if (d) {
        while ((directory = readdir(d)) != NULL) {
        FE:
            if (c > 1) {
                ln = strlen(directory->d_name);
                for (l = ln - 1; l > -1; l--) {
                    if (directory->d_name[l] == '.') {
                        dot = l;
                        break;
                    } else
                        dot = 0;
                }

                j = i + lt;
                if ((j > 57 && lay == 1) || (j > 122 && lay == 2)
                    || (j > 90 && lay == 3)) {
                    count++;
                    i = 1;
                }
                j = i + lt;

                k[0] = j;
                strcpy(filepath, path);
                strcpy(filefinal, filename);
                strcat(filepath, directory->d_name);

                for (l = 0; l < count; l++) {
                    strcat(filefinal, k);
                }

                if (dot != 0) {
                    type = new char[ln - dot];
                    typeln = ln - dot;
                    for (h = 0; h < typeln; h++) {
                        type[h] = directory->d_name[dot];
                        dot++;
                    }
                    strcat(filefinal, type);
                    delete type;
                    dot = 0;
                }

                if (access(filefinal, F_OK) != 0) {
                    rename(filepath, filefinal);
                } else {
                    i++;
                    goto FE;
                }
                i++;
            }
            c++;
        }
        closedir(d);
    }
    return RENAMESUCCESS;
}
