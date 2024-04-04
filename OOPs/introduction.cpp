#include <bits/stdc++.h>
#include "Hero.cpp"
using namespace std;

class Hero {
   private:
    int health;

   public:
    char* name;
    char level;
    static int timeToComplete;

    // default constructor
    Hero() {
        cout << "Default constructor called" << endl;
        name = new char[100];
    }

    // parameterised constructor
    Hero(int health) {
        this->health = health;
    }
    Hero(int health, char level) {
        this->level = level;
        this->health = health;
    }

    // copy constructor
    Hero(Hero& temp) {
        char* ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print() {
        cout << endl;
        cout << "Name " << this->name << endl;
        cout << "Health " << this->health << endl;
        cout << "Level " << this->level << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    static int random() {
        return timeToComplete;
    }

    // destructor
    ~Hero() {
        cout << "Destructor called" << endl;
    }
};

int Hero::timeToComplete = 5;

int main() {
    // cout<<Hero::timeToComplete<<endl;
    cout << Hero::random() << endl;

    // Hero a;
    // cout<<a.timeToComplete<<endl;

    // Hero b;
    // b.timeToComplete = 10;
    // cout<<a.timeToComplete<<endl;
    // cout<<b.timeToComplete<<endl;

    /*
    // static
    Hero a;

    // dynamic
    Hero *b = new Hero();
    // manually destructor call
    delete b;
    */

    /*
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    // hero1.print();

    // use default copy constructor
    Hero hero2(hero1);
    // hero2.print();

    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();

    hero1 = hero2;
    hero1.print();

    hero2.print();
    */

    // Hero S(70,'C');

    // // copy constructor
    // Hero R(S);

    /*
    Hero ramesh(70);
    cout << "Address of ramesh " << &ramesh << endl;
    ramesh.getHealth();

    Hero temp(22,'B');
    */

    /*
    // static allocation
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout << "Level is " << a.level << endl;
    cout << "Health is " << a.getHealth() << endl;

    // dynamic allocation
    Hero *b = new Hero;
    b->setHealth(70);
    b->setLevel('A');
    cout << "Level is " << (*b).level << endl;
    cout << "Health is " << (*b).getHealth() << endl;

    cout << "Level is " << b->level << endl;
    cout << "Health is " << b->getHealth() << endl;
    */

    // // creation of object
    // Hero ramesh;
    // cout<<"Ramesh health is "<<ramesh.getHealth()<<endl;
    // // ramesh.health = 70;
    // ramesh.setHealth(70);
    // ramesh.level = 'A';

    // // cout<<"Size : "<<sizeof(h1)<<endl;
    // cout << "Health is : " << ramesh.getHealth() << endl;
    // cout << "Level is : " << ramesh.level << endl;

    return 0;
}