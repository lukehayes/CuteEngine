#pragma once

#include "common/types.h"

/**
 * A generic container to hold specific groups of things.
 */
template<class T>
class TypedContainer
{
    public:
        TypedContainer() {}
        ~TypedContainer() {}

        void render();

        void update(double delta);

        void add(std::shared_ptr<T>& entity);

        std::vector<std::shared_ptr<T>> entities;
};

template<class T>
void TypedContainer<T>::add(std::shared_ptr<T>& entity)
{
    this->entities.push_back(entity);
}

template<class T>
void TypedContainer<T>::render()
{
    for(auto &e : this->entities)
    {
        e->render();
    }
}

template<class T>
void TypedContainer<T>::update(double delta)
{
    for(auto &e : this->entities)
    {
        e->update(delta);
    }
}

//extern TypedContainer typedContainer;
