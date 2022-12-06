#ifndef student_h
#define student_h


#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Student{
public:
	Student();
	
	void setId(string);
	string getId() const;
	
	void setName(string);
	string getFirstName() const;
	string getLastName() const;
	
	void setPoints(double);
	double getPoints() const;
	
	
	void display(vector<Student>&, int);

	// Exam Functions

	void setExamWeights(double, double, double);
	double getGrade(string, double) const; 


private:
    string firstName;                     // name of the student (include middle name if exists)
    string lastName;                  // lastname of the student
    string ID;                       // identity number of the student
	double points;

	double midtermWeight; 
	double finalWeight;
	double hwWeight;
};

/*vector<int> -> 1,2,3
Student num1;
student num2;

vector<Student> classroom;
classroom.pus_back(nnum1,num2)
classroom[1].id  */


#endif
