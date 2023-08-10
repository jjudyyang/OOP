#include <iostream>
using namespace std;

class Turtle{
    public:
        void draw(){
            drawHead();
            drawShell();
            drawFeet();
        }
    private:
        void drawHead(){
            cout<<"Turtle Head"<<endl;
        }
        void drawFeet(){
            cout<<"Turtle Head"<<endl;
        }
        virtual void drawShell() = 0; // pure virtual, subclasses can customize
};

class RedTurtle: public Turtle{
    void drawShell() override{
        cout << "Turtle Red Shell" <<endl;
    }
};

class GreenTurtle: public Turtle{
    void drawShell() override{
        cout << "Turtle Green Shell" <<endl;
    }
};

//Subclasses can choose the way some parts are drawn, but not all parts
// this NVI (non virutal interface) idiom. NVI idiom is to make virtual methods private, and create accessors
// to them as public methods 

int main(){
    GreenTurtle gt;
    gt.draw();

    cout << endl;

    RedTurtle rt;
    rt.draw();

    return 0;
    
}

