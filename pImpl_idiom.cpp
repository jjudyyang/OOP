struct CImpl{
    A a;
    B b;
};
class C{
    unique_ptr<CImpl> pImpl;
        public:
            void f(){
                auto temp = make_unique<CImpl>(*pImpl);
                temp->a.g();
                temp->b.h();
                std::swap(pImpl, temp); // no throw
            }
}

//syntax pratice 
//makeing unique pointer to CImpl class that is the same as pImpl
auto temp = make_unique<CImpl>(*pImpl);

auto temp = make_unique<CImpl>(*pointer that points to class )

//pointer swap operation never throws exception because it is just swap of memory addresses stored on each of the already allocated variables 

//pimple not the best solution if data is map, vector
//making temp copy of everything is inefficient

