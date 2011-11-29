#ifndef lexer_HEADER
#define lexer_HEADER

#include <string>
#include <list>

#include "token.h"

class Lexer {
    private :
        std::list <Token> tokens;
        
        void tokenize (std::string text);
    public :
        Lexer (std::string input);

        std::list <Token> g_tokens ();
};

#endif
