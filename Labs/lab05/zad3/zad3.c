#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int binary_search(int array[], int size, int target, int *steps) {
    int left = 0;
    int right = size - 1;
    *steps = 0;

    while (left <= right) {
        (*steps)++;
        int middle = (left + right) / 2;

        if (array[middle] == target) {
            return middle;
        } else if (array[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    int array[MAX];
    int size, lower_bound, upper_bound;
    int i;
    int target, index, steps;

    srand(time(NULL));

    printf("Enter number of array elements (max %d): ", MAX);
    scanf("%d", &size);

    if (size <= 0 || size > MAX) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter lower bound (a): ");
    scanf("%d", &lower_bound);
    printf("Enter upper bound (b): ");
    scanf("%d", &upper_bound);

    if (lower_bound > upper_bound) {
        printf("Lower bound cannot be greater than upper bound!\n");
        return 1;
    }

    
    for (i = 0; i < size; i++) {
        array[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    }

    printf("\nArray before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    sort(array, size);

    printf("\nArray after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("\nEnter value to search: ");
    scanf("%d", &target);

    index = binary_search(array, size, target, &steps);

    if (index != -1) {
        printf("Value %d found at index %d.\n", target, index);
        printf("Steps taken: %d\n", steps);
    } else {
        printf("Value %d not found in the array.\n", target);
        printf("Steps taken: %d\n", steps);
    }

    return 0;
}
