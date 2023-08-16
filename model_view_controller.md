## Model View Controller 

Decoupling: reducing/eliminating interdependencies between different components or modules of system 

We want high cohesion, low coupling
make code reuse easier 

#### Single responsibility principle 
" a class should only have one reason to change "

- seperate program state, presentation logic and control logic 
- possible to modify any one of them without modifying the other two

**Model** : manages application data and its modification. does not know anything about how data is presented to user

**View** : manages interface to present data. (ie text-based interface, graphical interface)

**Controller** : manages interface to modify data. recieves user input and translates it to the actions that operate in the program state stored in model

Implementated via Observer design pattern
Model is subject
View is observer 

if view takes in input, should redirect to Controller

Controller is not responsible for actually making any change in the program state
