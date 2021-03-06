#include "FinalProject.h"
#include <iostream>

using namespace std;

FinalProject::FinalProject()
{
    head=NULL;
    head1=NULL;
}
void FinalProject::printMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Record Workout" << endl;
    cout << "2. Delete Workout" << endl;
    cout << "3. Print All Workouts" << endl;
    cout << "4. Record PR" << endl;
    cout << "5. See Previous PRs" << endl;
    cout << "6. Calculate Other Values" << endl;
    cout << "7. Quit Program" << endl;
    cout << "=====================" << endl;
}
void FinalProject::printSubMenu(){
    cout<<"Other Calculation Options"<<endl;
    cout<<"========================="<<endl;
    cout<<"1. Calculate 1RM"<<endl;
    cout<<"2. Calculate Total Weight Lifted"<<endl;
    cout<<"3. Calculate Big Three Index"<<endl;
    cout<<"========================="<<endl;
}
bool FinalProject::validDate(string date){

	
	unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};

	if(date.length()!= 10){
		return false;
	}
	
	if(date[2]!= '/' && date[5] !='/'){
		return false;
	}
	
	for(int i = 0; i < date.length(); ++i){
		if(i != 2 && i != 5 ){
			if( ((int) date[i] - '0') > 10 ){
				return false;
			}
		}
	}
	
	int month = ((int) date[0] - '0') *10+ ((int) date[1] - '0'); 
	//cout <<"month = " << month << endl;//DEBUG purposes
	int day = ((int) date[3] - '0') *10 + ((int) date[4] - '0') ;
	//cout << "day = "<< day << endl;//DEBUG purposes
	int year=((int) date[6] - '0')*1000 + ((int) date[7] - '0') *100 + ((int) date[8] - '0') *10+((int) date[9] - '0') ;
	//cout << "year = " << year << endl;//DEBUG purposes

	if( month == 0 || month > 12 || day == 0|| year == 0 ){
		return false;
	}
	
	if (day>monthlen[month-1]){
		return false;
	}
	return true;


}
void FinalProject::insertExercise(string date, string exercise, int sets, int weight, int reps){
    if(head==NULL){
        head=new Workout(date, exercise, sets, weight, reps, NULL, NULL);
    }
    else{
        Workout *tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        Workout *w=new Workout(date, exercise, sets, weight, reps, NULL, NULL);
        tmp->next=w;
        w->prev=tmp;
    }
}
void FinalProject::deleteExercise(string date){//delete node
    Workout *tmpExercise = NULL;
   Workout *searchExercise = head;
    bool found = false;
    while(!found && searchExercise != NULL){
        if(searchExercise->date == date)
            found = true;
        else
            searchExercise = searchExercise->next;
    }
    if(found == true){
        if(searchExercise == head){
            tmpExercise = head;
            head = head->next;
            delete tmpExercise;
        }
        else if(searchExercise->next==NULL){
            searchExercise->prev->next=NULL;
            delete searchExercise;
        }
        else{
            searchExercise->prev->next = searchExercise->next;
            searchExercise->next->prev = searchExercise->prev;
            delete searchExercise;
        }
    }
    else
        cout<<"No workouts found for "<<date<<endl;
}
void FinalProject::printWorkouts(){
    Workout *tmp=head;
    while(tmp!=NULL){
        cout<<"Date: "<<tmp->date<<", Exercise: "<<tmp->exercise<<", Sets/Reps/Weight: "<<tmp->sets<<"/"<<tmp->reps<<"/"<<tmp->weight<<endl;
        tmp=tmp->next;
    }
    if(head==NULL){
        cout<<"No workouts to print"<<endl;
    }
}
void FinalProject::PR(string exercise, int weight){//need to fix
    if(head1==NULL){
        head1=new PRWorkout(exercise, weight, NULL);
    }
    else{
        bool found=false;
        PRWorkout *tmp=head1;
        while(!found && tmp->next!=NULL){
            if(tmp->exercise==exercise){
                found=true;
                if(tmp->weight<weight)
                    tmp->weight=weight;
            }
            tmp=tmp->next;
        }
        if(tmp->exercise==exercise){
            found=true;
            if(tmp->weight<weight)
                tmp->weight=weight;
            }
        if(found==false){
            PRWorkout *pr=new PRWorkout(exercise, weight, NULL);
            tmp->next=pr;
        }
    }
}
void FinalProject::searchPR(string exercise){
    PRWorkout *tmp=head1;
    if(head1==NULL)
        cout<<"No Previous PRs"<<endl;
    while(tmp!=NULL){
        if(tmp->exercise==exercise){
            cout<<"Your PR for "<<exercise<<" is "<<tmp->weight<<endl;
        }
        tmp=tmp->next;
    }
}

int FinalProject::maxCalc(int reps, int weight){
    int Max;
    Max=weight*reps*.0333+weight;
    return Max;
}

int FinalProject::totalWeightLifted(){
    Workout *tmp=head;
    int total=0;
    while(tmp!=NULL){
        total=total+(tmp->sets*tmp->reps*tmp->weight);
        tmp=tmp->next;
    }
    return total;
}
int FinalProject::Big3Index(int squat, int deadlift, int bench, int bodyWeight){
    int index;
    index=(squat+deadlift+bench)/bodyWeight;
    return index;
}
FinalProject::~FinalProject()
{

}
