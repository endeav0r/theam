#include "parser.h"

#include <stack>

MathTree * Parser :: g_mathTree () { return this->mathTree; }

MathTree * Parser :: make_arith_mathTree (Token token)
{
    switch (token.g_type()) {
    case TOK_ADD : return new MathTree(MT_ADD); 
    case TOK_SUB : return new MathTree(MT_SUB);
    case TOK_MUL : return new MathTree(MT_MUL);
    case TOK_DIV : return new MathTree(MT_DIV);
    }
    throw std::string("make_arith_mathTree called with invalid token_type");
    return NULL;
}

MathTree * Parser :: make_literal_mathTree (Token token)
{
    MathTree * mt;
    switch (token.g_type()) {
    case TOK_NUMBER :
        mt = new MathTree(MT_NUMBER);
        mt->s_value(token.to_double());
        return mt;
    }
    throw std::string("make_literal_mathTree called with invalid token");
    return NULL;
}

PostFixParser :: PostFixParser (std::list <Token> tokens)
{
    std::stack <MathTree *> literals;
    std::stack <MathTree *> operators;
    std::list <Token> :: iterator it;
    std::list <Token> :: iterator look_ahead;
    MathTree * mt = NULL;

    for (it = tokens.begin(); it != tokens.end(); it++) {
        look_ahead = it;
        look_ahead++;

        if ((*it).is_arith()) {
            mt = make_arith_mathTree(*it);
            if (literals.size() >= 2) {
                mt->s_right(literals.top());
                literals.pop();
                mt->s_left(literals.top());
                literals.pop();
                operators.push(mt);
            }
            else if (literals.size() == 1) {
                if (operators.size() < 1) 
                    throw std::string("parser error: not enough operators on stack");
                mt->s_right(literals.top());
                literals.pop();
                mt->s_left(operators.top());
                operators.pop();
                operators.push(mt);
            }
            else {
                if (operators.size() < 2)
                    throw std::string("parser error: not enough operators on stack");
                mt->s_right(operators.top());
                operators.pop();
                mt->s_left(operators.top());
                operators.pop();
                operators.push(mt);
            }
        }
        else
            literals.push(make_literal_mathTree(*it));
    }

    if (literals.size() > 0)
        throw std::string("parser error: literals left on the stack");
    if (operators.size() > 1)
        throw std::string("parser error: more than one operator left on the stack");
    if (operators.size() == 0)
        throw std::string("parser error: empty operators stack");

    this->mathTree = operators.top();
    operators.pop();
}
