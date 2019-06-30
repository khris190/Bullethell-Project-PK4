#pragma once
#include <vector>
template <typename T>
class TemplateVector
{

public:
	std::vector < T  > Vector;

	void DeleteElement(int x)
	{
		T swapper = Vector[x];
		Vector[x] = Vector[Vector.size() - 1];
		Vector[Vector.size() - 1] = swapper;
		Vector.erase(Vector.end() - 1);
		delete swapper;
	}
	TemplateVector()
	{

	}
	T operator[](const int& x)
	{
		return Vector[x];
	}

	void push_back( T obj)
	{
		Vector.push_back(obj);
	}

	size_t size()
	{
		return Vector.size();
	}

	~TemplateVector()
	{
		Vector.clear();
	}
};

