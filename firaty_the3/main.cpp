//
//  main.cpp
//  firaty_the3
//
//  Created by Fırat Yurdakul on 19.04.2022.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


bool innputchecker (string choice, string searching_part){
    cout<< "Enter your choice and string: ";
    int i = 1;
    for (; i > 2 ;){
    
    cin>>choice;
    
    if (choice == "1" || choice == "2" ){
        cin >> searching_part;//taker ()
        if(choice == "2"){
            cout <<"Wrong input format! Try again.";
            i = 2;
            return 0;
            
        }
        else{
            i = 2;
            return 1;
        }
        i = 2;
    }
    else if (choice == "3"){
        cout<<"See you!";
        i = 2;
    }
    else{
        cout<<"Choice can be 1, 2 or 3! Try again."<<endl;
        return 0;
    }
    }
    }

bool taker (string choice, string searching_part ){
    
    if (choice == "1"){
        cin>>searching_part;
        
        for(int i = 0; i < searching_part.length();  i++){
            
            if ((searching_part.at(i) > 97) && ( searching_part.at(i)<127)){
                return 0;
            }
            else{
                cout<<"Wrong input format! Try again.";

                return 1;
            }
}
}
}
        
bool searcher (string searching_subpart){
    
    for(int i = 0; i < searching_subpart.length();  i++){
        
        if (((searching_subpart.at(i) >= 97) && ( searching_subpart.at(i)<=122)) || searching_subpart.at(i) == 63){
            return 0;
        

        }
        else{
            cout<<"Wrong input format! Try again.";

            return 1;
        }
}
}
    
    
    
    
double calculater(string subpart, string searching_part){
    

double place_number = searching_part.find(subpart);
double lengh_subpart = subpart.length();
int    i = 1;
    for( ; i >; i++){
        
        cout<< subpart<< "found at "<<place_number;
        
    }
        
    
    
    cout<<"has been found at index";




}
int main (){
    string subpart = "ing";
    string searching_part = "changingthesourcestring";
 //   string choice
    double place_number = searching_part.find(subpart);
    double lengh_subpart = subpart.length();
    int    i = 1;
        for( ; i >; i++){
            
            cout<< subpart<< "found at "<<place_number;
    
            retrun 0;
}
//firat
//str.at(0) -> 'f'
