#ifndef TEST_GROUP_H
#define TEST_GROUP_H

#include <string>
#include <domain/valoplus/controllableElement.h>
#include <vector>

class Group : ControllableElement {
	private:
		std::string name;
		std::vector<ControllableElement> members;
	public:
		std::string getName() { return this->name; }
		std::vector<ControllableElement> getMembers() { return this->members; }
		void setName(std::string name) { this->name = name; }
		void setMembers(std::vector<ControllableElement> members) { this->members = members; }
};

#endif //TEST_GROUP_H
