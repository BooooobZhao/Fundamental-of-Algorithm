// Xuebao Zhao
// 002108354
#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

// Find the max value
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

// Recurive method
int Recursive_CutRod(int* p, int n)
{
	if (n == 0)
		return 0;
	int q = -1; // Initializes to a minimum
	for (int i = 1; i <= n; i++)
		q = max(q, p[i] + Recursive_CutRod(p, n - i)); // Find the max q
	return q;
}

// Dynamic Program
int Memoized_CutRod_Aux(int* p, int n, int* r)
{
	int q;
	if (r[n] >= 0) return r[n]; // r[n] has been calculated
	if (n == 0) q = 0;
	else{
		q = -1;
		for (int i = 1; i <= n; i++) // For each case
			q = max(q, p[i] + Memoized_CutRod_Aux(p, n - i, r)); // Find the max q
	}

	r[n] = q;
	return q;
}

int Memoized_CutRod(int* p, int n)
{
	int* r = new int[n + 1];
	for (int i = 0; i <= n; i++) r[i] = -1; // Initializes to a minimum
	return Memoized_CutRod_Aux(p, n, r);
}

int main()
{
	int n; // The length of Rod
	cout << "Please input the length of Rod: ";
	cin >> n;
	clock_t t; // Record the time
	int* p = new int[n + 1]; // The table of prices
    // Define the prices
	p[0] = n;
	for (int i = 1; i <= n; i++) {
		if (i == 1) p[i] = 2;
		else if (i == n) p[i] = (float)n * 2.5 - 1;
		else p[i] = floor(i * 2.5); // floor is to find the integer not bigger than (i * 2.5)
	}
 
 // The dp implemetnation
	cout << "The dp implemetation: " << endl;
	t = clock();
	int res2 = Memoized_CutRod(p, n);
	t = clock() - t; // Get the running time
	cout << "The optimal revenue is: " << res2 << endl;
	cout << "The time is: " << ((float)t / CLOCKS_PER_SEC) * 1000000 << " us" << endl; // Output the time
 
	// The recursive implemetnation
	cout << endl << "The recursive implemetation: " << endl;
	t = clock();
	int res1 = Recursive_CutRod(p, n);
	t = clock() - t; // Get the running time
	cout << "The optimal revenue is: " << res1 << endl;
	cout << "The time is: " << ((float)t / CLOCKS_PER_SEC) * 1000000 << " us" << endl << endl; // Output the time

	
	delete[]p;
	return 0;
}