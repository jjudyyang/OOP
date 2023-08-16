## Inheritance 
- creating new classes based on exisitng class
- derived class inherits the attributes and methods of the base class
- code reuse and creation of hierachies of related classes 

## Polymorphism 
- ability of different classes to be treated as instances of a common base class
- allows you to write code that can work with mutiple different classes through shared interface 
- use virtual functions, which are overriden in derived classes to provide specialized implementations 

### We want low coupling and high cohesion

## Coupling 
- (low) modules communicate via function calls
- modules pass structs/arrays back and forth
- modules affect each other's control flow
- modules share global data
- (high) everything is public

High coupling, it because harder to reuse individual modules 

## Cohesion
- (low) arbitrary grouping of unrelated elements
- elements share a common theme but are otherwise unrelated
- elements manipulate state over the lifetime of an object 
- elements pass data to eachother
- (high) elements perform excalty one task

Low cohesion, then code is poorly organized, hard to understand and hard to maintain. 

## Mantras of OOP

### Single Responsibility Principle 

### program to the iterface and not to the implementation

noexcept keyword, function does not throw 

