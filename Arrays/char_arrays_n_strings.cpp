#include <bits/stdc++.h>

using namespace std;

char getMaxOccCharacter(string s) {
    int arr[26] = {0};

    // creating an array of count of characters
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // lowercase
        int number = 0;
        if (ch >= 'a' && ch <= 'z') {
            number = ch - 'a';
        } else {
            // uppercase
            number = ch - 'A';
        }
        arr[number]++;

        // find maximum occuring character
        int maxi = -1, ans = 0;
        for (int i = 0; i < 26; i++) {
            if (maxi < arr[i]) {
                ans = i;
                maxi = arr[i];
            }
        }
        char finalAnswer = 'a' + ans;
        return finalAnswer;
    }
}

void reverse(char name[], int n) {
    int s = 0;
    int e = n - 1;
    while (s < e) {
        swap(name[s++], name[e--]);
    }
}

bool isPalindrome(char name[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        if (name[s] != name[e]) {
            return 0;
        } else {
            s++;
            e--;
        }
    }
    return 1;
}

int getLength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char name[20];
    cout << "Enter your name" << endl;
    cin >> name;
    name[2] = '\0';

    cout << "Your name is ";
    cout << name << endl;

    // int len = getLength(name);
    // cout << "Length: " << len << endl;

    // reverse(name, len);
    // cout << "Your name is ";
    // cout << name << endl;

    // bool isPal = isPalindrome(name, len);
    // if (isPal) {
    //     cout << "It is a palindrome" << endl;
    // }
    // else {
    //     cout << "It is not a palindrome" << endl;
    // }

    // string s;
    // // cin >> s;
    // // use cin.getline function
    // getline(cin, s);

    // cout << getMaxOccCharacter(s);
    return 0;
}