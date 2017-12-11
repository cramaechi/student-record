/*------------------------------------------------------------------------
This is the implementation for the class Student. The interface is in the
file student.h.

Author: Chibuikem Amaechi
Email:  cramaechi@me.com
------------------------------------------------------------------------*/
#include<iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "student.h"

using namespace std;

const string Student::getName() const
{
    return name;
}

unsigned int Student::getNumberOfClasses() const
{
    return numClasses;
}        

void Student::setName(const string& aName)
{
    if (aName.empty())
    {
        cout<<"Error: Attempt to pass in empty string"<<endl;
        exit(1);
    }
    name = aName;
}

void Student::input()
{
    cout<<"Enter name: ";
    getline(cin, name);
    cout<<endl;


    unsigned int count = 0;  
    vector<string> temp;
    string course;  

    cout<<"Enter list of courses currently enrolled in (press '-' key to stop): \n\n";
    getline(cin, course); 
    while (course != "-")
    {
        temp.push_back(course);
        getline(cin, course);  
    }
    cout<<endl;

    numClasses = temp.size(); 
    classList = new string[numClasses];
    for (unsigned int i = 0; i < numClasses; i++)
        classList[i] = temp[i];
} 

void Student::output() 
{
    cout<<"Student Name"<<endl;
    cout<<"------------"<<endl;
    cout<<name<<endl<<endl;

    cout<<"Courses"<<endl;
    cout<<"-------"<<endl;
    for (unsigned int i = 0; i < numClasses; i++)
        cout<<classList[i]<<endl; 
}

Student& Student::operator =(const Student& otherStudent)
{
    //Checks if the object on the right of the = operator is equal to the object
    //on the left side. 
    if (numClasses != otherStudent.numClasses)
    {                                          
        delete [] classList;
        classList = new string[otherStudent.numClasses];
    }

    name = otherStudent.name;
    numClasses = otherStudent.numClasses;

    for (unsigned int i = 0; i < numClasses; i++)
        classList[i] = otherStudent.classList[i];

    return *this;
}

void Student::empty()
{
    delete [] classList;
    classList = NULL;
    numClasses = 0; 
}

Student::~Student()
{
    delete [] classList;
} 
