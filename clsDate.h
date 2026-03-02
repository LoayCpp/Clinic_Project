#pragma once
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class clsMyQueue
{
private:
	queue<T> MyQueue;
	int _Size = 0;

public:
	void push(T value)
	{
		_Size++;
		MyQueue.push(value);
	}

	int Size()
	{
		return _Size;
	}
	void pop()
	{

		_Size--;
		MyQueue.pop();
	}
	T front()
	{

		return MyQueue.front();
	}

	T back()
	{

		return MyQueue.back();
	}

	void Print()
	{

		queue<T> currentQueue = MyQueue;

		for (int i = 0; i < _Size; i++)
		{

			cout << currentQueue.front() << " ";
			currentQueue.pop();
		}
	}
};
