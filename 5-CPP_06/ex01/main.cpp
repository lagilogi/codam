#include "Serializer.hpp"

int main()
{
	Data* ptr = new(Data);
	ptr->age = 100;
	ptr->name = "Billy";

	uintptr_t intRepresantion = Serializer::serialize(ptr);
	Data* ptr2 = Serializer::deserialize(intRepresantion);
	
	std::cout << "ptr:  " << ptr
			<< "\nptr2: " << ptr2
			<< "\nintRep: " << intRepresantion << std::endl;
	std::cout << "\n-- Checking ptr data --"
			<< "\nptr age: " << ptr->age
			<< "\nptr name: " << ptr->name << std::endl;
	std::cout << "\n-- Derefencing ptr2 data --"
			<< "\nptr2 age: " << ptr2->age
			<< "\nptr2 name: " << ptr2->name << std::endl;
	delete (ptr2);
	ptr = nullptr;
	ptr2 = nullptr;
}
