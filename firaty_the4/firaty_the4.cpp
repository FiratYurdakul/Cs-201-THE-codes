//
//  main.cpp
//  firaty_the4
//
//  Created by Fırat Yurdakul on 22.05.2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


void Sameresult(vector<double> & grade, vector<string> & surname, vector<string> & id, vector<string> & name){
    
    int k, numvec = grade.size(), k2 = 1;
    string  temp_surname, temp_name, temp_id;
    for(k=0; k < numvec-1; ){
        if(grade[k] == grade[k2] ){
            if(surname[k] > surname[k2]){
                temp_surname = surname[k];
                surname[k] = surname[k2];
                surname[k2] = temp_surname;
                
                temp_name = name[k];
                name[k] = name[k2];
                name[k2] = temp_name;
                
                temp_id = id[k];
                id[k] = id[k2];
                id[k2] = temp_id;
                
            }
            
            k++; k2++;
        }
        else{
            k++; k2++;
        }
    }
    
    
    
}









void SelectSort(vector<double> & a,vector<string> & b,vector<string> & c,vector<string> & d){
// pre: a contains a.size() elements
// post: elements of a are sorted in non-decreasing order
    int j, k, minIndex, numElts = a.size();
    double temp;
    string tempc,tempd,tempb;
    for(k=0; k < numElts - 1; k++){
        minIndex = k;             // minimal element index
        for(j=k+1; j < numElts; j++)
            if (a[j] > a[minIndex] )
               minIndex = j;     // new min, store index
        temp = a[k];
        a[k] = a[minIndex];
        a[minIndex] = temp;
        
        tempb = b[k];
        b[k] = b[minIndex];
        b[minIndex] = tempb;
        
        tempc = c[k];
        c[k] = c[minIndex];
        c[minIndex] = tempc;
        
        tempd = d[k];
        d[k] = d[minIndex];
        d[minIndex] = tempd;
        
        
        
    }
}










int main() {
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
    
    string s,a,name2,surname2,sid,id2;
    double sgrade = 0;
    //hw = 1 md = 2 final = 3
    vector<string> id;
    vector<double> grade;
    vector<string> name;
    vector<string> surname;
    while(getline(student_names,a)){
        istringstream input(a);
        input >> id2 >>name2 >>surname2;
        id.push_back(id2); name.push_back(name2); surname.push_back(surname2); grade.push_back(0);
        
    }
    
    
    
    string alaca = "";
    
    while (getline(student_grades,s)){
        istringstream input(s);
        input >> sid ;
        
        
        if(s == "***HOMEWORK***") alaca = "***HOMEWORK***";
        if(s == "***FINAL***") alaca = "***FINAL***";
        if(s == "***MIDTERM***") alaca = "***MIDTERM***";
    
        
        if (alaca == "***HOMEWORK***"){
        int b = -1;
        for(int a = 0; a < id.size(); ){
            b++;
            if(id[b] == sid ){
                a = (int)id.size();
            }
            else{
                a++;
            }
        }
        
            input >> sgrade;
            grade[b] = grade[b] + (sgrade*(1.0/10.0));
            
        }
        if (alaca == "***MIDTERM***"){
        int b = -1;
        for(int a = 0; a < id.size(); ){
            b++;
            if(id[b] == sid ){
                a = (int)id.size();
            }
            else{
                a++;
            }
        }
        
            input >> sgrade;
            grade[b] = grade[b] + (sgrade*(2.0/10.0));
            
        }
        
        if (alaca == "***FINAL***"){
        int b = -1;
        for(int a = 0; a < id.size(); ){
            b++;
            if(id[b] == sid ){
                a = (int)id.size();
            }
            else{
                a++;
            }
        }
        
            input >> sgrade;
            grade[b] = grade[b] + (sgrade*(3.0/10.0));
            
        }
            sgrade = 0;
        
    }
    
    double ab = 0,adad = 0;
    for(int z=0; z <id.size(); ){
        if(grade[z] == 0){
            ab++;
            z++;
        }
        else{
            z++;
        }
        
    }
    
    SelectSort(grade,id,name,surname);
    Sameresult(grade, surname, id, name);
    while(adad == 0){
        double rank;
        cout<< "Enter the rank you want to query (enter 0 to exit): ";
        cin>> rank;
        if(rank == 0){
            cout<<"Exiting..."<<endl;
            return 0;
            }
        else if(rank< 0 || rank > id.size()-ab ){
            cout<<"Rank needs to be greater than 0 and smaller than "<< id.size()-(ab-1)<< "!"<<endl;
            }
        else{
            cout<<rank<<", "<<id[rank-1]<<", "<<name[rank-1] << " " << surname[rank-1]<<", "<<grade[rank-1]<<endl;
            }
    }
    
    return 0;
}
