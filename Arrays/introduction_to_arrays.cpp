#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // declare
    int number[15];

    // accessing an array
    cout << "Value at 14 index: " << number[14] << endl;

    // cout<<"Value at 20 index: "<<number[20]<<endl;

    // initialising an array
    int second[3] = {3, 7, 11};

    // accessing an element
    cout << "Value at 2 index: " << second[2] << endl;

    int third[15] = {2, 7};

    // print the array
    cout << "Printing the array" << endl;
    printArray(third, 15);

    // initialising all locations with 0
    int fourth[10] = {0};

    // print the array
    cout << "Printing the array" << endl;
    printArray(fourth, 10);

    // initialising all locations with 1 [not possible with below line]
    int fifth[10] = {1};

    // print the array
    cout << "Printing the array" << endl;
    printArray(fifth, 10);
    int fifthSize = sizeof(fifth) / sizeof(int);
    cout << "Size of Fifth is " << fifthSize << endl;


    char ch[5] = {'a', 'b', 'c', 'r', 'p'};
    cout<<ch[3]<<endl;

    double firstDouble[5];
    float firstFloat[6];
    bool firstBool[9];

    cout << "Everything is fine" << endl;
    return 0;
}