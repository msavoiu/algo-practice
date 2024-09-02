#include <iostream>
#include <vector>

// works!

std::vector<int> bubbleSort(std::vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        // you need to 'bubble' through the array as many times are there are items in the array
        int first_index = 0;
        int second_index = 1;
        int temp = 0;

        while ((first_index <= (array.size() - 2)) && (second_index <= (array.size() - 1))) {
            // std::cout << "Checking indices " << first_index << " and " << second_index << '\n';
            if (array[first_index] > array[second_index]) {
                temp = array[first_index];
                array[first_index] = array[second_index];
                array[second_index] = temp;
            }

            // for (int item : array) {
            //     std::cout << item << ", ";
            // }

            first_index++;
            second_index++;
        }
    }

    return array;
}

int main() {
    std::vector<int> array = {9, 1, 8, 2, 7, 3, 6, 4, 5};

    std::cout << "Original array: " << '\n';
    for (int item : array) {
        std::cout << item << ", ";
    }
    std::cout << '\n';

    std::vector<int> sorted_array = bubbleSort(array);

    std::cout << "Sorted array: " << '\n';
    for (int item : sorted_array) {
        std::cout << item << ", ";
    }
    std::cout << '\n';

    return 0;
}