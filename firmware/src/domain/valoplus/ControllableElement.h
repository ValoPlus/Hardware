#ifndef TEST_CONTROLLABLEELEMENT_H
#define TEST_CONTROLLABLEELEMENT_H

#include <domain/core/PersistentElement.h>
#include <string>

class ControllableElement : public PersistentElement {
	private:
		
	public:
		virtual std::string getName()= 0;
		virtual void setName(std::string name)= 0;
};

#endif //TEST_CONTROLLABLEELEMENT_H
