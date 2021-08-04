#include <iostream>

using namespace std;

class Figure{
public:
    virtual void area()=0;
};

class Parallelogram : public Figure{
protected:
    int S{}, a = 5, h = 2;
public:

    void area(){
        S = a*h;
        cout << "Parallelogram = " << S << endl;
    }

};

class Circle : public Figure{

};

class Rectangle : public Parallelogram{
    int a = 4, b = 3;
public:
    void area(){
        S = a*b;
        cout << "Rectangle = " << S << endl;
    }
};

class Square : public Parallelogram{
    int a = 3;
public:
    void area(){
        S = a*a;
        cout << "Square = " << S << endl;
    }
};

class Rhombus : public Parallelogram{

public:
    void area(){
        S = a*h;
        cout << "Rhombus = " << S << endl;
    }
};
//-----------------------------------------------

class Car{
protected:
    string _company{};
    string _model{};
public:
    Car(string com = "", string mod = "") : _company(com), _model(mod)
    {    }

};

class PassengerCar : public Car{
public:
    PassengerCar(string com = "Toyota", string mod = "Supra") : Car(com, mod)
    {
        cout << "PassengerCar: ";
        cout << com << ", " << mod<< endl;
    }
};

class Bus : public Car{
public:
    Bus(string com = "Icarus", string mod = "342") : Car(com, mod)
    {
        cout << "Bus: ";
        cout << com << ", " << mod<< endl;
    }
};

class Minivan : public PassengerCar, public Bus{
public:
    Minivan(string com = "nissan", string mod = "autopekar") : PassengerCar(com, mod), Bus(com, mod)
    {
        cout << "Minivan: ";
        cout << com << ", " << mod<< endl;
    }
};
//-----------------------------------------------

/*class Fraction{
    int numerator{}, denominator{};
public:
    Fraction(int num) {
        numerator = num;
        //denominator = den;
    }

    friend Fraction operator+(const Fraction &num1, const Fraction &den1);
    int getDollars() const { return numerator; }
};

Fraction operator+(const Fraction &num1, const Fraction &den1){
    return Fraction(num1.numerator + den1.denominator);
}*/


class Card{
    enum suit{
        ACE = 1,
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACKET = 10,
        QEEN = 10,
        KING = 10
    };
    bool cardpos;
public:
    void Flip(){
        cardpos = !cardpos;
    }

    int GetValue(){
        suit card;
        card = ACE;
        if (card == ACE){
            return ACE;
        }if (card == TWO){
            return TWO;
        }if (card == THREE){
            return THREE;
        }if (card == FOUR){
            return FOUR;
        }if (card == FIVE){
            return FIVE;
        }if (card == SIX){
            return SIX;
        }if (card == SEVEN){
            return SEVEN;
        }if (card == EIGHT){
            return EIGHT;
        }if (card == NINE){
            return NINE;
        }else return 10;
        }
};

int main()
{
    /*Parallelogram pl;
    pl.area();
    Rectangle rec;
    rec.area();
    Square sq;
    sq.area();
    Rhombus romb;
    romb.area();*/

  /*  PassengerCar pc;
    Bus b;
    Minivan mv; // выводит на экран повторно информацию о PassengerCar и Bus, и только потом выводит инфу о минивене
*/
    /*Fraction fr1(7);
    Fraction fr2(9);
    Fraction sum = fr1 + fr2;
    cout << "I have " << sum.getDollars() << " dollars.";*/

    cout << "Hello World!" << endl;
    return 0;
}
