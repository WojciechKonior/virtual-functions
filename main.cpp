#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a = 0;
int b = 0;

class Person
{
protected:
    string name;
    int age;
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person
{
    int publications, cur_id;
public:
    Professor(){}
    void getdata(){
        cur_id = ++a;
        cin >> name >> age >> publications;

    }
    void putdata(){
        cout << name << " ";
        cout << age << " ";
        cout << publications << " ";
        cout << cur_id << "\n";
    }
};

class Student : public Person
{
    int marks[6], cur_id;
public:
    Student(){}
    void getdata(){
        cur_id = ++b;
        cin >> name >> age;
        for(int i = 0; i<6; i++) cin >> marks[i];

    }
    void putdata(){
        long long result = 0;
        for(int i = 0; i<6; i++) result += marks[i];
        cout << name << " ";
        cout << age << " ";
        cout << result << " ";
        cout << cur_id << "\n";
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
