#include <stdio.h>

int main() {
    int arr[3][3][3];
    int i, j, k;         
    int layerSum, total = 0;
    int layerMax, layerMin;

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

    printf("\n--- Layer-wise Analysis ---\n");
    for(i = 0; i < 3; i++){
        layerSum = 0;
        layerMax = arr[i][0][0];
        layerMin = arr[i][0][0];

        printf("\nLayer %d:\n", i+1);
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                printf("%5d ", arr[i][j][k]);
                layerSum += arr[i][j][k];
                if(arr[i][j][k] > layerMax) layerMax = arr[i][j][k];
                if(arr[i][j][k] < layerMin) layerMin = arr[i][j][k];
            }
            printf("\n");
        }

        total += layerSum;
        printf("Layer Total: %d\n", layerSum);
        printf("Layer Max: %d\n", layerMax);
        printf("Layer Min: %d\n", layerMin);
    }


    printf("\n--- Overall Analysis ---\n");
    printf("Total of all layers: %d\n", total);
    printf("Average of all elements: %.2f\n", total / 27.0);

    return 0;
}
