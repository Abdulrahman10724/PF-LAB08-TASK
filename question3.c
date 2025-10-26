#include <stdio.h>

int main() {
    int mat1[3][3], mat2[3][3], result[3][3];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter number of rows for first matrix (max 3): ");
    scanf("%d", &r1);
    printf("Enter number of columns for first matrix (max 3): ");
    scanf("%d", &c1);

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++){
        for(j = 0; j < c1; j++){
            printf("mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter number of rows for second matrix (max 3): ");
    scanf("%d", &r2);
    printf("Enter number of columns for second matrix (max 3): ");
    scanf("%d", &c2);

    if(c1 != r2){
        printf("\nMatrix multiplication not possible (columns of first != rows of second).\n");
        return 0;
    }

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i++){
        for(j = 0; j < c2; j++){
            printf("mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            result[i][j] = 0;
        }
    }

    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            for(k = 0; k < c1; k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("\nFirst Matrix:\n");
    for(i = 0; i < r1; i++){
        for(j = 0; j < c1; j++){
            printf("%8d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond Matrix:\n");
    for(i = 0; i < r2; i++){
        for(j = 0; j < c2; j++){
            printf("%8d ", mat2[i][j]);
        }
        printf("\n");
    }

    printf("\nResultant Matrix (Multiplication):\n");
    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            printf("%8d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
