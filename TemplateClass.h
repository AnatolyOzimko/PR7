#pragma once
#include <iostream>

template <class T>
class TemplateClass
{
private:
	int length;
	T* data;
public:
	TemplateClass();
	TemplateClass(int aLength);
	T& operator[](int index);
	void showArray();
	void average();
	void max();
};

template<class T>
inline TemplateClass<T>::TemplateClass()
{
	length = 0;
	data = nullptr;
}

template<class T>
inline TemplateClass<T>::TemplateClass(int aLength)
{
	data = new T[aLength];
	length = aLength;
}

template<class T>
inline T& TemplateClass<T>::operator[](int index)
{
	return data[index];
}

template<class T>
inline void TemplateClass<T>::showArray()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << data[i] << std::endl;
	}

}

template<class T>
inline void TemplateClass<T>::average()
{
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += data[i];

	std::cout << "Average: " << sum / length << std::endl;
}

template<class T>
inline void TemplateClass<T>::max()
{
	int max = data[0];

	for (int i = 0; i < length; ++i) {
		if (data[i] > max) {
			max = data[i];
		}
	}

	std::cout << "Max: " << max << std::endl;
}
