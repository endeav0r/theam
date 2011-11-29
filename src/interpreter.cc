#include "interpreter.h"

MathTree * Interpreter :: reduce_numbers (MathTree * mt)
{
    int mask;

    if (mt == NULL)
        return NULL;

    reduce_numbers(mt->g_left());
    reduce_numbers(mt->g_right());
    
    mask = mt->contains();
    
    if ((mask & (1 << MT_VARIABLE)) == 0) {
        mt->s_value(evaluate(mt));
        mt->s_type(MT_NUMBER);
        mt->delete_children();
    }

    return mt;
}

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

std::string Interpreter :: infix_string (MathTree * mt)
{
    std::string result;

    if (mt == NULL)
        return "";

    result = infix_string(mt->g_left());
    
    switch (mt->g_type()) {
    case MT_NUMBER   : result += mt->g_value_string(); break;
    case MT_VARIABLE : result += mt->g_text(); break;
    case MT_ADD      : result += "+"; break;
    case MT_SUB      : result += "-"; break;
    case MT_MUL      : result += "*"; break;
    case MT_DIV      : result += "/"; break;
    }

    result += infix_string(mt->g_right());

    return result;
}
