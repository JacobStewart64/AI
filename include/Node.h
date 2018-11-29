#pragma once

#include <functional>

#define NODETEMPLATE \
template<typename T, typename C>

#define NODE \
Node<T, C>

NODETEMPLATE
class Node {
public:
    Node(NODE*, T&&);
    ~Node();

    NODE* root() const;
    void visit_to_root(std::function<void(const T&, const C&)>) const;

    T data;
    C children;
    NODE* parent;
};

NODETEMPLATE
NODE::Node(NODE* _parent, T&& _data)
    : parent(_parent)
    , data(_data)
{}

NODETEMPLATE
NODE::~Node()
{}

NODETEMPLATE
NODE* NODE::root() const
{
    NODE* tmp = parent;
    while (tmp->parent != nullptr)
    {
        tmp = tmp->parent;
    }
    return tmp;
}

NODETEMPLATE
void NODE::visit_to_root(std::function<void(const T&, const C&)> visitor) const
{
    visitor(data, children);

    if (parent == nullptr)
        return;

    NODE* tmp = parent;
    while (tmp->parent != nullptr)
    {
        visitor(tmp->data, tmp->children);
        tmp = tmp->parent;
    }
    visitor(tmp->data, tmp->children);
}

#undef NODETEMPLATE
#undef NODE