#include "Array.hpp"

int main()
{
	// int array
	Array<int> x(5);
	std::cout << x[0] << std::endl;


	// std::cout << "\n--- INT ARRAY ---\n1. Array<int> intArray(5);" << std::endl;
	// Array<int> intArray(5);
	// for (int i = 0; i < 5; ++i) {
	// 	intArray[i] = i;
	// }
	// for (int i = 0; i < 5; ++i) {
	// 	std::cout << "Num: " << intArray[i] << std::endl;
	// } std::cout << std::endl;

	// std::cout << "\n2. Array<int> intArray2(10);" << std::endl;
	// Array<int> intArray2(10);
	// for (int i = 0; i < 10; ++i) {
	// 	intArray2[i] = i+100;
	// }
	// for (int i = 0; i < 10; ++i) {
	// 	std::cout << "Num: " << intArray2[i] << std::endl;
	// } std::cout << std::endl;

	// std::cout << "\n3. Array<int> intArray3(intArray); Printing going out of bounds" << std::endl;
	// Array<int> intArray3(intArray);
	// try
	// {
	// 	for (int i = 0; i < 10; ++i) {
	// 		std::cout << intArray[i] << std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// } std::cout << std::endl;

	// try
	// {
	// 	std::cout << "\n4. intArray = intArray2;" << std::endl;
	// 	intArray = intArray2;
	// 	for (int i = 0; i < 10; ++i) {
	// 		std::cout << "intArray: " << intArray[i] << " - intArray2: " << intArray2[i] << std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// } std::cout << std::endl;


	// std::cout << "\n5. Changing intArray values, check if intArray2 remain unchanged" << std::endl;
	// for (int i = 0; i < 10; ++i) {
	// 	intArray[i] = i;
	// }
	// for (int i = 0; i < 10; ++i) {
	// 	std::cout << "intArray: " << intArray[i] << " - intArray2: " << intArray2[i] << std::endl;
	// } std::cout << std::endl;





	// // string array
	// std::cout << "\n\n\n--- STD::STRING ARRAY ---\n1. Array<std::string> intArray4 - check if _array points to nullptr" << std::endl;
	// Array<std::string> intArray4; std::cout << std::endl;

	// std::cout << "\n2. Array<std::string> stringArray(4)" << std::endl;
	// Array<std::string> stringArray(4);
	// stringArray[0] = "Hello";
	// stringArray[1] = "Billy";
	// stringArray[2] = "Goodbye";
	// stringArray[3] = "Tilly";
	// for (unsigned int i = 0; i < stringArray.size(); ++i)
	// 	std::cout << "String " << i << " " << stringArray[i] << std::endl;

	// std::cout << "\n3. Array<std::string> stringArray2(stringArray)" << std::endl;
	// Array<std::string> stringArray2(stringArray);
	// std::cout << "\nstringArray - stringArray2:" << std::endl;
	// std::cout << stringArray[0] << " - " << stringArray2[0] << '\n'
	// 		<< stringArray[1] << " - " << stringArray2[1] << '\n'
	// 		<< stringArray[2] << " - " << stringArray2[2] << '\n'
	// 		<< stringArray[3] << " - " << stringArray2[3] << '\n' << std::endl;
	// stringArray2[0] = "dshgjh"; stringArray2[1] = "kjndsg"; stringArray2[2] = "sabdghbsg"; stringArray2[3] = "hbdsghbf";
	// std::cout << stringArray[0] << " - " << stringArray2[0] << '\n'
	// 		<< stringArray[1] << " - " << stringArray2[1] << '\n'
	// 		<< stringArray[2] << " - " << stringArray2[2] << '\n'
	// 		<< stringArray[3] << " - " << stringArray2[3] << std::endl;			

	// std::cout << "\n4. Array<std::string> stringArray3;" << std::endl;
	// Array<std::string> stringArray3;
	// stringArray3 = stringArray2;
	// std::cout << stringArray3[0] << '\n'
	// 		<< stringArray3[1] << '\n'
	// 		<< stringArray3[2] << '\n'
	// 		<< stringArray3[3] << std::endl;

	// std::cout << "\n5. Going out of bounds" << std::endl;
	// try
	// {
	// 	stringArray3[10];
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n' << std::endl;
	// }


	// // Char array
	// std::cout << "\n\n\n--- CHAR ARRAY ---\n1. Array<char> charArray" << std::endl;
	// Array<char> charArray(5);
	// for (unsigned int i = 0; i < charArray.size(); ++i) {
	// 	charArray[i] = i + 90;
	// } std::cout << std::endl;
	// for (unsigned int i = 0; i < charArray.size(); ++i) {
	// 	std::cout << "Char: " << charArray[i] << '\n';
	// } std::cout << std::endl;

	// std::cout << "\n2. Empty array" << std::endl;
	// Array<char> charArray2;
	// std::cout << "Size: " << charArray2.size() << '\n' << std::endl;


}



