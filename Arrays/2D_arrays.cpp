#include <bits/stdc++.h>

using namespace std;

bool isPresent(int arr[][3], int target, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (arr[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;
}

// to print row-wise sum
void printSum(int arr[][3], int row, int column) {
    cout << "Printing sum ->" << endl;
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < column; j++) {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
}

int largestRowSum(int arr[][3], int row, int column) {
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < column; j++) {
            sum += arr[i][j];
        }
        if (sum > maxi) {
            maxi = sum;
            rowIndex = row;
        }
    }
    cout << "The maximum sum is " << maxi << endl;
    return rowIndex;
}

int main() {
    // create 2D array
    int arr[3][3];
    // int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // int arr[3][4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};

    // taking input -> row wise
    cout << "Enter the elements" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cin >> arr[row][column];
        }
    }

    /*
    // taking input -> column wise
    for (int column = 0; column < 4; column++) {
        for (int row = 0; row < 3; row++) {
            cin >> arr[row][column];
        }
    }
    */

    // print
    cout << "Printing the array" << endl;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << arr[row][column] << " ";
        }
        cout << endl;
    }

    /*
    cout << "Enter the element to search" << endl;
    int target;
    cin >> target;

    if (isPresent(arr, target, 3, 4)) {
        cout << "Element found" << endl;
    } else {
        cout << "Not found" << endl;
    }
    */
    printSum(arr, 3, 3);
    cout << "Max row is at index " << largestRowSum(arr, 3, 3) << endl;

    return 0;
}
