#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 100
#define Run 10

// Function for sequential matrix multiplication
void multiplySequential(int A[Size][Size], int B[Size][Size], int C[Size][Size]) {
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < Size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    static int A[Size][Size], B[Size][Size], C[Size][Size];
    double total_time = 0.0; // ✅ Declare & initialize total_time

    // Initialize matrices with random values
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    // Run matrix multiplication multiple times and record execution time
    for (int i = 0; i < Run; i++) {
        clock_t start = clock();
        multiplySequential(A, B, C);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0; // Convert to milliseconds
        total_time += time_taken; // ✅ Fixed total_time accumulation

        printf("Time taken for run %d: %.2f ms\n", i + 1, time_taken);
    }

    // Calculate and print average execution time
    double avg_time = total_time / Run;
    printf("Average time taken: %.2f ms\n", avg_time);

    return 0;
}
