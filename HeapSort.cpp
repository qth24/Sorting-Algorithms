#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono; 

void heapify(int arr[], int n, int i) {
    int largest = i; // Assume the root is the largest
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // Check if the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if the right child is larger than the root
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move the largest element to the end
        heapify(arr, i, 0);
    }
}

int main()
{
    cout << "        HEAPSORT ALGORITHM" << endl; 

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

        // Sort the array - heapsort
        heapSort(input_arr, 999999);
        
        // Print the array (If you want)
        /* for (int i = 0; i < 1000000; i++)
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