#include "interpreter.h"

#include <string>

double Interpreter :: evaluate (MathTree * mt)
{
    switch (mt->g_type()) {
    case MT_NUMBER :
        return mt->g_value();
    case MT_ADD :
        return evaluate(mt->g_left()) + evaluate(mt->g_right());
    case MT_SUB :
        return evaluate(mt->g_left()) - evaluate(mt->g_right());
    case MT_MUL :
        return evaluate(mt->g_left()) * evaluate(mt->g_right());
    case MT_DIV :
        return evaluate(mt->g_left()) / evaluate(mt->g_right());
    }

    throw std::string("interpreter error: invalid type");
    return 0;
}
