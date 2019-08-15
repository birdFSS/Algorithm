#include <func.h>

void Merge(int* A, int * tmpA, int left, int right, int rightEnd)
{
    int leftEnd = right - 1;    //这里假设两个归并数组是紧挨着的，实际也是
    int tmp = left;
    int numElements = rightEnd - left + 1;

    while(left <= leftEnd && right <= rightEnd)
    {
        if(A[left] <= A[right]) tmpA[tmp++] = A[left++];
        else                    tmpA[tmp++] = A[right++]; 
    }

    while(left <= leftEnd) tmpA[tmp++] = A[left++];

    while(right <= rightEnd) tmpA[tmp++] = A[right++];


    for(int i=0; i != numElements; --rightEnd, ++i)
    {
        A[rightEnd] = tmpA[rightEnd];
    }
}

void Merge_pass(int * A, int * tmpA, int N, int length)
{
    int i;
    for(i=0; i <= N - 2 * length; i += 2*length)
    {
        Merge(A, tmpA, i, i+length, i + 2*length-1);
    }
    if(i+length < N)
    {
        Merge(A, tmpA, i, i+length, N-1);
    }else{
        for(int j=i; j < N; ++j)
            tmpA[j] = A[j];
    }
}


void MergeSort(int* A, int len)
{
    int length = 1;
    int * tmpA = (int*)malloc(sizeof(int) * len);
    if(NULL != tmpA)
    {
        while(length < len)
        {
            Merge_pass(A, tmpA, len, length);
            length <<= 1;
            Merge_pass(tmpA, A, len, length);
            length <<= 1;
        }
        free(tmpA);
    }else{
        perror("malloc");
        return ;
    }
}

int main()
{
    int arr[10] = {54,34,67,23,88,12,56,98,32,99};
    MergeSort(arr, sizeof(arr)/ sizeof(int));
    for(int i=0; i!=10;++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

