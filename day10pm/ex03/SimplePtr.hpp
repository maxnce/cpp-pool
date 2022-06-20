#pragma once

#include "BaseComponent.hpp"

class SimplePtr
{
public:
    explicit SimplePtr(BaseComponent *rawPtr);
    ~SimplePtr();
    BaseComponent *get() const;

private:
    // Make the class non copyable
    SimplePtr(SimplePtr const &);
    SimplePtr &operator=(SimplePtr const &);

    BaseComponent *_rawPtr;
};
