#include <stdio.h>

void test(int arr[],int n)
{
    int i;
    for(i = 0; i < n; i++)
        arr[i] = 4;
}

int main(void)
{
    int i;
    int arr[4] = {1,2,3,4};
    test(arr,4);

    for(i = 0; i < 4; i++)
        printf("%d \n",arr[i]);
}