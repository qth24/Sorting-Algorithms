#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono; 

int main()
{
    cout << "        C++SORT ALGORITHM" << endl; 

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

        // Sort the array - c++
        sort(input_arr, input_arr+1000000);
        
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