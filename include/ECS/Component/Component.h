#pragma once

#include <string>

namespace ECS::Component
{
    class Component
    {
    public:
            Component();
            Component(const std::string& name);
            ~Component();

            /**
             * Get the name of the component.
             *
             * @return std::string
             */
            std::string getName() const;

    private:
            std::string name;

    };
}

