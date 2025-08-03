#include <iostream>
using namespace std;

void reverseString(const char* str) {
    if (str == nullptr) {
        return;
    }
    const char* end = str;
    while (*end != '\0') {
        ++end;
    }
    while (end-- != str) {
        cout << *end;
    }
    cout << endl;
}

int main() {
    char inputString[100];
    cout << "Enter a string: ";
    cin.getline(inputString, 100);

    cout << "Reversed String: ";
    reverseString(inputString);

    return 0;
}
