#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/*Unsorted search, [SKELETTKOD]*/
bool unsorted_search(int array[], int length, int key)
{
    for (int index = 0; index < length; index++)
    {
        if (array[index] == key)
        {
            return true;
        }
    }
    return false;
}

/*Sorted search */
bool sorted_search(int array[], int length, int key)
{
    for (int index = 0; index < length; index++)
    {
        if (array[index] == key)
        {
            return true;
        }
        else if (array[index] > key)
        {
            return false;
        }
    }
    return false;
}

// Skapa Sorterad lista (Inga kopior) [SKELETTKOD]
int *sorted(int n)
{
    int *array = (int *)malloc(n * sizeof(int));
    int nxt = 0;
    for (int i = 0; i < n; i++)
    {
        nxt += rand() % 10 + 1;
        array[i] = nxt;
    }
    return array;
}

// Random list generator
int *Random_Array_Generator(int length, int element_max_value)
{
    int *array = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % element_max_value;
    }
    return array;
}

int main()
{
    // Configuration menu
    int array_length = 1000000;
    int array_element_size = 1000000;
    int key_value = rand()%100000;
    double interval = 0;
    double interval2 = 0;

    for (int i = 0; i < 1000; i++){
    int *random_array = Random_Array_Generator(array_length, array_element_size);
     LARGE_INTEGER frequency; 
     LARGE_INTEGER start; 
     LARGE_INTEGER end; 
     QueryPerformanceFrequency(&frequency); 
     QueryPerformanceCounter(&start);
     unsorted_search(random_array, array_length, key_value);
      // code to be measured 
     QueryPerformanceCounter(&end); 
     interval += (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
    }
    double average_unsorted_time = interval/1000;
    printf("Average unsorted time search: %lf\n", average_unsorted_time);

    for (int i = 0; i < 1000; i++){
    int *sorted_array = sorted(array_length);
     LARGE_INTEGER frequency2; 
     LARGE_INTEGER start2; 
     LARGE_INTEGER end2; 
     QueryPerformanceFrequency(&frequency2); 
     QueryPerformanceCounter(&start2);
    sorted_search(sorted_array, array_length, key_value);
      // code to be measured 
     QueryPerformanceCounter(&end2); 
     interval2 += (double) (end2.QuadPart - start2.QuadPart) / frequency2.QuadPart; 
    }
    double average_sorted_time = interval2/1000;
    printf("Average sorted search: %lf", average_sorted_time);

}
/*Oavsett hur stor lista jag gör tar själva sökningen under 1 sekund? Även om jag sätter det sökta elementet sist medvetet? Annars 0 sekunder  */