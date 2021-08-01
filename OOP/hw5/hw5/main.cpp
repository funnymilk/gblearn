#include <iostream>

using namespace std;

template <typename Type>
class Pair1{
    Type pa;
    Type pb;
public:
    Pair1(Type a, Type b) : pa(a), pb(b)
    {};

    Type first() const{
        return pa;
    }

    Type second() const{
        return pb;
    }
};


template <typename T1, typename  T2>
class Pair2{
    T1 pa;
    T2 pb;
public:
    Pair2(T1 a, T2 b) : pa(a), pb(b)
    {};

    T1 first() const{
        return pa;
    }

    T2 second() const{
        return pb;
    }
};

template <string *text, typename T2>
class Pair{
protected:
    T2 _value;

public:

    Pair(T2 b) : _value(b)
    {};

    /*string first() const{
        return *T1;
    }*/

    T2 second() const{
        return _value;
    }
};

template <typename T2>
class StringValuePair<string, T2> : public Pair<string, T2>{
    T2 d;
public:
    StringValuePair(T2 _value) : Pair<string, T2>(_value)
    {
        d = _value;
    }
};

int main()
{
    /*Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n'; */

   /* Pair2<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair2<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';*/


    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
