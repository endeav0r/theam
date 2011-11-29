#include "mathtree.h"

#include <cstdlib>

MathTree :: MathTree (int type)
{
    this->left = NULL;
    this->right = NULL;
    this->value = 0;
    this->type = type;
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

void MathTree :: s_left  (MathTree * mt) { this->left  = mt; }
void MathTree :: s_right (MathTree * mt) { this->right = mt; }
void MathTree :: s_value (double value)  { this->value = value; }

MathTree * MathTree :: g_left   () { return this->left;  }
MathTree * MathTree :: g_right  () { return this->right; }
int        MathTree :: g_type   () { return this->type;  }
double     MathTree :: g_value  () { return this->value; }

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

