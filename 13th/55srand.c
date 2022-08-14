#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10 

void init_arr(int*arr, int size )
{
        int i;
        for(i = 0; i < MAX; i++)
        {   
                arr[i] = rand() % 100;
        }   
}

void travel_arr(int *arr, int size)
{
        int i;
        for(i = 0; i < MAX; i++)
        {   
                printf("%d ", arr[i]);
        }  
	putchar(10); 
}
int main(void)
{
        srand(time(NULL));
        int arr[MAX];
	int size;
	size = sizeof(arr) / sizeof(arr[0]);
        init_arr(arr, MAX );
        travel_arr(arr, MAX);
return 0;
}
