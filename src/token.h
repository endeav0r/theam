#ifndef token_HEADER
#define token_HEADER

#include <string>

enum {
    TOK_NUMBER,
    TOK_VARIABLE,
    TOK_ADD,
    TOK_SUB,
    TOK_MUL,
    TOK_DIV
};

class Token {
    private :
        std::string text;
        int type;
    public :
        Token (std::string text, int type);

        std::string g_text ();
        int         g_type ();

        bool        is_arith ();
        
        double      to_double ();
};

#endif
