#ifndef parser_HEADER
#define parser_HEADER

#include <list>
#include <string>

#include "mathtree.h"
#include "token.h"

class Parser {
    protected :
        MathTree * mathTree;

        MathTree * make_arith_mathTree   (Token token);
        MathTree * make_literal_mathTree (Token token);

    public :
        MathTree * g_mathTree ();
};


class PostFixParser : public Parser {
    public :
        PostFixParser (std::list <Token> tokens);
};
        
#endif
