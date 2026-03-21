#pragma once
#include<iostream>

class smart_array
{
public:
	smart_array(size_t);
	~smart_array();
	void add_element(const int);
	int get_element(const int) const;
	size_t GetSize() const;
	size_t GetCapacity() const;
	void operator =(const smart_array& arr);

private:
	int* arr;
	size_t size;
	size_t count_el;
};