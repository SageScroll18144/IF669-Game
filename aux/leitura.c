#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file = fopen("mat.txt", "r");
    int l[2];

    if(file == NULL) exit(1);

    fscanf(file, "%d %d", &l[0], &l[1]);

    printf("%d %d\n", l[0], l[1]);

    fclose(file);

    return 0;
}