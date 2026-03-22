#include "smart_array.h"

smart_array::smart_array(size_t size)
{
	this->size = size;
	arr = new int[size];
	count_el = 0;
}

smart_array::~smart_array()
{
	if(arr != nullptr)
		delete[]arr;
}

void smart_array::add_element(const int number)
{
	if (count_el >= size)
		throw std::length_error("Попытка превысить длинну");
	arr[count_el] = number;
	count_el++;
}

int smart_array::get_element(const int index) const 
{
	if (index<0 || size < index)
		throw std::out_of_range("Выход за пределы диапозона");
	if (count_el >= index)
		throw std::out_of_range("Попытка получить неинициализированное значение");
	return arr[index];

}

size_t smart_array::GetSize() const
{
	return count_el;
}

size_t smart_array::GetCapacity() const
{
	return size;
}

void smart_array::operator =(const smart_array& array)
{
	size_t tmp_capasity = array.GetCapacity();
	size_t size = array.GetSize();
	int* tmp = new int[tmp_capasity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = array.get_element(i);
	}
	delete[]arr;
	arr = new int[tmp_capasity];
	this->arr = tmp;
	this->size = array.GetCapacity();
	this->count_el = array.GetSize();
}