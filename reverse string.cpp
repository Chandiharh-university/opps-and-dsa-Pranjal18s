#include <iostream>
#include <string>
using namespace std;

class StringReverser {
private:
    string str;

public:
    // Constructor to initialize the string
    StringReverser(const string &input) : str(input) {}

    // Method to reverse the string iteratively
    void reverseIterative() {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            swap(str[left], str[right]);
            left++;
            right--;
        }
    }

    // Method to reverse the string recursively
    void reverseRecursive(int left, int right) {
        if (left >= right) {
            return;
        }
        swap(str[left], str[right]);
        reverseRecursive(left + 1, right - 1);
    }

    // Method to display the string
    void display() const {
        cout << "Current String: " << str << endl;
    }

    // Method to reset the string
    void setString(const string &input) {
        str = input;
    }
};

int main() {
    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input);

    // Create an object of StringReverser
    StringReverser reverser(input);

    // Display original string
    reverser.display();

    // Iterative reverse
    reverser.reverseIterative();
    cout << "After Iterative Reverse: ";
    reverser.display();

    // Reset and reverse recursively
    reverser.setString(input);
    reverser.reverseRecursive(0, input.length() - 1);
    cout << "After Recursive Reverse: ";
    reverser.display();

    return 0;
}
