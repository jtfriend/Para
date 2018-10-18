#include <stdio.h>
int main()
{
    // printf() displays the string inside quotation
    printf("Hello, World!");
    printf("\n");
    printf("%d\n", rand() % 10);

    int matrixA[30][50];
    int matrixB[50][30];
    int matrixC[30][30];

    for(int i= 0; i < 30; i++) {
      for(int j= 0; j < 50; j++) {
        matrixA[i][j] = rand() % 10;
      }
    }

    for(int i= 0; i < 30; i++) {
      for(int j= 0; j < 50; j++) {
        matrixB[j][i] = rand() % 10;
      }
    }

    for(int i= 0; i < 30; i++) {
      for(int j= 0; j < 30; j++) {
        matrixC[i][j] = rand() % 10;
      }
    }

    int min_size = 30;
    int max_size = 50;

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
