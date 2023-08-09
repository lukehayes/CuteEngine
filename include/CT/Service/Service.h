#ifndef CT_SERVICE_SERVICE_H
#define CT_SERVICE_SERVICE_H

namespace CT::Service
{
	/**
	* @breif Base class for all services inside the service container.
	*
	* @namespace CT::Service.
	*/
	class Service
	{
	public:
		Service() {}
		~Service() {}

		virtual CT::Service::Service* getService() = 0;
	};
}
#endif
