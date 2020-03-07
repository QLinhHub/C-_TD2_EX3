#include<iostream>

using namespace std;

template<typename T> class Matrice2x2;
template<typename T> ostream& operator << (ostream&, const Matrice2x2<T>&);

template<typename T>
class Matrice2x2
{
    public:
        T a, b, c, d;
        Matrice2x2(){};
        Matrice2x2(T, T, T, T);
        Matrice2x2 operator + (const Matrice2x2& ) const;
        Matrice2x2 operator - (const Matrice2x2& ) const;
        Matrice2x2 operator * (const float ) const;
        Matrice2x2 operator / (const float ) const;
        friend ostream& operator << <>(ostream& , const Matrice2x2& );
};

template<typename T> ostream& operator << (ostream& os, const Matrice2x2<T>& M){
    os << "[" << M.a << "     " << M.b << endl;
    os << " " << M.c << "     " << M.d << "]" << endl;
    return os;
}

template<typename T> Matrice2x2<T>::Matrice2x2(T a, T b, T c, T d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

template<typename T> Matrice2x2<T> Matrice2x2<T>::operator + (const Matrice2x2<T>& M) const{
    Matrice2x2<T> M_add;
    M_add.a = a + M.a;
    M_add.b = b + M.b;
    M_add.c = c + M.c;
    M_add.d = d + M.d;
    return M_add; 
}

template<typename T> Matrice2x2<T> Matrice2x2<T>::operator - (const Matrice2x2<T>& M) const{
    Matrice2x2<T> M_sous;
    M_sous.a = a - M.a;
    M_sous.b = b - M.b;
    M_sous.c = c - M.c;
    M_sous.d = d - M.d;
    return M_sous; 
}

template<typename T> Matrice2x2<T> Matrice2x2<T>::operator * (const float f) const{
    Matrice2x2 M_mul;
    M_mul.a = a*f;
    M_mul.b = b*f;
    M_mul.c = c*f;
    M_mul.d = d*f;
    return M_mul;
}

int main()
{
    Matrice2x2<int> m(1, 2, 3, 4);
    Matrice2x2<int> m1(2, 3, 4, 5);
    cout << m*3 << endl;
    return 0;
}