//Xuebao Zhao
//002108354
#include<iostream>
#include<random>

using namespace std;

void MergeSort(int a[],int p, int r);
void MERGE(int a[], int p, int q, int r);

int main()
{
	int n;//The number of the array
	cout << "Please input the value n: ";
	cin >> n;
	while (n < 2 || n > 50)//Make sure n is in the range
	{
		cout << "Please intput the value n between 1 and 51! Try again: ";
		//Clear then cin
		cin.clear();
		cin.ignore();
		cin >> n;
	}
	//Create the array A
	int* A = new int[n];
	cout << "The array before sort:";
	random_device rd;//Will be used to obtain a seed for the random number engine
	mt19937 gen(rd());//Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> distrib(0, 100);
	for (int i = 0; i < n; i++)
	{
		A[i] = distrib(gen);//Fill the array with random values.
	}
	//Print the array before sort
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "  ";
	}
	cout << endl;
	MergeSort(A, 0, n - 1);//Sort
	cout << "The array after sort:";
	//Print the array after sort
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "  ";
	}
	cout << endl;
	delete[] A;//Free memory
	return 0;
}

void MergeSort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;//Divide the array to two array
		MergeSort(a, p, q);//The left one
		MergeSort(a, q + 1, r);//The right one
		MERGE(a, p, q, r);//Sort the subarray
	}
}

void MERGE(int a[], int p, int q, int r)
{
	if (a[q] <= a[q + 1])//If the array is sorted
	{
		;//DO nothing
	}
	else
	{
		int n1 = q - p + 1;
		int n2 = r - q;
		int i, j;
		int* L = new int[n1 + 1];//Left
		int* R = new int[n2 + 1];//Right
		//Create the left subarray
		for (i = 0; i < n1; i++)
		{
			L[i] = a[p + i];
		}
		//Create the right subarray
		for (j = 0; j < n2; j++)
		{
			R[j] = a[q + j + 1];
		}
		L[n1] = 1000;
		R[n2] = 1000;
		//Resert form the beginning
		i = 0;
		j = 0;
		//Insert the smaller one into array a
		for (int k = p; k <= r; k++)
		{
			//Compare the element of left to the element of right
			if (L[i] <= R[j])
			{
				a[k] = L[i];//Insert into array a
				i++;
			}
			else
			{
				a[k] = R[j];//Insert into array a
				j++;
			}
		}
	}
}