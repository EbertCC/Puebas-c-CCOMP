#include <iostream>
#include <numeric> // para std::gcd (C++17)
using namespace std;

class Fraction {
private:
    int n, d;
public:
    Fraction(int n, int d = 1) : n(n / gcd(n, d)), d(d / gcd(n, d)) {}
    
    int num() const { return n; }
    int den() const { return d; }
    
    Fraction& operator*=(const Fraction& rhs) {
        int new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }

    bool operator==(const Fraction& rhs)const{
        return (n==rhs.n)&&(d==rhs.d);
    }

    bool operator!=(const Fraction& rhs)const{
        return !((n==rhs.n)&&(d==rhs.d));
    }

    friend ostream& operator<<(ostream& os ,const Fraction& f){
        os<<f.n<<" / "<<f.d;
        return os;
    }

    Fraction operator*(const Fraction& rhs)const{
        return Fraction(n*rhs.n , d*rhs.d);
    }




    static int gcd(int a , int b){

        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;

    }


};



int main() {
    Fraction f1(3, 8), f2(1, 2), f3(10, 2);

    cout << (f1 == f2) << '\n';       // Debería dar 0
    cout << (f1 != f2) << '\n';       // Debería dar 1
    cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n'; // 3/8 * 1/2 = 3/16
    cout << f2 << " * " << f3 << " = " << f2 * f3 << '\n'; // 1/2 * 5/1 = 5/2
    cout << 2 << " * " << f1 << " = " << Fraction(2) * f1 << '\n'; // 2 * 3/8 = 3/4

    return 0;
}