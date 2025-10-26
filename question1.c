#include <stdio.h>

int main() {
    float mat[3][3], trans[3][3], cof[3][3], adj[3][3], inv[3][3];
    float det;
    int i, j, r, c;

    // Input matrix
    printf("Enter 3x3 matrix values:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("mat[%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%8.2f ", mat[i][j]);
        printf("\n");
    }

    // Transpose
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            trans[j][i] = mat[i][j];

    printf("\nTranspose Matrix:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%8.2f ", trans[i][j]);
        printf("\n");
    }

    // Determinant
    det = mat[0][0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1])
        - mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0])
        + mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);
    printf("\nDeterminant: %.2f\n", det);

    // Cofactor matrix
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            float sub[2][2];
            r=0;
            for(int x=0;x<3;x++){
                if(x==i) continue;
                c=0;
                for(int y=0;y<3;y++){
                    if(y==j) continue;
                    sub[r][c] = mat[x][y];
                    c++;
                }
                r++;
            }
            float minor = sub[0][0]*sub[1][1]-sub[0][1]*sub[1][0];
            cof[i][j] = ((i+j)%2==0 ? 1 : -1)*minor;
        }
    }

    printf("\nCofactor Matrix:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%8.2f ", cof[i][j]);
        printf("\n");
    }

    // Adjoint (transpose of cofactor)
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            adj[j][i] = cof[i][j];

    printf("\nAdjoint Matrix:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%8.2f ", adj[i][j]);
        printf("\n");
    }

    // Inverse
    if(det==0){
        printf("\nInverse does not exist (determinant is 0)\n");
    } else {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                inv[i][j] = adj[i][j]/det;

        printf("\nInverse Matrix:\n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++)
                printf("%8.2f ", inv[i][j]);
            printf("\n");
        }
    }

    return 0;
}
