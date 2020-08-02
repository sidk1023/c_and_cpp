//The only functional difference between allocating memory with malloc() and with calloc() for the same size, assuming the size computation is accurate, is the latter initializes the block to all bits 0, whereas the former does not.
//
//All bits 0 means all int values in the array are initialized to 0.
//
//The inner loop in the multiply function only increments the element at row i and column j, therefore the function relies on implicit initialization of the array elements to 0. calloc() does that, but not malloc() so you definitely need to use calloc().
//
//Also note these remarks:
//
//in display the computation for the offset of the matrix element at row i column j should be printf(" %5d ", *(arr + i * col + j));
//multiply should return arr and display() should be called in the main function.
//you should check for scanf(), malloc() and calloc()` failure
//you should free allocated memory
//pointer arguments to objects that are not modified by the function should be const qualified so the function can be called with a pointer to a const object.
//Here is a modified version:
//for functions with pointers, remember if we are not altering the value of the pointer keep it as constant
#include <stdio.h>
#include <stdlib.h>

int *getArray(int);
void display(const int *, int, int);
int *multiply(const int *, const int *, int);

int main() {
    int n;
    printf("enter dimension of square matrix:\n");
    if (scanf("%d", &n) != 1)
        return 1;
    printf("\n now give input for the first array");
    int *arr1 = getArray(n);
    if (!arr1)
        return 1;
    display(arr1, n, n);
    printf("\n now give input for the second array");
    int *arr2 = getArray(n);
    if (!arr2)
        return 1;
    display(arr2, n, n);
    printf("\n\n\n");
    int *arr = multiply(arr1, arr2, n);
    if (!arr)
        return 1;
    printf("product of above matrices = \n\n");
    display(arr, n, n);
    free(arr1);
    free(arr2);
    free(arr);
    return 0;
}

int *getArray(int n) {
    int *arr = malloc(sizeof(int) * n * n);
    if (arr == NULL)
        return NULL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", (arr + i * n + j)) != 1) {
                free(arr);
                return NULL;
            }
        }
    }
    return arr;
}

void display(const int *arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf(" %5d ", *(arr + i * col + j));
        }
        printf("\n");
    }
}

int *multiply(const int *arr1, const int *arr2, int n) {
    int *arr = calloc((size_t)n * n, sizeof(int));
    if (arr == NULL)
        return NULL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                *(arr + i * n + j) += (*(arr1 + i * n + k)) * (*(arr2 + k * n + j));
            }
        }
    }
    return arr;
}
