#include <stdio.h>
#include <stdlib.h>

void memory_hog(int size);

int main(void)
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Let's make some space to hold our numbers
    int *a = calloc(size, sizeof(int));
    if (a == NULL) {
        printf("Uh-oh! We couldn't get enough memory.\n");
        return 1;
    }

    // Fill up the array with numbers starting from 'size' and going down
    for (int i = 0; i < size; i++) {
        a[i] = size - i;
    }

    // Print out all the numbers we just put in the array
    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");

    // Show where our array is stored in memory
    printf("Array address: %p\n", (void*)a);

    // Now let's make the array bigger so we can add more stuff
    a = realloc(a, sizeof(int) * (size + 5));
    if (a == NULL) {
        printf("Oops! We ran out of memory while trying to resize.\n");
        return 1;
    }

    // Put the number 9 in the new spots we just made
    for (int i = size; i < size + 5; i++) {
        a[i] = 9;
    }

    // Print out the whole array again to see the new numbers
    for (int i = 0; i < size + 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");

    // Save the address of the array before we free it
    int *save = a;

    // Free up the memory since we're done with it
    free(a);

    // Show where the array used to be
    printf("Saved address: %p\n", (void*)save);

    // Try to print data from the old memory (not safe, but just for fun)
    for (int i = 0; i < 10; i++) {
        printf("save[%d] = %d\n", i, save[i]);
    }
    printf("\n");

    return 0;
}

void memory_hog(int size)
{
    // Get some memory but never free it (this isn't good practice)
    int *a = malloc(size);
}
