#ifndef mathtree_HEADER
#define mathtree_HEADER

#include <string>

enum {
    MT_NUMBER,
    MT_VARIABLE,
    MT_ADD,
    MT_SUB,
    MT_MUL,
    MT_DIV
};

class MathTree {
    private :
        MathTree * left;
        MathTree * right;
        std::string text;
        int type;
        double value;

    public :
        MathTree  (int type);
        MathTree  (int type, std::string text);
        ~MathTree ();

        void clear_children  ();
        void delete_children ();

        // returns a masked value with all of the types of this node and
        // all children
        // IE if this tree contains MT_NUMBER <-> MT_ADD <-> MT_NUMBER
        // then the result would be (1 << MT_NUMBER) | (1 << MT_ADD)
        int contains ();
        
        void s_left  (MathTree * mt);
        void s_right (MathTree * mt);
        void s_value (double value);
        void s_type  (int type);
        void s_text  (std::string text);

        MathTree *  g_left         ();
        MathTree *  g_right        ();
        int         g_type         ();
        double      g_value        ();
        std::string g_value_string ();
        std::string g_text         ();
        bool        is_arith       ();
};

#endif
