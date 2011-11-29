#include "mathtree.h"

#include <cstdlib>
#include <sstream>

MathTree :: MathTree (int type)
{
    this->left = NULL;
    this->right = NULL;
    this->value = 0;
    this->type = type;
    this->text = "";
}

MathTree :: MathTree (int type, std::string text)
{
    this->left = NULL;
    this->right = NULL;
    this->value = 0;
    this->type = type;
    this->text = text;
}

MathTree :: ~MathTree ()
{
    if (this->left != NULL)
        delete this->left;
    if (this->right != NULL)
        delete this->right;
}

void MathTree :: clear_children ()
{
    this->left = NULL;
    this->right = NULL;
}

void MathTree :: delete_children ()
{
    if (this->right != NULL)
        delete this->right;
    if (this->left != NULL)
        delete this->left;
    clear_children();
}

int MathTree :: contains ()
{
    int result;

    result = 1 << this->type;

    if (left != NULL)
        result |= left->contains();
    if (right != NULL)
        result |= right->contains();

    return result;
}

void MathTree :: s_left  (MathTree * mt)    { this->left  = mt; }
void MathTree :: s_right (MathTree * mt)    { this->right = mt; }
void MathTree :: s_value (double value)     { this->value = value; }
void MathTree :: s_text  (std::string text) { this->text = text; }
void MathTree :: s_type  (int type)         { this->type = type; }

MathTree *  MathTree :: g_left   () { return this->left;  }
MathTree *  MathTree :: g_right  () { return this->right; }
int         MathTree :: g_type   () { return this->type;  }
double      MathTree :: g_value  () { return this->value; }
std::string MathTree :: g_text   () { return this->text;  }

std::string MathTree :: g_value_string ()
{
    std::ostringstream result;
    result << this->value;
    return result.str();
}

bool MathTree :: is_arith ()
{
    switch (this->type) {
    case MT_ADD :
    case MT_SUB :
    case MT_MUL :
    case MT_DIV :
        return true;
    }
    return false;
}

