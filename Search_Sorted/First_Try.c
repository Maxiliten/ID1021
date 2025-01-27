#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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
    int array_length = 10000;
    int array_element_size = 10;
    int key_value = 9;

    int *sorted_array = sorted(array_length);
    int *random_array = Random_Array_Generator(array_length, array_element_size);

    // Unsorted search
    clock_t time_unsorted_start = clock();
    unsorted_search(random_array, array_length, key_value);
    clock_t time_unsorted_end = clock();
    double total_time_unsorted = (double)(time_unsorted_end - time_unsorted_start) / CLOCKS_PER_SEC;
    printf("Time for unsorted search:%lf\n", total_time_unsorted);

    // Sorted search (optimised)
    clock_t time_sorted_start = clock();
    sorted_search(sorted_array, array_length, key_value);
    clock_t time_sorted_end = clock();
    double total_time_sorted = (double)(time_sorted_end - time_sorted_start) / CLOCKS_PER_SEC;
    printf("Time for sorted search:%lf\n", total_time_sorted);

    double time_difference = total_time_unsorted - total_time_sorted;
    printf("Time Comparison, sorted search is:%lf", time_difference, "faster");
}
/*Oavsett hur stor lista jag gör tar själva sökningen under 1 sekund? Även om jag sätter det sökta elementet sist medvetet? Annars 0 sekunder */