/////////////    ///////////////////     //////////////////    /////////////////////


// int	main(void)
// {
// 	try
// 	{
// 		Array<int> arr;
// 		std::cout << "Empty array size: " << arr.size() << std::endl;

// 		Array<int> intArray(10);
// 		std::cout << "Int array size: " << intArray.size() << std::endl;

// 		for (unsigned int i = 0; i < intArray.size(); i++)
// 			intArray[i] = i * 42;

// 		std::cout << "Int array contents: " << std::endl;
// 		for (unsigned int i = 0; i < intArray.size(); i++)
// 			std::cout << intArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<int> copyArray(intArray);
// 		std::cout << "Copied array size: " << copyArray.size() << std::endl;
// 		std::cout << "Set copy index [0] to 9" << std::endl;
// 		copyArray[0] = 9;
// 		std::cout << "Original array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < intArray.size(); i++)
// 			std::cout << intArray[i] << " ";
// 		std::cout << std::endl;
// 		std::cout << "Copied array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < copyArray.size(); i++)
// 			std::cout << copyArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<int> assignedArray;
// 		assignedArray = copyArray;
// 		for (unsigned int i = 0; i < assignedArray.size(); i++)
// 			std::cout << assignedArray[i] << " ";
// 		std::cout << std::endl;

// 		std::cout << "Accessing out-of-bounds: " << arr[1] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }

// int	main(void)
// {
// 	try
// 	{
// 		Array<char> arr;
// 		std::cout << "Empty array size: " << arr.size() << std::endl;

// 		Array<char> charArray(10);
// 		std::cout << "Char array size: " << charArray.size() << std::endl;

// 		for (unsigned int i = 0; i < charArray.size(); i++)
// 			charArray[i] = i + 97;

// 		std::cout << "Char array contents: " << std::endl;
// 		for (unsigned int i = 0; i < charArray.size(); i++)
// 			std::cout << charArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<char> copyArray(charArray);
// 		std::cout << "Copied array size: " << copyArray.size() << std::endl;
// 		std::cout << "Set copy index [0] to 'c'" << std::endl;
// 		copyArray[0] = 99;
// 		std::cout << "Original array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < charArray.size(); i++)
// 			std::cout << charArray[i] << " ";
// 		std::cout << std::endl;
// 		std::cout << "Copied array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < copyArray.size(); i++)
// 			std::cout << copyArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<char> assignedArray;
// 		assignedArray = copyArray;
// 		for (unsigned int i = 0; i < assignedArray.size(); i++)
// 			std::cout << assignedArray[i] << " ";
// 		std::cout << std::endl;

// 		std::cout << "Accessing out-of-bounds: " << arr[1] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }

// int	main(void)
// {
// 	try
// 	{
// 		Array<std::string> arr;
// 		std::cout << "Empty array size: " << arr.size() << std::endl;

// 		Array<std::string> strArray(5);
// 		std::cout << "String array size: " << strArray.size() << std::endl;

// 		strArray[0] = "Hello";
// 		strArray[1] = "World";
// 		strArray[2] = "This";
// 		strArray[3] = "Is";
// 		strArray[4] = "Me";

// 		std::cout << "Char array contents: " << std::endl;
// 		for (unsigned int i = 0; i < strArray.size(); i++)
// 			std::cout << strArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<std::string> copyArray(strArray);
// 		std::cout << "Copied array size: " << copyArray.size() << std::endl;
// 		std::cout << "Set copy index [4] to \"C++\'" << std::endl;
// 		copyArray[4] = "C++";
// 		std::cout << "Original array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < strArray.size(); i++)
// 			std::cout << strArray[i] << " ";
// 		std::cout << std::endl;
// 		std::cout << "Copied array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < copyArray.size(); i++)
// 			std::cout << copyArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<std::string> assignedArray;
// 		assignedArray = copyArray;
// 		for (unsigned int i = 0; i < assignedArray.size(); i++)
// 			std::cout << assignedArray[i] << " ";
// 		std::cout << std::endl;

// 		std::cout << "Accessing out-of-bounds: " << arr[1] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }