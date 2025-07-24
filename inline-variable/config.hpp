#pragma once
#include<string>

//inline variables acts like global variables and avoid multiple definition conflicts when including in cpp files
//ODR (one definition rule) errors can be avoided by inline variables, its not same as inline functions which just copies the code in line where its called.
inline int  global_counter   = 0;            // namespace-scope
struct Foo {
    inline static std::string tag = "Foo";   // class-scope
};

