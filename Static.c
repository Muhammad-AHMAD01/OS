#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define Size 500
#define Threads 4
#define Run 10

void ParallelMatrixMultiplication(int A[Size][Size], int B[Size][Size], int C[Size][Size])
{
    #pragma omp parallel for num_threads(Threads) schedule(static)
    for (int i=0;i <Size;i++)
    {
        for (int j=0; j<Size; j++)
        {
            C[i][j]=0;
            for(int k=0;k<Size;k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main()
{
    int A[Size][Size], B[Size][Size], C[Size][Size];
    srand(50);
    for(int i=0;i<Size;i++)
    {
        for(int j=0;j<Size;j++)
        {
            A[i][j]=rand()%10;
            B[i][j]=rand()%10;

        }
    }

    double total_time = 0;

    for (int r = 0; r < Run; r++)
    {
        double start = omp_get_wtime();  // Start time
        ParallelMatrixMultiplication(A, B, C);
        double end = omp_get_wtime();  // End time

        double iteration_time = end - start;  // Time for this run
        total_time += iteration_time;  // Add to total time

        // Print time for each iteration
        printf("Run %d: Execution Time = %f seconds\n", r + 1, iteration_time);
    }

    double avg_time = total_time/Run;
    printf("Average Execution Time over %d runs: %f seconds\n", Run, avg_time);

    return 0;
}