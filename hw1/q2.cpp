//Xuebao Zhao
//002108354
#include<iostream>

using namespace std;

void mirror(int a[], int n);

int main()
{
	//Declare array
	int v[] = { 5,6,7,8,2,1 };
	//Mirror it
	mirror(v, 6);
	//Print array
	for (int i = 0; i < 6; i++)
		cout << v[i] << '\n';
	return 0;
}

//mirror the array
void mirror(int a[], int n)
{
	//Swap for n/2 times
	for (int i = 0; i < n / 2; i++)
	{
		//swap
		int temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}