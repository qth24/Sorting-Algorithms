#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono; 

// Swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function: divides array into two parts
int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2; // Choose the middle element as pivot
    int pivot = arr[mid];
    swap(arr[mid], arr[high]); // Move pivot to the end for convenience
    
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in its correct position
    return i + 1;
}

// Quicksort function using recursion
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Sort left part
        quickSort(arr, pi + 1, high); // Sort right part
    }
}

int main()
{
    cout << "        QUICKSORT ALGORITHM" << endl; 

    // Run 10 times (testcases)
    for (int loop = 1; loop <= 10; loop++)
    {
        // Open file and read input
        string input = "../Testcase/testcase";
        input += to_string(loop) + ".txt";
        ifstream inputFile(input);

        cout<<"Đang đọc file "<< input << endl;
        
        int input_arr[1000001];

        // Read input
        int i = 0;
        while (i < 1000000 && inputFile >> input_arr[i]) 
        {
            i++;
        }

        // Start timing
        auto start = high_resolution_clock::now();

        // Sort the array - quicksort
        quickSort(input_arr, 0, 999999);
        
        // Print the array (If you want)
        /*for (int i = 0; i < 1000000; i++)
        {
            cout << input_arr[i] << " ";
        } */

        // End timing
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << " -> Testcase " << loop << " - Thời gian chạy: " << duration.count() << " ms" << endl;

        // Close file
        inputFile.close();
    }
    return 0;
}