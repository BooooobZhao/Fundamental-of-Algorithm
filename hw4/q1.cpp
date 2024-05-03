// Xuebao Zhao
// 002108354
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <chrono>

using namespace std;

void reinitialize(int arr1[], int arr2[]);		 // Re‐initialize copies from BST, AVG, and WST
void insertion_sort(int arr[], int n);			 // Insertion Sort
void max_heapify(int arr[], int start, int end); // Build max heap
void heap_sort(int arr[], int n);				 // Heap Sort
int paritition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high); // Quick sort
void check(int arr[], int n);				   // Check whether the array is sorted

int moves = 0; // Number of moves
int comps = 0; // Number of comparison

int main()
{
	int BST[1000], AVG[1000], WST[1000];
	int tBST[1000], tAVG[1000], tWST[1000];
	int n = 1000;
	srand(time(NULL)); // Call this only once at the beginning to
					   // allow rand() to generate a different
					   // succession of random value
	for (int i = 0; i < n; i++)
	{
		BST[i] = i * 10;		  // 1000 integers already sorted in ascending order
		WST[i] = 10000 - i * 10;  // 1000 randomly generated integers between 0 and 100,000
		AVG[i] = rand() % 100000; // 1000 integers sorted in descending order
	}

	ofstream outf;		   // File operation
	outf.open("sort.txt"); // Open sort.txt
	if (outf.fail())
	{
		cerr << "Error: Could not open the file\n";
		exit(1);
	}
	// Insertion Sort
	// Reinitialize
	reinitialize(BST, tBST);
	reinitialize(AVG, tAVG);
	reinitialize(WST, tWST);
	// Initialize variables to zero
	moves = 0;
	comps = 0;
	insertion_sort(tBST, n);
	check(tBST, n);
	// Write into file
	outf << "Moves of BST by using Insertion Sort: " << moves << endl;
	outf << "Comps of BST by using Insertion Sort: " << comps << endl;

	// Initialize variables to zero
	moves = 0;
	comps = 0;
	insertion_sort(tAVG, n);
	check(tAVG, n);
	// Write into file
	outf << "Moves of AVG by using Insertion Sort: " << moves << endl;
	outf << "Comps of AVG by using Insertion Sort: " << comps << endl;

	// Initialize variables to zero
	moves = 0;
	comps = 0;
	insertion_sort(tWST, n);
	check(tWST, n);
	// Write into file
	outf << "Moves of WST by using Insertion Sort: " << moves << endl;
	outf << "Comps of WST by using Insertion Sort: " << comps << endl;

	// Heap
	reinitialize(BST, tBST);
	reinitialize(AVG, tAVG);
	reinitialize(WST, tWST);
	// Initialize variables to zero
	moves = 0;
	comps = 0;
	heap_sort(tBST, n);
	check(tBST, n);
	// Write into file
	outf << "Moves of BST by using Heap Sort: " << moves << endl;
	outf << "Comps of BST by using Heap Sort: " << comps << endl;

	// Initialize variables to zero
	moves = 0;
	comps = 0;
	heap_sort(tAVG, n);
	check(tAVG, n);
	// Write into file
	outf << "Moves of AVG by using Heap Sort: " << moves << endl;
	outf << "Comps of AVG by using Heap Sort: " << comps << endl;

	// Initialize variables to zero
	moves = 0;
	comps = 0;
	heap_sort(tWST, n);
	check(tWST, n);
	// Write into file
	outf << "Moves of WST by using Heap Sort: " << moves << endl;
	outf << "Comps of WST by using Heap Sort: " << comps << endl;

	// Quick Sort
	reinitialize(BST, tBST);
	reinitialize(AVG, tAVG);
	reinitialize(WST, tWST);
	// Initialize variables to zero
	moves = 0;
	comps = 0;
	quick_sort(tBST, 0, n - 1);
	check(tBST, n);
	// Write into file
	outf << "Moves of BST by using Quick Sort: " << moves << endl;
	outf << "Comps of BST by using Quick Sort: " << comps << endl;

	// Initialize variables to zero
	moves = 0;
	comps = 0;
	quick_sort(tAVG, 0, n - 1);
	check(tAVG, n);
	// Write into file
	outf << "Moves of AVG by using Quick Sort: " << moves << endl;
	outf << "Comps of AVG by using Quick Sort: " << comps << endl;

	// Initialize variables to zero
	moves = 0;
	comps = 0;
	quick_sort(tWST, 0, n - 1);
	check(tWST, n);
	// Write into file
	outf << "Moves of WST by using Quick Sort: " << moves << endl;
	outf << "Comps of WST by using Quick Sort: " << comps;

	outf.close();
	return 0;
}

// Re‐initialize copies from BST, AVG, and WST
void reinitialize(int arr1[], int arr2[])
{
	for (int i = 0; i < 1000; i++)
	{
		arr2[i] = arr1[i];
	}
}

// Insertion Sort
void insertion_sort(int arr[], int n)
{
	int key, pre;
	for (int i = 1; i < n; i++)
	{ // n-1 parameters needs to move, move arr[i] in each loop
		key = arr[i];
		pre = i - 1;
		while (pre >= 0 && arr[pre] > key)
		{ // Find the position to insert
			arr[pre + 1] = arr[pre];
			moves++;
			comps++;
			pre--; // Move forward
		}
		comps++;
		if (pre + 1 < i)
		{ // Do not change with itself
			moves++;
			arr[pre + 1] = key; // Move the key to the correct position
		}
	}
}

// Heap Sort
void max_heapify(int arr[], int start, int end)
{
	int dad = start;	   // Parent note
	int son = dad * 2 + 1; // Son note
	while (son <= end)
	{ // Compare when son in the range
		if (son + 1 <= end)
		{
			if (arr[son] < arr[son + 1]) // Choose the greater son
				son++;
			comps++;
		}
		comps++;
		if (arr[dad] > arr[son]) // Finish if parent greater than son
			return;
		else
		{ // Exchane son and parent and move on to the grandson
			swap(arr[dad], arr[son]);
			moves = moves + 3;
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int n)
{
	// Build the max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, n - 1);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]); // Move the sorted number to the back
		moves = moves + 3;
		max_heapify(arr, 0, i - 1);
	}
}

// Quick Sort
int paritition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	int temp, j;
	for (j = low; j < high; j++)
	{ // Start from the beginning
		comps++;
		if (arr[j] <= pivot)
		{
			i++; // Move to the change position
			if (i != j)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				moves = moves + 3;
			}
		}
	}
	if (high != i + 1)
	{ // Put the pivot into its position
		temp = arr[high];
		arr[high] = arr[i + 1];
		arr[i + 1] = temp;
		moves = moves + 3;
	}
	return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = paritition(arr, low, high);
		quick_sort(arr, low, pivot - 1);  // Left
		quick_sort(arr, pivot + 1, high); // Right
	}
}

// Check whether the array is sorted
void check(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{ // Compare with the i+1 element
			cout << "The array is not sorted!" << endl;
			return;
		}
	}
	cout << "The array is sorted!" << endl;
}