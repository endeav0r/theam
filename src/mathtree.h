#ifndef mathtree_HEADER
#define mathtree_HEADER

enum {
    MT_NUMBER,
    MT_ADD,
    MT_SUB,
    MT_MUL,
    MT_DIV
};

class MathTree {
    private :
        MathTree * left;
        MathTree * right;
        int type;
        double value;

    public :
        MathTree  (int type);
        ~MathTree ();

        void clear_children ();

        void s_left  (MathTree * mt);
        void s_right (MathTree * mt);
        void s_value (double value);

        MathTree * g_left   ();
        MathTree * g_right  ();
        int        g_type   ();
        double     g_value  ();
        bool       is_arith ();
};

#endif
