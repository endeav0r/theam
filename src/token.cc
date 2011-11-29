#include "token.h"

#include <sstream>

Token :: Token (std::string text, int type)
{
    this->text = text;
    this->type = type;
}

std::string Token :: g_text () { return this->text; }
int         Token :: g_type () { return this->type; }

bool Token :: is_arith ()
{
    switch (this->type) {
    case TOK_ADD :
    case TOK_SUB :
    case TOK_MUL :
    case TOK_DIV :
        return true;
    }
    return false;
}

double Token :: to_double ()
{
    std::istringstream i(this->text);
    double result;

    if (!(i >> result))
        throw std::string("Bad conversion of ") + this->text + std::string("to double");

    return result;
}
