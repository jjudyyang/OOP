#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Observer{
    public:
        virtual void notify() = 0;
        virtual ~Observer(){};
};

class Subject{ 
    //vector of observers so subject knows who is subscribed or not
    vector <Observer *> observers;

    public:
        void attach(Observer *ob) { observers.emplace_back(ob);}
        void detach (Observer *ob) {
            for(auto it = observers.begin(); it != observers.end(); ++it){
                if(*it == ob){
                    //if located the observer we want to detach
                    observers.erase(it);
                    break;
                }
            }
        }

        void notifyObservers(){
            for( auto &ob: observers ){
                ob->notify();
            }
        }
        virtual ~Subject()=0;

};

// implementation
Subject::~Subject(){}

class HorseRace: public Subject{

    ifstream in; // reads from file
    string lastWinner;

    public:
        HorseRace(string source): in{source}{}
        bool runRace(){
            return in >> lastWinner ? true : false;
        }
        string getState(){
            return lastWinner;
        }
};

class Better: public Observer{
    //pointer to subject class 
    HorseRace *subject;
    public:
    string name, myHorse;
    Better(HorseRace *hr, string name, string h):  name{name}, myHorse{h}, subject{hr}{
        subject->attach(this);
    }
    ~Better() { subject->detach(this);}

    void notify(){
        string winner = subject->getState();
        if(winner == myHorse){
            cout<< "WIN" << endl;
        }else{
            cout<< "LOSE!" <<endl;
        }
    }
};

int main(){
    HorseRace hr("file.txt");
    Better larry{ &hr, "Larry", "RunsLikeACow"};

    while(hr.runRace()){
        hr.notifyObservers();
    }
}