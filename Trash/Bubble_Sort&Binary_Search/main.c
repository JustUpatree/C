#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    FALSE,
    TRUE
} bool;

int* ArrayInit(int);
void ArrayDisplay(int*, int);
void ArrayFill(int*, int);
void ArraySort(int*, int);
int ArrayBinarySearch(int*, int, int);
    
int main()
{
    printf("Array size: ");
    int array_size;
    scanf("%d", &array_size);
    register int* array = ArrayInit(array_size);
    ArrayFill(&array[0], array_size);
    ArrayDisplay(&array[0], array_size);
    ArraySort(&array[0], array_size);
    ArrayDisplay(&array[0], array_size);
    int searched_number = ArrayBinarySearch(&array[0], array_size, 10);
    (searched_number != -1) ? 
        printf("Pos of searched number: %d\n", searched_number)
    :  
        printf("Arr has no the number\n");
    return 0;
}

int* ArrayInit(int array_size)
{
    int* ptr = malloc(array_size * 4);
    return ptr;
}
void ArrayFill(int* array, int array_size)
{
    srand(time(NULL));
    int i = 0;
    while(i < array_size)
    {
        array[i] = rand() % 20;
        i++;
    }
}
void ArrayDisplay(int* array, int array_size)
{
    int i = 0;
    while(i < array_size)
    {
        printf("%d", array[i]);
        if(i == array_size - 1)
        {    
            putchar('.');
            putchar('\n');
        }    
        else    
        {   
            putchar(',');
            putchar(' ');
        }
        i++;
    }
}
void ArraySort(int* array, int array_size)
{
    bool SORTED_ARRAY = TRUE;
    int i = 0, tmp;
    while(i < array_size)
    {
        if(i == array_size - 1)
        {
            if(SORTED_ARRAY == TRUE)
            {
                break;
            }
            else
            {
                i = 0;
                SORTED_ARRAY = TRUE;
                continue;
            }
        }
        if(array[i] > array[i + 1])
        {
            tmp = *(array + i);
            *(array + i) = *(array + i + 1);
            *(array + i + 1) = tmp;
            SORTED_ARRAY = FALSE;
        }
        i++;
    }
}
int ArrayBinarySearch(int* array, int array_size, int searched_number)
{
    int min = 0, max = array_size - 1, avg;
    while(1)
    {
        avg = (max + min) / 2;
        if(array[avg] > searched_number)
        {
            max = avg;
        }
        else
        {
            min = avg;
        }
        if(array[avg] == searched_number)
        {
            return avg;
        }
        else if(max - min == 1)
        {
            return -1;
        }
    }
}