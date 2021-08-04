#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Card{

public:
    enum m_nominal{
        ACE = 1, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACKET = 10, QEEN = 10, KING = 10
    };
    enum m_suit{DIAMOND, HEART, CLUBS, SPADES};

    Card(m_nominal nominal, m_suit suit, bool IsFace = false) : nom_(nominal), suit_(suit), m_IsFace(IsFace)
    { nom_ = nominal; }
    void Flip(){
        m_IsFace = !m_IsFace;
    }
    int GetValue() const{
        int card;
        card = nom_;

        if (card >= 10){
            return 10;
        } else return card;
    }

private:
    m_nominal nom_;
    m_suit suit_;
    bool m_IsFace;
};

class Hand
{
public:
    Hand();
    // виртуальный деструктор
    virtual ~Hand();

    // добавляет карту в руку
    void Add(Card* pCard);

    // очищает руку от карт
    void Clear();

    //получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
};

Hand::Hand()
{
    m_Cards.reserve(7);
}
// деструктор по-прежнему виртуальный
// это уже можно не обозначать
Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    // проходит по вектору, освобождая всю память в куче
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    // очищает вектор указателей
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    // если карт в руке нет, возвращает значение 0
    if (m_Cards.empty())
    {
        return 0;
    }

    //если первая карта имеет значение 0, то она лежит рубашкой вверх:
    // вернуть значение 0
    if (m_Cards[0]->GetValue() == 0)
    {
        return 0;
    }

    // находит сумму очков всех карт, каждый туз дает 1 очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        total += (*iter)->GetValue();
    }

    // определяет, держит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && total <= 11)
    {
        // добавляем только 10 очков, поскольку мы уже добавили
        // за каждый туз по одному очку
        total += 10;
    }

    return total;
}

/*class Hand{
protected:
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
        _card.shrink_to_fit(); // если всё правильно понял этот метод сокращает объём памяти до размера веткора, который в свою очередь после clear равен 0
    }

    int GetValue(){
       int sum = 0;
       for (int i = 0; i < _card.size(); i++){
           if ( (_card[i]->nom_ == 1) && ((sum + _card[i]->GetValue()) > 21) ) {
                sum += _card[i]->GetValue();
           }else sum += _card[i]->GetValue();
        }
    }

    virtual ~Hand();

};
*/

class GenericPlayer : public Hand{
    string name_;
public:
    //GenericPlayer(string name,)
    virtual bool IsHitting(){
        return true;
    }

    bool IsBoosted(){
        //int toto = GetTotal();
        if (GetTotal() > 21) return true;
    }

    void Bust(){
        cout << name_ << endl;
        if (IsBoosted()) cout << "У вас перебор, уважаемый" << endl;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
