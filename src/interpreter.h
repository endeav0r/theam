#ifndef interpreter_HEADER
#define interpreter_HEADER

#include <string>

#include "mathtree.h"

class Interpreter {
    private :
    public :
        double      evaluate       (MathTree * mt);
        MathTree *  reduce_numbers (MathTree * mt);
        std::string infix_string   (MathTree * mt);
};

#endif
