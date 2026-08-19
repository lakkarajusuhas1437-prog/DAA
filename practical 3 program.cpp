#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// ---------- MAX HEAP ----------

void heapifyMax(vector<int>& arr, int n, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void maxHeapSort(vector<int>& arr)
{
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

// ---------- MIN HEAP ----------

void heapifyMin(vector<int>& arr, int n, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(arr[index], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void minHeapSort(vector<int>& arr)
{
    int n = arr.size();

    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }

    // Min heap gives descending order, so reverse it
    reverse(arr.begin(), arr.end());
}

// ---------- MAIN ----------

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    vector<int> data(n);

    // Generate random values
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 100000;
    }

    // Make separate copies
    vector<int> maxHeapData = data;
    vector<int> minHeapData = data;

    // ---------- MAX HEAP SORT ----------

    auto maxStart = high_resolution_clock::now();

    maxHeapSort(maxHeapData);

    auto maxEnd = high_resolution_clock::now();

    // ---------- MIN HEAP SORT ----------

    auto minStart = high_resolution_clock::now();

    minHeapSort(minHeapData);

    auto minEnd = high_resolution_clock::now();

    // Calculate execution times
    auto maxTime = maxEnd - maxStart;
    auto minTime = minEnd - minStart;

    cout << "\n====================================\n";
    cout << "        MAX HEAP SORT RESULT\n";
    cout << "====================================\n";

    cout << "Time in Nanoseconds  : "
         << duration_cast<nanoseconds>(maxTime).count()
         << " ns\n";

    cout << "Time in Microseconds : "
         << duration_cast<microseconds>(maxTime).count()
         << " us\n";

    cout << "Time in Milliseconds : "
         << duration_cast<milliseconds>(maxTime).count()
         << " ms\n";


    cout << "\n====================================\n";
    cout << "        MIN HEAP SORT RESULT\n";
    cout << "====================================\n";

    cout << "Time in Nanoseconds  : "
         << duration_cast<nanoseconds>(minTime).count()
         << " ns\n";

    cout << "Time in Microseconds : "
         << duration_cast<microseconds>(minTime).count()
         << " us\n";

    cout << "Time in Milliseconds : "
         << duration_cast<milliseconds>(minTime).count()
         << " ms\n";

    return 0;
}
