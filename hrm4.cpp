#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
    string name;
    int age;
    virtual void getdata() {
        cin >> this->name >> this->age;
    }
    virtual void putdata() {
        cout << this->name << " " << this->age << endl;
    }
};

class Professor : public Person{
    private:
    int publications;
    int cur_id;
    static int id;
    
    public:
    Professor() {
        this->cur_id = ++id;
    }
    
    void getdata(){
        cin >> this->name >> this->age >> this->publications;
    }
    
    void putdata(){
        cout << this->name << " " << this->age << " " << this->publications << " " << this->cur_id << endl;
    }
};
int Professor::id = 0;

class Student : public Person{
    private:
    int marks[6];
    int cur_id;
    static int id;
    
    public:
    Student(){
        this->cur_id = ++id;
    }
    
    void getdata(){
        cin >> this->name >> this->age
            >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
    }
    
    void putdata(){
        int sumOfMarks = 0;
        for(int i = 0; i < 6; i++){
           sumOfMarks += marks[i];
        }
        cout << this->name << " " << this->age << " " << this->sumOfMarks << " " << this->cur_id << endl;
    }
};
int Student::id = 0;

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
