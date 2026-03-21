#include<iostream>
#include"smart_array .h"

static void Print(smart_array& arr)
{
	std::cout << "[";
	for (int i = 0; i < arr.GetSize(); i++)
	{
		if (i == 0)
		{
			std::cout << arr.get_element(i);
			continue;
		}
		std::cout << ", " << arr.get_element(i);
	}
	std::cout << "]"<<std::endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		std::cout << "arr1" << std::endl;
		Print(arr);


		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		std::cout << "arr2" << std::endl;
		Print(new_array);
		std::cout << std::endl;

		arr = new_array;
		std::cout << "arr1" << std::endl;
		Print(arr);
		std::cout << "arr2" << std::endl;
		Print(new_array);

		std::cout << std::endl;

		arr.add_element(100);
		Print(arr);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}