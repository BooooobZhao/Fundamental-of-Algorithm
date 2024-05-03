//Xuebao Zhao
//002108354

#include<iostream>

using namespace std;

//Swap the values of two integer variables using pass‐by‐point
void SwapP(int *a, int *b);
//Swap the values of two integer variables using pass‐by‐reference
void SwapR(int& a, int& b);

int main()
{
    int a = 4;
    int b = 7;
    //Output the original number
    cout << "Original value of a and b:";
    cout << a << " " << b << endl;
    //Swap the values of two integer variables using pass‐by‐point
    SwapP(&a, &b);
    //Output the result of swap using pass‐by‐point
    cout << "Pass by pointer:";
    cout << a << " " << b << endl;

    //Output the original number
    a = 4;
    b = 7;
    cout << "Original value of a and b:";
    cout << a << " " << b << endl;
    //Swap the values of two integer variables using pass‐by‐reference
    SwapR(a, b);
    //Output the result of swap using pass‐by‐reference
    cout << "Pass by reference:";
    cout << a << " " << b << endl;
}

void SwapP(int *a, int *b)
{
    int temp = *a;//Save the value temporarily
    *a = *b;
    *b = temp;
}

void SwapR(int& a, int& b)
{
    int temp = a;//Save the value temporarily
    a = b;
    b = temp;
}