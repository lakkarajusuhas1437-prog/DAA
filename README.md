#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// ---------------- MAX HEAP ---------------- //

void buildMaxHeap(vector<int>& arr, int n, int index)
{
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        buildMaxHeap(arr, n, largest);
    }
}

void maxHeapSort(vector<int>& arr)
{
    int size = arr.size();

    // Create Max Heap
    for (int i = size / 2 - 1; i >= 0; i--)
        buildMaxHeap(arr, size, i);

    // Sorting
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        buildMaxHeap(arr, i, 0);
    }
}

// ---------------- MIN HEAP ---------------- //

void buildMinHeap(vector<int>& arr, int n, int index)
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    if (rightChild < n && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    if (smallest != index)
    {
        swap(arr[index], arr[smallest]);
        buildMinHeap(arr, n, smallest);
    }
}

void minHeapSort(vector<int>& arr)
{
    int size = arr.size();

    // Create Min Heap
    for (int i = size / 2 - 1; i >= 0; i--)
        buildMinHeap(arr, size, i);

    // Sorting
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        buildMinHeap(arr, i, 0);
    }

    // Convert descending result to ascending
    reverse(arr.begin(), arr.end());
}

// ---------------- MAIN FUNCTION ---------------- //

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    // Generate random numbers
    srand(time(nullptr));

    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 100000;
    }

    vector<int> maxHeapData = data;
    vector<int> minHeapData = data;

    // -------- MAX HEAP SORT TIME -------- //

    auto maxStart = high_resolution_clock::now();

    maxHeapSort(maxHeapData);

    auto maxEnd = high_resolution_clock::now();

    // -------- MIN HEAP SORT TIME -------- //

    auto minStart = high_resolution_clock::now();

    minHeapSort(minHeapData);

    auto minEnd = high_resolution_clock::now();

    // Calculate execution time
    auto maxNano = duration_cast<nanoseconds>(maxEnd - maxStart);
    auto maxMicro = duration_cast<microseconds>(maxEnd - maxStart);
    auto maxMilli = duration_cast<milliseconds>(maxEnd - maxStart);

    auto minNano = duration_cast<nanoseconds>(minEnd - minStart);
    auto minMicro = duration_cast<microseconds>(minEnd - minStart);
    auto minMilli = duration_cast<milliseconds>(minEnd - minStart);

    // -------- DISPLAY RESULTS -------- //

    cout << "\n====================================\n";
    cout << "        MAX HEAP SORT RESULT\n";
    cout << "====================================\n";
    cout << "Time in Nanoseconds  : "
         << maxNano.count() << " ns\n";
    cout << "Time in Microseconds : "
         << maxMicro.count() << " us\n";
    cout << "Time in Milliseconds : "
         << maxMilli.count() << " ms\n";

    cout << "\n====================================\n";
    cout << "        MIN HEAP SORT RESULT\n";
    cout << "====================================\n";
    cout << "Time in Nanoseconds  : "
         << minNano.count() << " ns\n";
    cout << "Time in Microseconds : "
         << minMicro.count() << " us\n";
    cout << "Time in Milliseconds : "
         << minMilli.count() << " ms\n";

    return 0;
}
