## Virtual Tables

how is correct virtual function chosen dynamically at run-time?

OS has address in memory and any call to the function is replaced by a transfer to that memory location.

virtual pointers to vtable 
- table of function pointers to virtual methods 
- every instance of class contains a virtual pointer to the vtable

- each object created have a field for the vptr and data fields of class
- v table contains an entry for each virtual method that points to the location of the method code in memory 

- when adding inheritance, each object has the data field appropriate to its type!
- ie. vptr for Book points to the Book vtable, while vptr for Text points to the Text vtable. 
- each of the vtables has an entry for the virtual isHeavy() method and they point to different locations where each class implementation is stored in memory 

### example 
say code has declared pointer of type (book*), bptr that happens to currently point to Text object when we want to ouput result of bptr->isHeavy()

to call correct virtual method for whatever bptr is pointing to:
1. follow the objects vptr to vtable
2. fetch address for isHeavy method for that class 
3. go to address for that isHeavy method
4. execute the method code at that address 

! Note: all of this happens at run-time. As a result, there is small performance penalty (object of class with more virtual methods will be smaller than similar class with virtual methods)

- vptrs are 8 bytes long, in g++ vptr is first data field in the object 

- information in the object is laid out consecutively 


## Pratice 
- when a subclass overrides a virtual function from base class, the vtable entry for that functionis updated to point to the overriden function's implementation. 


Quesiton: What situation where multiple inheritance could affect the vtable layout
Answer: deadly diamond (ambiguity)
Solution to diamond: virtual base class (when sub classes inherit, they do so virtually)

## Advantages
- flexible 
- easy to add/extend
- pointers more efficent then explicit conditionals 

## Disadvantages 
- memory overhead 
- runtime overhead
- compiler dependency

## Alternatives to VTable 
- function pointers

