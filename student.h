/*--------------------------------------------------------------------
This is the header file student.h. This is the interface for the class 
Student. Values of this type store common information about college
student.

Author: Chibukem Amaechi
Email:  cramaechi@me.com
-------------------------------------------------------------------*/
#include <string>
using namespace std;

typedef string* StringPtr;

class Student
{
public:
    Student() :name(""), numClasses(0), classList(NULL) {} 

    Student(string sName) :name(sName) {}

    Student(string sName, unsigned int nClasses) :name(sName), numClasses(nClasses) {}

    const string getName() const; 

    unsigned int getNumberOfClasses() const;

    void setName(const string& aName);

    void input();  // Inputs all relevant student info into the object.

    void output(); // Outputs the students name and course list.  

    void empty();  // Resets number of classes to 0 and empties list.

    Student& operator =(const Student& otherStudent);

    ~Student(); // Destroys the dynamic array of courses.
private:
    string name;
    unsigned int numClasses;
    StringPtr classList;
};
