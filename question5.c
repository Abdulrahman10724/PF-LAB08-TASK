#include <stdio.h>

int main() {
    int arr[3][3][3];
    int i, j, k;
    int same;

    // Input 3D array
    printf("Enter elements for 3x3x3 array:\n");
    for(i = 0; i < 3; i++){
        printf("\nLayer %d:\n", i+1);
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                printf("arr[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    // Display layers
    for(i = 0; i < 3; i++){
        printf("\nLayer %d:\n", i+1);
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                printf("%5d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    // Compare Layer 0 and Layer 1
    same = 1;  // assume identical
    for(j = 0; j < 3; j++){
        for(k = 0; k < 3; k++){
            if(arr[0][j][k] != arr[1][j][k]){
                same = 0;
                break;
            }
        }
        if(same == 0) break;
    }
    if(same) printf("\nLayer 1 and Layer 2 are IDENTICAL");
    else printf("\nLayer 1 and Layer 2 are DISTINCT");

    // Compare Layer 0 and Layer 2
    same = 1;
    for(j = 0; j < 3; j++){
        for(k = 0; k < 3; k++){
            if(arr[0][j][k] != arr[2][j][k]){
                same = 0;
                break;
            }
        }
        if(same == 0) break;
    }
    if(same) printf("\nLayer 1 and Layer 3 are IDENTICAL");
    else printf("\nLayer 1 and Layer 3 are DISTINCT");

    // Compare Layer 1 and Layer 2
    same = 1;
    for(j = 0; j < 3; j++){
        for(k = 0; k < 3; k++){
            if(arr[1][j][k] != arr[2][j][k]){
                same = 0;
                break;
            }
        }
        if(same == 0) break;
    }
    if(same) printf("\nLayer 2 and Layer 3 are IDENTICAL");
    else printf("\nLayer 2 and Layer 3 are DISTINCT");

    printf("\n");
    return 0;
}
