template<typename T> T min (T x, T y){
    return x < y ? x : y; // if x < y return x, else return 7
}

int f(){
    int x = 1;
    int y = 2; 
    int z = min(x,y); //T = int;  
    char w = min('x', 'y'); //T = char
    auto f = min(1,0, 3.0); //T = double
}