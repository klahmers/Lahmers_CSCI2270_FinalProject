#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include <iostream>
struct Workout{
    std::string date;
    std::string exercise;
    int weight;
    int sets;
    int reps;
    Workout *next;
    Workout *prev;
    Workout(){};
    Workout(std::string initDate, std::string initExercise, int initSets, int initWeight, int initReps, Workout *initNext, Workout *initPrev){
        date=initDate;
        exercise=initExercise;
        sets=initSets;
        weight=initWeight;
        reps=initReps;
        next=initNext;
        prev=initPrev;
    }

};
struct PRWorkout{
    std::string exercise;
    int weight;
    PRWorkout *next;
    PRWorkout(){}
    PRWorkout(std::string initExercise, int initWeight, PRWorkout *initNext){
        exercise=initExercise;
        weight=initWeight;
        next=initNext;
    }
};

class FinalProject
{
    public:
        FinalProject();
        ~FinalProject();
        void printMenu();
        void printSubMenu();
        int maxCalc(int reps, int weight);
        void insertExercise(std::string date, std::string exercise, int sets, int weight, int reps);
        void deleteExercise(std::string date);
        void printWorkouts();
        void PR(std::string exercise, int weight);
        void searchPR(std::string exercise);
	bool validDate(std::string date);
        int totalWeightLifted();
        int Big3Index(int squat, int deadlift, int bench, int bodyWeight);
    protected:
    private:
        Workout *head;
        PRWorkout *head1;
};

#endif // FINALPROJECT_H
