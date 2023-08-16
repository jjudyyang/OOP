#include <iostream>

using namespace std;


//C++ RAII - Resource Acquisition Is Initialization Idion
// states all code which deals with resources should be wrapped 
// in stack allocated objects 
// this results in stack allocated object destructor to be called 
// to prevent any type of garbage or memory leak

// unique_ptrs - indicates ownership
// raw pointer - indicates non ownership 
// moving a unique pointer - transfer of ownership


// problems with normal pointes 
// memory leaks
// dangling pointer: object is deallocated from memory without modifying the value of the pointer_safety

// smart pointer is wrapper class
// over a pointer with operator * and -> overloaded. the objects of smart pointers look like normal pointers. 

// idea: take class with pointer, destructor and overloaded operators. since destructor is automatically called
// when object goes out of scope, the dynamically allocated memory would automatically be deleted

//defination of unique__ptr class. (can also include memory) to get STL unique_ptr definition

template<typename T> class my_unique_ptr {
    T *ptr;
  public:
    explicit my_unique_ptr(T *p):ptr{p}{}
    ~my_unique_ptr() { delete ptr; }
    my_unique_ptr(const my_unique_ptr &) = delete;
    my_unique_ptr &operator=(const my_unique_ptr &) = delete;
    my_unique_ptr(my_unique_ptr &&other):ptr{other.ptr} { other.ptr = nullptr; }
    my_unique_ptr &operator=(my_unique_ptr &&other) {
      std::swap(ptr, other.ptr);
      return *this;
    }
    T &operator*() { return *ptr; }
};



int main() {
  // C++ RAII - Resource Acquisition Is Initialization Idiom
  // RAII states that all code which deals with resources should be wrapped
  //   in stack allocated objects. This results in stack allocated object
  //   destructor to be called and prevent anay type of garbage or leaked memory
  // Smart pointers are basically classes initialized on stack which manage
  //   the creation and deletion of anything heap allocated
  // Smart pointers can be accessed using <memory> header
  
  // 2 different methods to create smart pointers
  my_unique_ptr<int> p{ new int(9) };
  auto r = make_unique<int>(103); 

  cout << *p << endl;
  cout << *r << endl;

  return 0;
}

