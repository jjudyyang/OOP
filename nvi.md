## Non-Virtual Interface Idiom & Template Method
used to encapsulate interface of a class and control access to its virtual functions  
- aims to provide a clear and controlled way for dervided classes to extend the behaviour of base class methods wihtout allowing direct access to the virtual functions from outside

- non virtual functions call private virtual functions for performing the actual work.
- making virtual functions private, base class maintains control over how the derived classes can override or extend its behaviour 

legal to have private virtual method 

subclasses can change way turtle is drawn, but can change they way shell is drawn

### NVI Idiom
Role of public virutal method
1. describes an interface to the client using it. pre and post conditions. class invariants (what properties must hold or must be true both before and after the method executes)
2. describes ths subclass interface and specfies the hook. 


Design Decisions 
1. all public methods should be non virtual
2. all virtual methods (expect the destructor) should be private or at least protected 

reasoning: provide control over methods from the very beginning. 

extends the template method design pattern by putting every virtual method inside non-virtual wrapper. 

