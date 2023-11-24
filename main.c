#include <stdio.h>

#define MaxRow 10 // array-maximum no of rows
#define MinRow 1  // array-minimum no of rows
#define MaxCol 6  // array-maximum no of columns
#define MinCol 1  // array-minimum no of columns

int ReadArraySize(int, int);
void ReadArray(int[][MaxCol], int, int);
void AddArray(int[][MaxCol], int[][MaxCol], int[][MaxCol], int, int);
void DispArray(int[][MaxCol], int, int);
void DispArrayT(int[][MaxCol], int, int);

int main() {
    int RowSize, ColSize;
    int a[MaxRow][MaxCol], b[MaxRow][MaxCol], c[MaxRow][MaxCol]; // 1st input array, 2nd input array, resulting array

    // Functions declaration
    printf("Please specify no. of rows of arrays: ");
    RowSize = ReadArraySize(MinRow, MaxRow);

    printf("Please specify no. of columns of arrays: ");
    ColSize = ReadArraySize(MinCol, MaxCol);
    printf("Array size is set to: [%d] [%d]\n", RowSize, ColSize);

    ReadArray(a, RowSize, ColSize); // get all values for array a (scanf)
    ReadArray(b, RowSize, ColSize); // get all values for array b (scanf)

    // find array c[][] = array a[][] + b[][]
    AddArray(a, b, c, RowSize, ColSize);

    // display a, b, and c
    DispArray(a, RowSize, ColSize);
    DispArray(b, RowSize, ColSize);
    DispArray(c, RowSize, ColSize);

    printf("Please type any key to show the transpose: ");
    getchar();

    // display transpose of a, b, and c
    DispArrayT(a, RowSize, ColSize);
    DispArrayT(b, RowSize, ColSize);
    DispArrayT(c, RowSize, ColSize);

    return 0;
}

int ReadArraySize(int MinSize, int MaxSize) {
    int size;
    do {
        printf(" range[%d..%d] : ", MinSize, MaxSize);
        scanf("%d", &size);
    } while (size > MaxSize || size <= MinSize);

    return size;
}

void ReadArray(int arr[][MaxCol], int RowSize, int ColSize) {
    int i, j;

    printf("Enter array elements:\n");
    for (i = 0; i < RowSize; i++) {
        for (j = 0; j < ColSize; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void AddArray(int a[][MaxCol], int b[][MaxCol], int c[][MaxCol], int RowSize, int ColSize) {
    int i, j;

    printf("Calculating array c..\n\n");
    for (i = 0; i < RowSize; i++)
        for (j = 0; j < ColSize; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void DispArray(int arr[][MaxCol], int RowSize, int ColSize) {
    int i, j;

    printf("\nDisplaying array:\n");
    for (i = 0; i < RowSize; i++) {
        for (j = 0; j < ColSize; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void DispArrayT(int arr[][MaxCol], int RowSize, int ColSize) {
    int i, j;

    printf("\nDisplaying transpose of array:\n");
    for (i = 0; i < ColSize; i++) {
        for (j = 0; j < RowSize; j++) {
            printf("%4d", arr[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}
