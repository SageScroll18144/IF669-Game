#include <stdio.h>
#include <stdlib.h>

void ler(char *file_name){
    FILE *file = fopen(file_name, "r");
    int l[2];

    if(file == NULL) {
        printf("*ERRO DE ABERTURA*\n");
        exit(1);
    }
    fscanf(file, "%d %d", &l[0], &l[1]);

    int mat[l[0]][l[1]];

    printf("%d %d\n", l[0], l[1]);

    for(int i=0;i<l[0];i++) for(int j=0;j<l[1];j++) fscanf(file, "%d", &mat[i][j]);
    // for(int i=0;i<l[0];i++) {
    //     for(int j=0;j<l[1];j++){
    //         printf("%d ", mat[i][j]);
    //     } 
    //     printf("\n");
    // }
    printf("dim(0, 0) -> %d\n", mat[0][0]);
    fclose(file);

}

int main(){

    ler("mat.txt");

    return 0;
}