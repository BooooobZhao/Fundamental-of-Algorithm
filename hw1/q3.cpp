//Xuebao Zhao
//002108354
#include<iostream>

using namespace std;

//Descending sort the array
void Sort(struct StuSco stu[], int n);
//Find the average and median number of the array
void Average(struct StuSco stu[], int n);
//Find the student info who get minimum grade
void Min(struct StuSco stu[], int n);
//Find the student info who get maximum grade
void Max(struct StuSco stu[]);

struct StuSco {
    string Name;//student's name
    int Grade;//student's grade
};

int main()
{
    int num;//number of students

    //Input the number of students
    cout << "Please input the number of students(only a number): ";
    cin >> num;
    while (num < 1)
    {
        cin.clear();//clear the inout
        cin.ignore();
        cout << "Please input the number bigger than 0!" << endl;
        cout << "Please input the number of student(only a number) again: ";
        cin >> num;//Input again
    }
    //Crate the array using dynamic memory
    StuSco* stusco = new StuSco[num];

    //Input the students' info
    for (int i = 0; i < num; i++)
    {
        cout << "Please input the name of student" << i + 1 << ": ";//Name
        cin >> stusco[i].Name;
        cout << "Please input the grade of student" << i + 1 << ": ";//Grade
        cin >> stusco[i].Grade;
        while(cin.fail())//If the input is not an integer, inout again
        {
            cin.clear();
            cin.ignore();
            cout << "Please input a correct number! Please try again!" << endl;//Input again
            cout << "Please input the Grade of student" << i + 1 << ": ";
            cin >> stusco[i].Grade;
        }
        while (stusco[i].Grade < 0 || stusco[i].Grade > 100)//Grade must in the range of 0 to 100
        {
            cin.clear();
            cin.ignore();
            cout << "Please input a number between 0 and 100!" << endl;//Input again 
            cout << "Please input the grade of student" << i + 1 << ": ";
            cin >> stusco[i].Grade;
        }
    }

    Sort(stusco, num);//Descending sort
    Average(stusco, num);//Find the average and median
    Min(stusco, num);//Find minimum grade
    Max(stusco);//Find maximum grade
    delete[] stusco;
    return 0;
}
//Insertion sort
void Sort(struct StuSco stu[], int n)
{
    int key,pre;
    for (int i = 1; i < n; i++)//n-1 parameters needs to move, move stu[i] in each loop
    {
        StuSco key = stu[i];
        pre = i - 1;
        while(pre >= 0 && stu[pre].Grade < key.Grade)//Find the biggest grade
        {
            stu[pre + 1] = stu[pre];
            pre--;
        }
        stu[pre + 1] = key;//move the stu[i] to the correct position
    }

    //Print the students' info after sort
    cout << "name    Grade" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << stu[i].Name << "     " << stu[i].Grade << endl;
    }
}

void Average(struct StuSco stu[], int n)
{
    float ave = 0;
    int medi;
    for (int i = 0; i < n; i++)
    {
        ave += stu[i].Grade;//Sum
    }
    ave = ave / n;
    if (n % 2 == 0)//If the n is even then median eauals to the average of stu[n/2-1] and stu[n/2]
        medi = (stu[n / 2 - 1].Grade + stu[n / 2].Grade) / 2;
    else
        medi = stu[n / 2].Grade;
    //Print the average and median
    cout << "The average grade is: " << ave << endl;
    cout << "The median grade is: " << medi << endl;
}

void Max(struct StuSco stu[])
{
    int i = 0;
    while (stu[i].Grade == stu[0].Grade)//Find all the maximum
    {
        cout << stu[i].Name << " gets the best grade. The grade is: " << stu[i].Grade << endl;
        i++;
    }
}

void Min(struct StuSco stu[], int n)
{
    int i = n - 1;
    while (stu[i].Grade == stu[n - 1].Grade)//Find all the minimum
    {
        cout << stu[i].Name << " gets the worst grade. The grade is: " << stu[i].Grade << endl;
        i--;
    }

}