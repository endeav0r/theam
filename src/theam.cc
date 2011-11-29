#include <list>
#include <iostream>
#include <string>

#include "interpreter.h"
#include "lexer.h"
#include "parser.h"
#include "token.h"

#define DEBUG 0

void debug_tokens (std::list <Token> tokens)
{
    std::list <Token> :: iterator it;

    for (it = tokens.begin(); it != tokens.end(); it++) {
        std::cout << (*it).g_text() << "\n";
    }
}


int main (int argc, char * argv[])
{
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " equation\n";
        return 0;
    }

    try {
        Lexer lexer(argv[1]);
        #if DEBUG == 1
            debug_tokens(lexer.g_tokens());
        #endif
        PostFixParser parser(lexer.g_tokens());
        Interpreter in;
        std::cout << "result: " << in.infix_string(in.reduce_numbers(parser.g_mathTree())) << "\n";
    }
    catch (std::string e) {
        std::cout << e << "\n";
        return 0;
    }

    return 0;
}
