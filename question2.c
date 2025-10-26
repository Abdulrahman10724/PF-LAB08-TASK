#include <stdio.h>

int main() {
    int matrix[5][5], matrix2[5][5];
    int row, col, i, j, isSquare = 0, isRectangular = 0;
    int isZero = 1, isIdentity = 1, isDiagonal = 1, isScalar = 1;
    int isUpper = 1, isLower = 1, isSymmetric = 1, isSkewSymmetric = 1;
    int isSingular = 0, isRow = 0, isCol = 0, isNull = 1;
    int isIdempotent = 1, isNilpotent = 1, det;
    int scalarValue = -1;

    printf("Enter number of rows (max 5): ");
    scanf("%d", &row);
    printf("Enter number of columns (max 5): ");
    scanf("%d", &col);

    printf("Enter elements of the matrix:\n");
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }


    if(row == col)
        isSquare = 1;
    else
        isRectangular = 1;

    if(row == 1) isRow = 1;
    if(col == 1) isCol = 1;

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(matrix[i][j] != 0) isZero = 0;
            if(i == j) {
                if(matrix[i][j] != 1) isIdentity = 0;
                if(scalarValue == -1) scalarValue = matrix[i][j];
                else if(matrix[i][j] != scalarValue) isScalar = 0;
            } else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    isDiagonal = 0;
                    isScalar = 0;
                }
            }
        }
    }

    if(isSquare) {
        for(i = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                if(i > j && matrix[i][j] != 0) isUpper = 0;
                if(i < j && matrix[i][j] != 0) isLower = 0;
            }
        }
    } else {
        isUpper = 0;
        isLower = 0;
    }

    if(isSquare) {
        for(i = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                if(matrix[i][j] != matrix[j][i]) isSymmetric = 0;
                if(matrix[i][j] != -matrix[j][i]) isSkewSymmetric = 0;
            }
        }
    } else {
        isSymmetric = 0;
        isSkewSymmetric = 0;Z
    }

    if(isSquare) {
        if(row == 2) {
            det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        } else if(row == 3) {
            det = matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])
                - matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])
                + matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);
        } else det = 1; 
        if(det == 0) isSingular = 1;
    }

    if(isZero) isNull = 1;
    else isNull = 0;

    if(isSquare && row == 2) {
        int a = matrix[0][0], b = matrix[0][1], c = matrix[1][0], d = matrix[1][1];
        int m2[2][2];
        m2[0][0] = a*a + b*c;
        m2[0][1] = a*b + b*d;
        m2[1][0] = c*a + d*c;
        m2[1][1] = c*b + d*d;
        if(m2[0][0] != a || m2[0][1] != b || m2[1][0] != c || m2[1][1] != d)
            isIdempotent = 0;
        if(m2[0][0] != 0 || m2[0][1] != 0 || m2[1][0] != 0 || m2[1][1] != 0)
            isNilpotent = 0;
    } else {
        isIdempotent = 0;
        isNilpotent = 0;
    }

    printf("\nMatrix Types:\n");
    if(isSquare) 
	printf("Square Matrix\n");
    if(isRectangular) 
	printf("Rectangular Matrix\n");
    if(isZero) 
	printf("Zero Matrix\n");
    if(isIdentity) 
	printf("Identity Matrix\n");
    if(isDiagonal) 
	printf("Diagonal Matrix\n");
    if(isScalar) 
	printf("Scalar Matrix\n");
    if(isUpper) 
	printf("Upper Triangular Matrix\n");
    if(isLower) 
	printf("Lower Triangular Matrix\n");
    if(isSymmetric) 
	printf("Symmetric Matrix\n");
    if(isSkewSymmetric) 
	printf("Skew-Symmetric Matrix\n");
    if(isSingular) 
	printf("Singular Matrix\n");
    else if(isSquare)
	 printf("Non-Singular Matrix\n");
    if(isRow) 
	printf("Row Matrix\n");
    if(isCol) 
	printf("Column Matrix\n");
    if(isNull) 
	printf("Null Matrix\n");
    if(isIdempotent) 
	printf("Idempotent Matrix\n");
    if(isNilpotent) 
	printf("Nilpotent Matrix\n");


    return 0;
}
