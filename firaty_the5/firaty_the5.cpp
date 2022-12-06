//
//  main.cpp
//  firaty_the5
//
//  Created by Fırat Yurdakul on 6.06.2022.
//

#include <iostream>
#include <string>
#include "student.h"
#include <fstream>
#include <sstream>

using namespace std;


void SelectSort(vector<Student> & a){
// pre: a contains a.size() elements
// post: elements of a are sorted in non-decreasing order
    int j, k, minIndex, numElts = a.size();
    Student temp;
    for(k=0; k < numElts - 1; k++){
        minIndex = k;             // minimal element index
        for(j=k+1; j < numElts; j++)
            if (a[j].getPoints() > a[minIndex].getPoints() )
               minIndex = j;     // new min, store index
        temp = a[k];
        a[k] = a[minIndex];
        a[minIndex] = temp;
        
        
        
        
        
    }
}


void Sameresult(vector<Student> & classroom){
    
    int k, numvec = classroom.size(), k2 = 1;
    Student  temp_student;
    for(k=0; k < numvec-1; ){
        if(classroom[k].getPoints() == classroom[k2].getPoints() ){
            if(classroom[k].getLastName() > classroom[k2].getLastName()){
                temp_student = classroom[k];
                classroom[k] = classroom[k2];
                classroom[k2] = temp_student;
                
                
                
            }
            
            k++; k2++;
        }
        else{
            k++; k2++;
        }
    }
    
    
    
}







int main (){
    string filename_results, filename_names;
        
    ifstream student_grades;
    ifstream student_names;

    cout << "Please enter a filename for Students Grades Results: ";
    cin >> filename_results;
    
    student_grades.open(filename_results.c_str());
        
    if(student_grades.fail()){
        cout << "Can not find the requested file. Terminating application ..."<<endl;
        return 0;
    }
    
    cout << "Please enter a filename for Students Names: ";
    cin >> filename_names;
    
    student_names.open(filename_names.c_str());
    
    if(student_names.fail()){
        cout << "Can not find the requested file. Terminating application ..."<<endl;
        return 0;
    }
    
    string a;
    int numid, linelength;
    vector<Student> classroom;
    double newgrade;
    while(getline(student_names,a)){
        string nameidline, id, name;
        Student talebe;
        
        linelength = a.length();
        numid = a.find(" ");
        id = a.substr(0, numid);
        name = a.substr(numid + 1, linelength - numid -1);
        talebe.setId(id);
        talebe.setName(name);
        talebe.setExamWeights(0.1, 0.2, 0.3);
        classroom.push_back(talebe);
    }
    
    
    string s, idgrade, examname;
    double grade;
    while (getline(student_grades,s)){

        
            
        if(s == "***HOMEWORK***"){ examname = "***HOMEWORK***";}
        else if(s == "***FINAL***"){  examname = "***FINAL***";}
        else if(s == "***MIDTERM***"){  examname = "***MIDTERM***";}
        else if (s==""){  examname = "no"; }
        
        else{
            istringstream input(s);
            
            input >> idgrade ;
                
            Student talebe;
            

            if(examname == "***HOMEWORK***" ){
                
                int b = -1;
                for(int a = 0; a < classroom.size(); ){
                    b++;
                    if(classroom[b].getId() == idgrade ){
                        a = (int)classroom.size();
                    }
                    else{
                        a++;
                    }
                }
                if(classroom[b].getId() == idgrade ){
                input >> grade;
                
                
                    newgrade = classroom[b].getPoints() + classroom[b].getGrade(examname, grade);
                    
                    classroom[b].setPoints(newgrade);
                    //if(classroom[b].getId() == "00009568")
                        //cout<< classroom[b].getPoints() << endl;
                }

                
            }
        
            if(examname == "***MIDTERM***" ){
                int b = -1;
                for(int a = 0; a < classroom.size(); ){
                    b++;
                    if(classroom[b].getId() == idgrade ){
                        a = (int)classroom.size();
                    }
                    else{
                        a++;
                    }
                }
                if(classroom[b].getId() == idgrade ){
                    input >> grade;
                    
                    newgrade = classroom[b].getPoints() + classroom[b].getGrade(examname, grade);
                   
                    classroom[b].setPoints(newgrade);
                    
                    
                }
            }
            
            if(examname == "***FINAL***" ){
                int b = -1;
                for(int a = 0; a < classroom.size(); ){
                    b++;
                    if(classroom[b].getId() == idgrade ){
                        a = (int)classroom.size();
                    }
                    else{
                        a++;
                    }
                }
                 
                if(classroom[b].getId() == idgrade ){
                input >> grade;
               
                    newgrade = classroom[b].getPoints() + classroom[b].getGrade(examname, grade);
                    classroom[b].setPoints(newgrade);
                }
            }
            newgrade = 0;
        }
    }
    
    
    
    
    double ab = 0,adad = 0;
    for(int z=0; z <classroom.size(); ){
        if(classroom[z].getPoints() == 0){
            ab++;
            z++;
        }
        else{
            z++;
        }
        
    }

    
    
    SelectSort(classroom);
    Sameresult(classroom);
    Student display;
    
    /*for(int rank = 1; rank <= classroom.size();rank++ ){
        cout<<rank<<", "<<classroom[rank-1].getId()<<", "<<classroom[rank-1].getFirstName() << " " << classroom[rank-1].getLastName()<<", "<<classroom[rank-1].getPoints()<<endl;
    }*/
        
    
    
    while(adad == 0){
        int rank;
        cout<< "Enter the rank you want to query (enter 0 to exit): ";
        cin>> rank;
        if(rank == 0){
            cout<<"Exiting..."<<endl;
            return 0;
            }
        else if(rank< 0 || rank > classroom.size()-ab ){
            cout<<"Rank needs to be greater than 0 and smaller than "<< classroom.size()-(ab-1)<< "!"<<endl;
            }
        else{
            display.display(classroom, rank);
            }
    }
    
    
    
    
    return 0;
    
}

