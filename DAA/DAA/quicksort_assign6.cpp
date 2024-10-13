#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for srand()

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for deterministic quicksort (pivot is the last element)
int partitionDeterministic(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1); // Return the partitioning index
}

// Deterministic Quick Sort
void quickSortDeterministic(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partitionDeterministic(arr, low, high);

        // Recursively sort elements before and after partition
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

// Partition function for randomized quicksort (pivot is randomly chosen)
int partitionRandomized(int arr[], int low, int high) {
    // Generate a random index between low and high
    int randomIndex = low + rand() % (high - low + 1);

    // Swap the randomly chosen pivot with the last element
    swap(arr[randomIndex], arr[high]);

    // Proceed with the deterministic partitioning on the swapped array
    return partitionDeterministic(arr, low, high);
}

// Randomized Quick Sort
void quickSortRandomized(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array using a randomized pivot
        int pi = partitionRandomized(arr, low, high);

        // Recursively sort elements before and after partition
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test both deterministic and randomized Quick Sort
int main() {
    srand(time(0)); // Seed for random number generation

    int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array: ";
    printArray(arr1, n);

    // Deterministic Quick Sort
    quickSortDeterministic(arr1, 0, n - 1);
    cout << "Array sorted using deterministic quicksort: ";
    printArray(arr1, n);

    // Randomized Quick Sort
    quickSortRandomized(arr2, 0, n - 1);
    cout << "Array sorted using randomized quicksort: ";
    printArray(arr2, n);

    return 0;
}
