#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono; 

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    // Merge the temporary arrays back into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    cout << "        MERGESORT ALGORITHM" << endl; 

    // Run 10 times (testcases)
    for (int loop = 1; loop <= 10; loop++)
    {
        // Open file and read input
        string input = "Testcase/testcase";
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

        // Sort the array - mergesort
        mergeSort(input_arr, 0, 999999);
        
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