#include <iostream>
#include <vector>
 
using namespace std;

class Student {
private:
string firstName;
string lastName;
float gpa;
double gradYear;
double enrollYear;
double enrollSemes;
bool isUndergrad;

public:
//default constructor
Student(){
    firstName = "";
    lastName = "";
    gpa = 0.0;
    gradYear = 0;
    enrollSemes = 0;
    isUndergrad = true;
}

//destructor
virtual ~Student(){}

//getters


//setters
}; 




class ArtStudent: public Student{







};

class PhysicsStudent: public Student{





};


int main(){

vector<ArtStudent *> artStudents;
artStudents.push_back(new ArtStudent);
//artStudents[0]->setName("some","name");
//artStudents[0]->setGPA("3.9");


//outfile = open("student_info.dat", ios::write);
//for(int i=0;i<artStudents.size();i++){
 


//}


}
