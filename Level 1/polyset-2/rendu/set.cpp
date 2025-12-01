// #include "set.hpp"

// set::set(searchable_bag& _bag) : bag(_bag) {}

// set::set(const set& copy) : bag(copy.bag) {}

// set::~set() {}

// void set::insert(int value)
// {
//     if (!bag.has(value))
//         bag.insert(value);
// }

// void set::insert(int *arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if(!bag.has(arr[i]))
//             bag.insert(arr[i]);
//     }
// }

// void set::print() const
// {
//     bag.print();
// }

// void set::clear()
// {
//     bag.clear();
// }

// bool    set::has(int value) const
// {
//     return (bag.has(value));
// }

// const searchable_bag& set::get_bag() const
// {
//     return (bag);
// }

#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

set::set(searchable_bag& _bag)
{
    // detect dynamic type and deep-copy
    if (auto *ab = dynamic_cast<searchable_array_bag*>(&_bag))
        bag = new searchable_array_bag(*ab);
    else if (auto *tb = dynamic_cast<searchable_tree_bag*>(&_bag))
        bag = new searchable_tree_bag(*tb);
    else
        bag = nullptr;
}

set::set(const set& copy)
{
    // deep copy again
    if (auto *ab = dynamic_cast<searchable_array_bag*>(copy.bag))
        bag = new searchable_array_bag(*ab);
    else if (auto *tb = dynamic_cast<searchable_tree_bag*>(copy.bag))
        bag = new searchable_tree_bag(*tb);
    else
        bag = nullptr;
}

// set& set::operator=(const set& copy)
// {
//     if (this != &copy)
//     {
//         delete bag;

//         if (auto *ab = dynamic_cast<searchable_array_bag*>(copy.bag))
//             bag = new searchable_array_bag(*ab);
//         else if (auto *tb = dynamic_cast<searchable_tree_bag*>(copy.bag))
//             bag = new searchable_tree_bag(*tb);
//         else
//             bag = nullptr;
//     }
//     return (*this);
// }

set::~set()
{
    delete bag;
}

void set::insert(int value)
{
    if (!bag->has(value))
        bag->insert(value);
}

void set::insert(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!bag->has(arr[i]))
            bag->insert(arr[i]);
    }
}

void set::print() const
{
    bag->print();
}

void set::clear()
{
    bag->clear();
}

bool set::has(int value) const
{
    return bag->has(value);
}

const searchable_bag& set::get_bag() const
{
    return *bag;
}
