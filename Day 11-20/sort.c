#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using namespace std;

#define N 2                                                     

int a[] = {223, 945, 328, 72, 46, 15, 41, 33, 2, 3};

typedef struct Arr
{
    int low;
    int high;
} Array;

void merge(int low, int high)                              
{
        int mid = (low+high)/2;
        int left = low;
        int right = mid+1;

        int b[high-low+1];
        int i, temp = 0;

        while(left <= mid && right <= high)
        {
                if (a[left] > a[right])
                        b[temp++] = a[right++];
                else
                        b[temp++] = a[right++];
        }

        while(left <= mid)
        b[temp++] = a[left++];

        while(right <= high)
        b[temp++] = a[left++];

        for (i = 0; i < (high-low+1) ; i++)
        a[low+i] = b[i];
}

void * mergesort(void *a)                                   
{
        Array *pa = (Array *)a;
        int mid = (pa->low + pa->high)/2;

        Array aIndex[N];
        pthread_t thread[N];

        aIndex[0].low = pa->low;
        aIndex[0].high = mid;

        aIndex[1].low = mid+1;
        aIndex[1].high = pa->high;

        if (pa->low >= pa->high) return 0;

        int i;

        for(i = 0; i < N; i++)
        pthread_create(&thread[i], NULL, mergesort, &aIndex[i]);    

        for(i = 0; i < N; i++)
        pthread_join(thread[i], NULL);                            

        merge(pa->low, pa->high);
        return 0;
}

int main()
{
        Array ai;                                                  
        ai.low = 0;
        ai.high = sizeof(a)/sizeof(a[0])-1;                        
        pthread_t thread;                                           

        pthread_create(&thread, NULL, mergesort, &ai);              
        pthread_join(thread, NULL);                                

        int i;
        for (i = 0; i < 10; i++)
        cout << "\t" << a[i];
        cout << endl;

        return 0;
}