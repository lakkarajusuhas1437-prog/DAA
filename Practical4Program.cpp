#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Iterative Factorial
// Time Complexity: O(n)
// Space Complexity: O(1)
long long factorialIterative(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Factorial
// Time Complexity: O(n)
// Space Complexity: O(n)
long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers.";
        return 0;
    }

    // Iterative Factorial
    auto start1 = high_resolution_clock::now();

    long long result1 = factorialIterative(n);

    auto end1 = high_resolution_clock::now();

    // Recursive Factorial
    auto start2 = high_resolution_clock::now();

    long long result2 = factorialRecursive(n);

    auto end2 = high_resolution_clock::now();

    // Calculate execution time
    auto time1 =
        duration_cast<nanoseconds>(end1 - start1);

    auto time2 =
        duration_cast<nanoseconds>(end2 - start2);

    // Display results
    cout << "\n-----------------------------\n";

    cout << "Iterative Factorial = "
         << result1 << endl;

    cout << "Iterative Time = "
         << time1.count() << " ns" << endl;

    cout << "\nRecursive Factorial = "
         << result2 << endl;

    cout << "Recursive Time = "
         << time2.count() << " ns" << endl;

    cout << "-----------------------------\n";

    return 0;
}
