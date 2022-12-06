//
//  main.cpp
//  The 2
//
//  Created by Fırat Yurdakul on 10.04.2022.
//

#include <iostream>
#include <string>
using namespace std;

void dispalyResults(double difference, double total,double weight,double walkMET,double runMET,double cyclingMET,double walkCalorie,double runCalorie,double cycleCalorie){
    cout << "From walking, you burned "<< walkCalorie<<" calories."<<endl;
    cout << "From running, you burned "<< runCalorie<<" calories."<<endl;
    cout << "From cycling, you burned "<< cycleCalorie<<" calories."<<endl;
    cout << "You burned "<<total<<" calories."<<endl;
    
    
    if(difference > 0){
        cout <<"You did not reach your goal by "<<difference<<" calories."<<endl;
        
    double walkingneedminutes = difference / (walkMET * weight / 60);
    cout<<"You need to walk " <<walkingneedminutes<<" minutes more to reach your goal or,"<<endl;
    
    double runneedminutes = difference / (runMET * weight / 60);
    cout<<"You need to run " <<runneedminutes<<" minutes more to reach your goal or,"<<endl;

    double cyclingneedminutes = difference / (cyclingMET * weight / 60);
    cout<<"You need to do cycling " <<cyclingneedminutes<<" minutes more to reach your goal."<<endl;
    }

    else if (difference < 0)
    {
        cout<<"You have surpassed your goal! You can eat something worth "<< -difference <<" calories :)"<<endl;
    }
    else if( difference == 0){
        cout<<"Congratulations! You have reached your goal!"<<endl;
    }
    


}






double calculateMet(double speed,string exercise){
    double met=0;
    if (exercise == "walking"){
        if ( speed >= 4 && speed < 6.5){
            met = 4;}
        else{
            met = 6.5;
            
        }
        }
        
    if (exercise == "running"){
        if ( speed >= 4 && speed < 11){
            met = 9;}
        else{
            met = 12.5;
            
        }
        }
        
    if (exercise == "cycling"){
        if ( speed >= 4 && speed < 20)
            met = 6;
        else if (speed >= 20 && speed < 25){
            met = 8;}
        else{
            met = 10.5;
            
        }
        }
    return met;
}

void computeResults(double weight,double goal,double speedWalk,double speedRun,double speedCycling,double minWalk,double minRun,double minCycling){

    double walkingmet = calculateMet(speedWalk, "walking");
    double runningmet = calculateMet(speedRun, "running" );
    double cyclingmet = calculateMet(speedCycling, "cycling");
    double perminwalkingcalorie_burn = (weight * walkingmet) / 60 ;
    double perminrunningcalorie_burn = (weight * runningmet) / 60 ;
    double permincyclingcaloire_burn = (weight * cyclingmet) / 60 ;
    
    double walkingcalorie_burn = perminwalkingcalorie_burn * minWalk;
    double runningcalorie_burn = perminrunningcalorie_burn * minRun;
    double cyclingcalorie_burn = permincyclingcaloire_burn * minCycling;
    
    //printf(" %lf %lf %lf %lf",&speedCycling,&cyclingcalorie_burn, &cyclingmet, &minCycling);
   
    
    double allcalorie_burn = walkingcalorie_burn + runningcalorie_burn + cyclingcalorie_burn;
    double caloriedif = goal - allcalorie_burn;
    dispalyResults(caloriedif,allcalorie_burn, weight, walkingmet, runningmet, cyclingmet, walkingcalorie_burn, runningcalorie_burn, cyclingcalorie_burn);
    

}
bool inputCheck(double weight,double speed,double minute){
    
    
    if (weight < 30){
        cout <<"Weight out of range!"<<endl;
        return 0;
    }
    else if ((speed < 4) || (speed > 30 ) ){
        
        cout<< "Speed out of range!"<<endl;
        return 0;
        }
    else if ((minute <0) || (minute >2000) ){
        cout << "Minute out of range!"<<endl;
        return 0;
        }

    return 1;
}

    

void getInput(string username){
    double weight,ws, wt,rs, rt, cs, ct, calorie;
    
    cout << "Welcome " << username << ", please enter your weight(kg): ";
    cin >> weight;
    cout <<username << ", please enter speed(km/h) and minutes spent in a week for the activities below."<<endl;
    cout <<"Walking: ";
    cin >> ws >> wt;
    cout <<"Running: ";
    cin >> rs >>rt ;
    cout <<"Cycling: ";
    cin >> cs >>ct ;
    cout <<username << ", please enter your weekly calorie burn goal: ";
    cin >>calorie;
    if (inputCheck(weight,ws,wt) == 1 && inputCheck(weight,rs,rt) == 1 && inputCheck(weight,cs,ct) == 1){
        computeResults(weight,calorie,ws,rs,cs,wt,rt,ct);
    }
    
}




int main(){
    string username;
    cout <<"Please enter your name: ";
    cin >> username;
    getInput(username);
    cout<<endl;
    
    cout <<"Please enter your name: ";
    cin >> username;
    getInput(username);
    
    return 0;
}
