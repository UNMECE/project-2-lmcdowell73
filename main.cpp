#include <iostream>
#include <vector>
#include <string>
#include <fstream>
 
using namespace std;

class Student {
protected:
string firstName;
string lastName;
double gpa;
double gradYear;
string gradSemester;
double enrollYear;
string enrollSemester;
string degreeLevel; // grad/undergrad 

public:
//default constructor
Student(){
    firstName = "";
    lastName = "";
    gpa = 0.0;
    gradYear = 0;
    gradSemester = "";
    enrollSemester = "";
    degreeLevel = "";
}

//destructor
virtual ~Student(){}

// getters and setters 
void getName(string &first, string &last) const {
    first = firstName;
    last = lastName;
}
void setName(const string &first, const string &last){
    firstName = first;
    lastName = last;
} 

void setGPA(double value) {gpa = value;}
double getGPA()const {return gpa;}

void setGradYear(int year) {gradYear = year;}
double getGradYear() const {return gradYear;}

void setGradSemester(const string &semester) {gradSemester = semester;}
string getGradSemester() const {return gradSemester;}

void setEnrollYear(double year) {enrollYear = year;}
double getEnrollYear() const {return enrollYear;}

void setEnrollSemester(const string &Semester) {enrollSemester = Semester;}
string getEnrollSemester() const {return enrollSemester;}


void setdegreeLevel(const string &Level) { degreeLevel = Level;}
string getdegreeLevel() const {return degreeLevel;}

virtual void print(ostream &os) const {
    os  << "Name: " << firstName << " " << lastName << "\n"
        << "GPA: " << gpa << "\n" 
        << "Graduation Year: " << gradYear << "\n"
        << "Graduation Semester: " << gradSemester << "\n"
        << "Enrolled Year: " << enrollYear << "\n"
        << "Enrolled Semester: " << enrollSemester << "\n"
        << "Degree Level: " << degreeLevel << "\n";
    }
}; 

class ArtStudent: public Student{
private:
string artEmphasis;
public:
ArtStudent(): Student(), artEmphasis(""){}

~ArtStudent()override {}

void setArtEmphasis(const string &emphasis) {
    if (emphasis == "Art Studio" || emphasis == "Art History" || emphasis == "Art Education"){
        artEmphasis = emphasis;
    }else{
        artEmphasis = "unknown";
    }
}

string getArtEmphasis() const {return artEmphasis;}

void print(ostream &os) const override {
    os << "Art Student Info:\n";
    Student::print(os);
    os << "Art Emphasis: " << artEmphasis << "\n";
    os << "---------------------------------\n";
    }
};

class PhysicsStudent: public Student{
private:
string concentration;
public:
PhysicsStudent() : Student(), concentration("") {}
~PhysicsStudent() override {}
void setConcentration(const string &conc) {
    if(conc == "Biophysics" || conc == "Earth and Planetary Sciences"){
        concentration = conc;
    }
}

string getConcentration() const {return concentration;}

void print(ostream &os) const override {
    os << "Physics Student Info:\n";
    Student::print(os);
    os << "Concentration: " << concentration << "\n";
    os << "---------------------------------\n";
    }
};


int main(){

vector<ArtStudent *> artStudents;
vector<PhysicsStudent *> PhysicsStudents;

//art students
for(int i=0; i < 5; i++){
    ArtStudent* artStudent = new ArtStudent;
    artStudent->setName("Art", "Student " + to_string(i + 1));
    artStudent->setGPA(3.5 + .063113 * i);
    artStudent->setGradYear(2025 + i);
    artStudent->setGradSemester("Spring");
    artStudent->setEnrollYear(2021);
    artStudent->setEnrollSemester("Fall");
    artStudent->setdegreeLevel("Undergrad");

    if(i % 2 == 0){
        artStudent->setdegreeLevel("Undergrad");
    }else{
        artStudent->setdegreeLevel("Graduate");
    }

    if(i % 3){
        artStudent->setArtEmphasis("Art Studio");
    }else if(i % 3 == 1){
        artStudent->setArtEmphasis("Art History");
    }else{
        artStudent->setArtEmphasis("Art Education");
    }

    artStudents.push_back(artStudent);
}

for(int i=0; i < 5; i++){
    PhysicsStudent* physicsStudent = new PhysicsStudent;
    physicsStudent->setName("Physics", "Student" + to_string(i+1));
    physicsStudent->setGPA(4.1 + .01 * i);
    physicsStudent->setGradYear(2025 + i);
    physicsStudent->setGradSemester("Spring");
    physicsStudent->setEnrollYear(2019);
    physicsStudent->setEnrollSemester("Fall");
    if(i % 2 == 0){
        physicsStudent->setdegreeLevel("Undergrad");
    }else{
        physicsStudent->setdegreeLevel("Graduate");
    }

    if(i % 2 == 0.0){
        physicsStudent->setConcentration("Biophysics");
    }else{
        physicsStudent->setConcentration("Earth and Planetary Sciences");
    }
    PhysicsStudents.push_back(physicsStudent);
}

ofstream outfile("student_info.dat");
if(!outfile){
    cout << "Error opening file." << endl;
}

outfile << "Art Students:\n";
for(const auto &student : artStudents){
    student->print(outfile);
}

outfile << "\nPhysics Students:\n";
for(const auto &student : PhysicsStudents){
    student->print(outfile);
}

outfile.close();

for(auto student: artStudents){
    delete student;
}

for(auto student: PhysicsStudents){
    delete student;
}

cout << "Information written to Student_info.dat" << endl;
cout << "rizz"<< endl;
return 0;
}