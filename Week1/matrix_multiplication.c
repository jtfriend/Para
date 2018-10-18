#include <stdio.h>
int main()
{
    // printf() displays the string inside quotation
    printf("Hello, World!");
    printf("\n");
    int matrixA[3][4] = {
        {1, 2, 3, 4} ,
        {4, 5, 6, 8} ,
        {4, 3, 6, 7} ,
    };

    int matrixB[4][3] = {
        {7, 8, 9} ,
        {9, 10, 11} ,
        {1, 12, 13} ,
        {5, 12, 13} ,
    };

    int matrixC[3][3] = {
        {0, 0, 0} ,
        {0, 0, 0} ,
        {0, 0, 0} ,
    };

   //calc size of matrix

    int min_size = 3;
    int max_size = 4;

    for(int i= 0; i < min_size; i++) {
        for(int j= 0; j < max_size; j++) {
            printf("%d, ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(int i= 0; i < max_size; i++) {
        for(int j= 0; j < min_size; j++) {
            printf("%d, ", matrixB[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int k= 0; k < min_size; k++) {
        for(int i= 0; i < min_size; i++) {
            for(int j= 0; j < max_size; j++) {
                matrixC[k][i] += (matrixA[i][j] * matrixB[j][k]);
                printf("%d * %d = %d, ...", matrixA[i][j] , matrixB[j][k], (matrixA[i][j] * matrixB[j][k]));
                printf("i=%d, j=%d, k%d, ::%d\n", i, j,k, matrixC[k][i]);
            }
            printf("\n");
        }
    }

    for(int i= 0; i < min_size; i++) {
        for(int j= 0; j < min_size; j++) {
            printf("%d, ", matrixC[j][i]);
        }
        printf("\n");
    }

    return 0;
}
