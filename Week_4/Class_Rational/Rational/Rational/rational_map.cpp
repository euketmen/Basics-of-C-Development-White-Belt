#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
    public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        P = 0;
        Q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        P = numerator/(nod(numerator, denominator));
        Q = denominator/(nod(numerator, denominator));
        signs(P, Q);
    }

    int Numerator() const { //Числитель
        // Реализуйте этот метод
        return P;
    }

    int Denominator() const { //Знаменатель
        // Реализуйте этот метод
        return Q;
    }

private:
    void signs(int& a, int& b){
        if((a>0 && b<0) || (a<0 && b<0)){
            a=-a;
            b=-b;
        }
    }
    int nod(int a, int b) {
        return b == 0 ? a : nod(b, a % b);
    }
    // Добавьте поля
    int P;  //P - целое число (числитель)
    int Q; //Q - натуральное число (знаменатель)
};

// Вставьте сюда реализацию operator == для класса Rational из второй части
bool operator==(const Rational& r_1, const Rational& r_2){
    if((r_1.Numerator() == r_2.Numerator()) && (r_1.Denominator() == r_2.Denominator())) return true;
    else return false;
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator > (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator < (Rational a, Rational b) { //обязательно нужно это дело перегрузить, для использования в map и set
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
