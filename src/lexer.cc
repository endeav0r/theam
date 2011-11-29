#include "lexer.h"

Lexer :: Lexer (std::string input)
{
    int end;
    int begin;
    std::string tmp;

    begin = 0;
    for (end = 0; end < input.size(); end++) {
        if (    (input[end] == ' ')
             || (input[end] == '\n')
             || (input[end] == '\t')) {
            tokenize(input.substr(begin, end - begin));
            begin = end + 1;
        }
    }
    tokenize(input.substr(begin, end - begin));
}

void Lexer :: tokenize (std::string text)
{
    int i;
    bool valid;

    if (text == "") return;

    if (text.size() == 1) {
        switch (text[0]) {
        case '+' :
            this->tokens.push_back(Token(text, TOK_ADD));
            return;
        case '-' :
            this->tokens.push_back(Token(text, TOK_SUB));
            return;
        case '*' :
            this->tokens.push_back(Token(text, TOK_MUL));
            return;
        case '/' :
            this->tokens.push_back(Token(text, TOK_DIV));
            return;
        }
    }

    valid = true;
    for (i = 0; i < text.size(); i++) {
        if (    (text[i] < '0')
                || (text[i] > '9')) {
            valid = false;
            break;
    }}

    if (valid) {
        this->tokens.push_back(Token(text, TOK_NUMBER));
        return;
    }
    
    throw std::string("Error parsing invalid token \"") + text + std::string("\"");
}

std::list <Token> Lexer :: g_tokens () { return this->tokens; }
