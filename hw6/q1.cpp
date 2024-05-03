// Xuebao Zhao
// 002108354
#include<iostream>
#include<time.h>
using namespace std;

int A[100];

int FibonacciR(int n);
int FibonacciD(int n);

int main() {
    int n; //The user inputs this number to calculate its Fibonacci sequence 
    cout << "n = ";
    cin >> n;

    // initialize all elements in array A to an invalid Fibonacci value 
    for (int i = 0; i <= n; i++)
        A[i] = -1;

    clock_t time;
    cout << "Using dp Methord:" << endl;
    time = clock();
    //Find Fibonacci sequence n using the Dynamic programming function 
    cout << " FibonacciD(n) = " << FibonacciD(n) << endl;
    time = clock() - time; // Get the time
    cout << "This way costs: " << ((float)time / CLOCKS_PER_SEC) *1000 << " ms" << endl << endl;

    cout << "Using recursion Methord:";
    time = clock();
    //Find Fibonacci sequence n using the recursive only function 
    cout << "\n FibonacciR(n) = " << FibonacciR(n) << endl;
    time = clock() - time; // Get the time
    cout << "This way costs: " << ((float)time / CLOCKS_PER_SEC) *1000 << " ms" << endl;

    return 0;
}

int FibonacciD(int n)
{
    if (n < 2) return n;
    if (A[n] != -1) return A[n];
    A[n] = FibonacciD(n - 1) + FibonacciD(n - 2); // Store A[n]
    return A[n];
}

int FibonacciR(int n)
{
    if (n < 2) return n; // Return
    else return FibonacciR(n - 1) + FibonacciR(n - 2); // F(n) = F(n - 1) + F(n - 2)
}