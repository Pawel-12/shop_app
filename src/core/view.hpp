#pragma once
#include <memory>
#include "session.hpp"

class View
{
public:
    virtual ~View() = default;
    virtual View* display(session&) = 0;

    virtual std::string getDisplayName() = 0;
};
