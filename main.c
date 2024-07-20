/*Design and implement C/C++ Program to find a subset of a given set S = {sl , s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d.*/

#include <stdio.h>

#define MAX 10

int set[MAX], subset[MAX];
int n, target_sum, subset_size = 0;
int solution_found = 0;

void print_subset() {
    printf("{");
    for (int i = 0; i < subset_size; i++) {
        printf("%d", subset[i]);
        if (i < subset_size - 1) printf(",");
    }
    printf("}\n");
}

void find_subset(int index, int current_sum) {
    if (current_sum == target_sum) {
        solution_found = 1;
        print_subset();
        return;
    }

    if (index >= n || current_sum > target_sum) {
        return;
    }

    // Include current element
    subset[subset_size++] = set[index];
    find_subset(index + 1, current_sum + set[index]);
    subset_size--;

    // Exclude current element
    find_subset(index + 1, current_sum);
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the set of values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    printf("The subsets with the target sum are:\n");
    find_subset(0, 0);

    if (!solution_found) {
        printf("No solution found.\n");
    }

    return 0;
}