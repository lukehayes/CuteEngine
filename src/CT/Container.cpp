#include "CT/Service/Container.h"

#include "CT/Service/TextureFactoryService.h"
#include <cstdio>

namespace CT::Service
{
    Container::Container() 
    {
        this->addSevice("texture_factory", new CT::Service::TextureFactoryService);
    }

    Container::~Container() {}
        
    void 
    Container::addSevice(const std::string& name, CT::Service::Service* service)
    {
        this->services.insert(std::pair(name, service));
    }

    bool  
    Container::hasService(const std::string& name)
    {
        return this->services.contains(name) ? true : false;
    }

    CT::Service::Service*
    Container::getService(const std::string& name)
    {
        if(this->hasService(name))
        {
            return this->services.at(name)->getService();
        }

        return nullptr;
    }

    std::map<std::string, CT::Service::Service*> Container::getServices() const { return this->services; }
}
