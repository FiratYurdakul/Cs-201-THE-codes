//
//  the.cpp
//  firaty_the5
//
//  Created by Fırat Yurdakul on 6.06.2022.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include "student.h"

using namespace std;

Student::Student(){
    firstName = "";
    lastName = "";
    ID ="";
    points = 0;

    midtermWeight = 0;
    finalWeight = 0;
    hwWeight = 0;

    
}


void Student::setId(string input){
    ID = input;
}

string Student::getId() const {
    return ID;
}

void Student::setName(string fullname){
    int lenght = fullname.length();
    int num = fullname.rfind(" ");
    firstName = fullname.substr(0, num);
    lastName = fullname.substr(num+1, lenght - num-1);
    //rfindla boşluk bulup soyaddan sonrasını firstname yapıcam
}
        
string Student::getFirstName() const{
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

void Student::setPoints(double grade){
    points = grade;
}
double Student::getPoints() const{
    return points;
}
void Student::display(vector<Student>& classroom , int rank){
    cout<<rank<<", "<<classroom[rank-1].ID<<", "<<classroom[rank-1].firstName << " " << classroom[rank-1].lastName<<", "<<classroom[rank-1].points<<endl;
}
void Student::setExamWeights(double a, double b, double c){
    hwWeight = a;
    midtermWeight =  b;
    finalWeight = c;
}
double Student::getGrade(string examname, double exampoint) const {
    double ret;
    if(examname == "***MIDTERM***" ){
        ret = exampoint * midtermWeight;
    }
    else if(examname == "***HOMEWORK***" ){
        ret = exampoint * hwWeight;
    }
    else if(examname == "***FINAL***"){
        ret = exampoint * finalWeight;
    }
    else{
        ret = 0;
    }
    return ret;
}

//hwWeight * (2.0/10.0) + midtermWeight*(1.0/10.0) + finalWeight * (3.0/10.0);
