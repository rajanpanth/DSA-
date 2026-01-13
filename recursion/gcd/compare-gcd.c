#include <stdio.h>
#include <time.h>

// Iterative function to find GCD using Euclidean Algorithm
int findGCD_Iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive function to find GCD using Euclidean Algorithm
int findGCD_Recursive(int a, int b) {
    // Base case: if b is 0, the GCD is a
    if (b == 0) {
        return a;
    }
    // Recursive step: call the function with (b, a % b)
    return findGCD_Recursive(b, a % b);
}

int main() {
    int num1, num2;
    clock_t start, end;
    double time_iterative, time_recursive;
    int result_iterative, result_recursive;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    // Using absolute values to handle negative numbers
    int a = num1 < 0 ? -num1 : num1;
    int b = num2 < 0 ? -num2 : num2;
    
    // Measure time for Iterative approach
    start = clock();
    for (int i = 0; i < 100000; i++) {  // Run multiple times for better measurement
        result_iterative = findGCD_Iterative(a, b);
    }
    end = clock();
    time_iterative = ((double)(end - start)) / CLOCKS_PER_SEC;  // Convert to seconds
    
    // Measure time for Recursive approach
    start = clock();
    for (int i = 0; i < 100000; i++) {  // Run multiple times for better measurement
        result_recursive = findGCD_Recursive(a, b);
    }
    end = clock();
    time_recursive = ((double)(end - start)) / CLOCKS_PER_SEC;  // Convert to seconds
    
    // Display results in a structured table
    printf("\n");
    printf("========================================================================\n");
    printf("                    GCD COMPUTATION TIME COMPARISON\n");
    printf("========================================================================\n");
    printf("Input Numbers: %d and %d\n", num1, num2);
    printf("GCD Result: %d\n", result_iterative);
    printf("------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-20s |\n", "Method", "Time (sec)", "Iterations");
    printf("------------------------------------------------------------------------\n");
    printf("| %-20s | %-15.6f | %-20d |\n", "Iterative", time_iterative, 100000);
    printf("| %-20s | %-15.6f | %-20d |\n", "Recursive", time_recursive, 100000);
    printf("------------------------------------------------------------------------\n");
    
    // Show which is faster
    if (time_iterative < time_recursive) {
        double speedup = time_recursive / time_iterative;
        printf("Result: Iterative is %.2fx faster than Recursive\n", speedup);
    } else if (time_recursive < time_iterative) {
        double speedup = time_iterative / time_recursive;
        printf("Result: Recursive is %.2fx faster than Iterative\n", speedup);
    } else {
        printf("Result: Both methods have similar execution time\n");
    }
    printf("========================================================================\n");
    return 0;
}
