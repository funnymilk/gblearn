#include <iostream>
#include <math.h>
#include <cstdint>
using namespace std;

class Power{
private:
    float a, b;

public:
    void set(){
        a = 5;
        b = 2;
    }

    void calculate(){
        int result;
        result = pow (a, b);

        cout<< "a ^ b = " << result << endl;
    }


};

class RGBA{
private:
    uint8_t m_red{}, m_green{}, m_blue{};
    uint8_t  m_alpha = 255;
public:
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : m_red(r), m_green(g), m_blue(b), m_alpha(a)
    {
        cout<< "init"<< endl;
    }

    void print(){
        cout<< "m_red = " << m_red << endl;
        cout<< "m_green = " << m_green << endl;
        cout<< "m_blue = " << m_blue << endl;
        cout<< "m_alpha = " << m_alpha << endl;
    }
};

class Stack{
private:
    int array[10];
    int length;
public:
    void reset()
    {
        fill(array, array + 10, 0);
        length = 0;
    }

    bool push(int a){
        if (length <= 9) {
            array[length] = a;
            length++;
            return true;
        } else return false;
    }

    void pop(){
        if (length == 0) {
            cout<< "Stack is empty" << endl;
            return;
        }
        array[length] = 0;
        length--;
    }

    void print(){
        cout << "(";
        for(int i = 0; i < length; i++){
            cout<< array[i] << " " ;
        }
        cout << ")" << endl;
    }

};


int main()
{
    Power calc;
    calc.set();
    calc.calculate();

    RGBA rgba(12, 15, 0, 210);
    rgba.print();

    Stack stack;

    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();




    return 0;

}
