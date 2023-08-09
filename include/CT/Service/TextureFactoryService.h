#ifndef CT_SERVICE_TEXTURE_FACTORY_SERVICE_H
#define CT_SERVICE_TEXTURE_FACTORY_SERVICE_H

#include "CT/Service/Service.h"
#include "CT/Factory/TextureFactory.h"

namespace CT::Service
{
	/**
	* @brief An instance of CT::Factory::TextureFactory.
	*
	* @namespace CT::Service.
	*/
	class TextureFactoryService : public CT::Service::Service
	{
	public:
		TextureFactoryService() {}
		~TextureFactoryService() {}

		/**
		* Get the underlying service this object holds.
		*
		* @return A pointer to CT::Service::Service.
		*/
		virtual CT::Service::Service* getService() override
		{
			return this->service;
		}

	private:
		CT::Service::Service* service = nullptr;
	};
}
#endif //CT_SERVICE_TEXTURE_FACTORY_SERVICE_H
