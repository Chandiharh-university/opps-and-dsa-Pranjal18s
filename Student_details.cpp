/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class Student {
private:
    string name; 
    int age;
public:
    void setDetails(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
    }
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Student student1; 
    student1.setDetails("Pranjal Singh", 21);
    cout << "Student Details:" << endl;
    student1.displayDetails();

    return 0;
}
