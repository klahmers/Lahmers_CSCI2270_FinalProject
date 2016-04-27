#include <iostream>
#include <sstream>
#include "FinalProject.h"
using namespace std;

int main()
{
    FinalProject Go;
    Go.printMenu();
    int x;
    cin >> x;
    while(x>0 && x<7){//insert
        if(x==1){
            string Date, Exercise;
            int Sets, Weight, Reps;
            cout<<"Enter workout date (MM/DD/YYYY): ";
            cin>>Date;
            cout<<"Enter exercise: ";
            cin.ignore();
            getline(cin, Exercise);
            stringstream ss(Exercise);
            cout<<"Enter Number of Sets: ";
            cin>>Sets;
            cout<<"Enter weight lifted: ";
            cin>>Weight;
            cout<<"Enter Reps Performed: ";
            cin>>Reps;
            Go.insertExercise(Date, Exercise, Sets, Weight, Reps);
            Go.printMenu();
            cin.ignore();
            cin>>x;
        }
        else if(x==2){//delete
            string deleteDate;
            cout<<"Enter workout date to delete (MM/DD/YYYY): ";
            cin.ignore();
            cin>>deleteDate;
            Go.deleteExercise(deleteDate);
            Go.printMenu();
            cin>>x;
        }
        else if(x==3){//print
            Go.printWorkouts();
            Go.printMenu();
            cin>>x;
        }
        else if(x==4){//pr
            string PRexercise;
            int PRweight;
            cin.ignore();
            cout<<"Enter PR exercise: "<<endl;
            getline(cin, PRexercise);
            stringstream ss1(PRexercise);
            cout<<"Enter PR weight: "<<endl;
            cin>>PRweight;
            Go.PR(PRexercise, PRweight);
            Go.printMenu();
            cin>>x;
        }
        else if(x==5){//ll PRs
            string prExercise;
            cin.ignore();
            cout<<"Enter exercise: "<<endl;
            getline(cin, prExercise);
            stringstream ss2(prExercise);
            Go.searchPR(prExercise);
            Go.printMenu();
            cin>>x;

        }
        else{//other
            int y;
            Go.printSubMenu();
            cin>>y;
            if(y==1){//1RM
                int reps, weight, liftMax;
                cout<<"Enter weight lifted: ";
                cin>>weight;
                cout<<"Enter reps preformed: ";
                cin>>reps;
                liftMax=Go.maxCalc(reps, weight);
                cout<<"Your 1 rep max is "<<liftMax<<endl;
                Go.printMenu();
                cin>>x;
            }
            else if(y==2){//Total Weight
                int total;
                total=Go.totalWeightLifted();
                cout<<"Total Weight Lifted: "<<total<<endl;
                Go.printMenu();
                cin>>x;
            }
            else if(y==3){
                int squat, deadlift, bench, bodyWeight;
                int totalIndex;
                cout<<"Enter squat 1RM: "<<endl;
                cin>>squat;
                cout<<"Enter deadlift 1RM: "<<endl;
                cin>>deadlift;
                cout<<"Enter bench press 1RM: "<<endl;
                cin>>bench;
                cout<<"Enter bodyWeight: "<<endl;
                cin>>bodyWeight;
                totalIndex=Go.Big3Index(squat, deadlift, bench, bodyWeight);
                cout<<"Your Big 3 Index is about "<<totalIndex<<endl;
                Go.printMenu();
                cin>>x;
            }
        }
    }
    if(x==7)
        cout<<"See you next time!"<<endl;
    return 0;
}
