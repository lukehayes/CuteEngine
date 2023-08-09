#ifndef CT_SERVICE_CONTAINER_H
#define CT_SERVICE_CONTAINER_H

#include "CT/Service/Service.h"
#include <map>
#include <string>

namespace CT::Service
{
	/**
	* @brief The main Service Container for the application.
	* 
	* @namespace CT::Service
	*/
	class Container
	{
	public:
		Container();
		~Container();
		
		/**
		* Add a service to the container.
		*
		* @param name The name of the service.
		* @param service A pointer to the service.
		*/
		void addSevice(const std::string& name, CT::Service::Service* service);

		/**
		* Does the service already exist inside the container.
		*
		* @param name The name of the service.
		*/
		bool hasService(const std::string& name);

		/**
		* Get a service from the container.
		*
		* @param name The name of the service.
		*
		* @return Instance of CT::Service::Service* or nullptr.
		*/
		CT::Service::Service* getService(const std::string& name);

	private:
		std::map<std::string, CT::Service::Service*> services;
	};
}
#endif
