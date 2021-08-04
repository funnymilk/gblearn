#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print(vector<int> &a) {
    //cout << " " << a.size() << '\n';

    for (int i=0; i<a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}
class Card{
    enum m_nominal{
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
    enum m_suit{
        DIAMOND,
        HEART,
        CLUBS,
        SPADES
    };

    bool m_cardpos;
public:
    m_nominal nom;
    Card(m_nominal nominal, m_suit suit, bool cardpos = false) : m_nominal(nominal), m_suit(suit), m_cardpos(cardpos)
    { nom = nominal; }
    void Flip(){
        m_cardpos = !m_cardpos;
    }

    int GetValue(){
        m_nominal card;
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
class Hand{
    vector<Card*> _card;
public:
    Hand(vector<Card*> c) : _card(c)
    {}

    void Add(Card* cards){
        //_card = cards;
        _card.push_back(cards);
    }

    void Clear(){
        _card.clear();
    }

    int GetValue(){
       int sum = 0;
       for (int i = 0; i < _card.size(); i++){
           if ( (_card[i]->nom == ACE) && ((sum + _card[i]->GetValue()) > 21) ) {
                sum += _card[i]->GetValue();
           }else sum += _card[i]->GetValue();
        }
    }
};


int main()
{    

    vector<int> v = { 10, 8, 10, 4, 2, 1, 2, 3, 3, 6, 5 };
    print(v);
    int inc = 0;
    for (int j = 0; j < v.size(); j++){
        for (int i = 0; i < v.size(); i++){
            //cout << "v[i] = " << v[i] << endl;
            //cout << "*v.end() = " << v.size() << endl;
            if ( (v[j] == v[i]) && (j != i)) break;
            else if (i == v.size()-1) inc++;
        }
    }
    cout << "Количество неповторяющихся числе равна " << inc << endl;
    std::sort(v.begin(), v.end());
    print(v);
    //cout << "Hello World!" << endl;


    return 0;

}
