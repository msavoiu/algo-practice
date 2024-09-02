#include <iostream>
#include <vector>

/*
1. determine pivot 
2. create indices i and j and temp variable
3. go through the array and check for places where
   index j's value is less than the pivot
4. if it is less, i++ and swap i and j
5. if it is not less, j++ and check again
6. when array[j] == pivot, swap pivot value and array[j]
7. recurse w/ subarrays that are split at the pivot
*/

// if you don't pass by reference for both functions it will not work!
int partition(std::vector<int> &array, int start_index, int end_index) {
    int pivot = array[end_index];
    int i = start_index - 1;

    for (int j = start_index; j <= end_index - 1; j++) {
        if (array[j] < pivot) {
            i++;
            if (i != j) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    i++; // swapping the pivot at the end of everything
    int temp = array[i];
    array[i] = array[end_index];
    array[end_index] = temp;

    return i;
}

std::vector<int> quickSort(std::vector<int> &array, int start_index, int end_index) {
    // base case, check if the 'subarrays' have a size of 1
    if (end_index <= start_index) {
        return array;
    }

    int pivot = partition(array, start_index, end_index);

    // int pivot = array[end_index - 1]; // write

    // int i = start_index -1;
    // int j = start_index;
    // int temp;

    // while (j <= end_index) {
    //     if (j == end_index) {
    //         i++;
    //         temp = array[j];
    //         array[j] = array[i];
    //         array[i] = temp;

    //     } else if (array[j] < pivot) {
    //         i++;
    //         if (i != j) {
    //             temp = array[j];
    //             array[j] = array[i];
    //             array[i] = temp;
    //         }
    //     }
    //     j++;
        
    //     // for cli debugging:
    //     std::cout << "Current array: ";
    //     for (int item : array) {
    //         std::cout << item << ", ";
    //     }
    //     std::cout << '\n';
    // }

    quickSort(array, start_index, pivot - 1);
    quickSort(array, pivot + 1, end_index);
    return array;
}

int main() {
    std::vector<int> array = {8, 2, 4, 7, 1, 3, 9, 6, 5};
    std::vector<int> sorted_array = quickSort(array, 0, 8);

    std::cout << "Sorted array: ";
    for (int item : sorted_array) {
        std::cout << item << ", ";
    }
    std::cout << '\n';
    return 0;
}