// 77. Combinations

#include <stdio.h>
#include <stdlib.h>

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int i, j, m, count = 0;
    int **result = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    for(i = 1; i <= n; i++){
        int *temp = (int*)malloc(sizeof(int) * k);
        temp[0] = i;
        for(j = 1; j < k; j++){
            temp[j] = 0;
        }
        result[count] = temp;
        (*returnColumnSizes)[count] = k;
        count++;
    }
    for(i = 1; i < k; i++){
        int **temp = (int**)malloc(sizeof(int*) * 10000);
        int *tempColumnSizes = (int*)malloc(sizeof(int) * 10000);
        int tempCount = 0;
        for(j = 0; j < count; j++){
            int last = result[j][i - 1];
            for(m = last + 1; m <= n; m++){
                int *newTemp = (int*)malloc(sizeof(int) * k);
                for(int l = 0; l < k; l++){
                    newTemp[l] = result[j][l];
                }
                newTemp[i] = m;
                temp[tempCount] = newTemp;
                tempColumnSizes[tempCount] = k;
                tempCount++;
            }
        }
        for(j = 0; j < count; j++){
            free(result[j]);
        }
        free(result);
        result = temp;
        *returnColumnSizes = tempColumnSizes;
        count = tempCount;
    }
    *returnSize = count;
    return result;
}

void free_result(int **result, int returnSize){
    for(int i = 0; i < returnSize; i++){
        free(result[i]);
    }
    free(result);
}

int main(){
    int n = 4, k = 2;
    int returnSize;
    int *returnColumnSizes;
    int **result = combine(n, k, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++){
        for(int j = 0; j < k; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    free_result(result, returnSize);

    return 0;
}
