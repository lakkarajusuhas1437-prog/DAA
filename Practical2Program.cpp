#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
using namespace chrono;

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    const int n = 100;
    int arr[n];

    // Generate random numbers
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Binary search requires a sorted array
    sort(arr, arr + n);

    // Select a random element as search key
    int key = arr[rand() % n];

    cout << "Number of Elements = " << n << endl;
    cout << "Search Key = " << key << endl;
    cout << "----------------------------------\n";

    // Linear Search
    auto start = high_resolution_clock::now();

    int linearResult = linearSearch(arr, n, key);

    auto stop = high_resolution_clock::now();

    auto linearTime =
        duration_cast<microseconds>(stop - start).count();

    cout << "Linear Search Time : "
         << linearTime << " microseconds\n";

    if (linearResult != -1)
        cout << "Element Found at Index : "
             << linearResult << "\n";
    else
        cout << "Element Not Found\n";

    cout << "----------------------------------\n";

    // Binary Search
    start = high_resolution_clock::now();

    int binaryResult = binarySearch(arr, n, key);

    stop = high_resolution_clock::now();

    auto binaryTime =
        duration_cast<microseconds>(stop - start).count();

    cout << "Binary Search Time : "
         << binaryTime << " microseconds\n";

    if (binaryResult != -1)
        cout << "Element Found at Index : "
             << binaryResult << endl;
    else
        cout << "Element Not Found" << endl;

    return 0;
}
