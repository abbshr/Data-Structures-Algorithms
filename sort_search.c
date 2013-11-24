#include <stdio.h>
#include <stdlib.h>

void swap(int* A, int i, int j)
{
    *(A + i) ^= *(A + j);
    *(A + j) ^= *(A + i);
    *(A + i) ^= *(A + j);
}

int diff(int* A, int i, int j)
{
    if (i == j) return 0;
    while (i <= j)
        if (*(A + i) != *(A + (++i)))
            return 1;
    return 0;
}

int findv(int* A, int i, int j)
{
    int v = *A;
    while (i <= j)
        if (*(A + i) != *(A + (++i)))
            return *(A + i) > *(A + i - 1) ? *(A + i) : *(A + i - 1);
}

void QuickSort(int* A, int i, int j)
{
    if (!diff(A, i, j)) return;
    int v = findv(A, i, j);
    int l = i, r = j;
    while (l < r)
    {
        swap(A, l, r);
        while (*(A + l) < v)
            l++;
        while (*(A + r) >= v)
            r--;
    }
    QuickSort(A, i, r);
    QuickSort(A, l, j);
}

int main()
{
    int* A = NULL;
    int n = 0;
    printf("元素个数：\n");
    scanf("%d", &n);
    A = (int* )malloc(sizeof(int) * n);
    printf("依次输入每个元素值:\n");
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", A + i);
    QuickSort(A, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d ", *(A + i));
}