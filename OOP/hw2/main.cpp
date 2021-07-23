#include <iostream>

using namespace std;

class Person{
protected:
    string _name{};
    string _sex{};
    int _age{}, _weight{};

public:
    Person(string name = "", string sex = "", int age = 0, int weight = 0) : _name(name), _sex(sex), _age(age), _weight(weight)
    { }

    void name(string n){
        _name = n;
    }

    void ageWeight(int a){
        _age = a;
    }
    void weight(int w){
        _weight = w;
    }
    void sex(string s){
        _sex = s;
    }

};

class Student : public Person {
    int _year{};
    int _count{};
public:
    //using Person::Person;
    Student(string name = "", string sex = "", int age = 0, int weight = 0, int year = 0, int count = 0) : Person(name, sex, age, weight), _year(year), _count(count)
    { }
    void year(int y){
        _year = y;
    }
    void print(){
        cout << _name << endl;
        cout << _sex << endl;
        cout << _age << endl;
        cout << _weight << endl;
        cout << _year << endl;
    }
    Student(string n, string s, int a, int w, int y){
        name(n);
        ageWeight(a);
        weight(w);
        sex(s);
        year(y);
        _count++;
    }

//    string getName() const { return _name; }
//    string getSex() const { return _sex; }
//    int getAge() const { return _age;}
//    int getWeight() const { return _weight; }
//    int getYear() const { return _year; }
};

//void print(const Student &student){
//    std::cout << student.getName() << '\n' << date.getMonth() << '\n' << date.getYear() << '\n';
//}

class Fruit{
protected:
    string _name{};
    string _color{};
public:
    Fruit(string name = "", string color = "") : _name(name), _color(color)
    { }

    string getName() const{
        return _name;
    }
    string getColor() const{
        return _color;
    }
};

class Apple : public Fruit{
public:
    Apple(string name = "apple", string color = "") : Fruit(name, color) //вот с этим проблемы, не могу понять как правильно сформировать конструктор, из-за этого ошибки при вызове в мейне
    { }
    Apple(string col){
        _color = col;
    }

};

class Banana : public Fruit{
public:
    Banana(string name = "banana", string color = "yellow") : Fruit(name, color)
    {}
};

class GrannySmith : public Apple{
public:
    GrannySmith(string name = "", string color = "green") : Apple(name, color)
    {}
};


int main()
{
    Student vitek("Sasha", "male", 15, 55);
    //vitek.print();


        Apple a("red");
        Banana b;
        GrannySmith c;

        std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
        std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
