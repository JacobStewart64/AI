#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

class Data {
public:
    Data(int);
    ~Data();

    int hi() const;

    const int sig;
};

Data::Data(const int _sig) : sig(_sig) {}
Data::~Data() {}

int Data::hi() const
{
    return sig;
}

class Children {
public:
    Children();
    ~Children();

    vector<Node<Data, Children>*> child_vec;
};

Children::Children() {}
Children::~Children() {}

int main()
{
    Node<Data, Children>* dnode0 = new Node<Data, Children>(nullptr, Data(0));
    Node<Data, Children>* dnode2 = new Node<Data, Children>(dnode0, Data(2));
    Node<Data, Children>* dnode3 = new Node<Data, Children>(dnode2, Data(3));
    Node<Data, Children>* dnode4 = new Node<Data, Children>(dnode3, Data(4));
    Node<Data, Children>* dnode5 = new Node<Data, Children>(dnode4, Data(5));
    Node<Data, Children>* dnode7 = new Node<Data, Children>(dnode5, Data(7));
    dnode7->visit_to_root([](const Data& d, const Children& c) {
        cout << d.hi() << endl;
    });
    return 0;
}