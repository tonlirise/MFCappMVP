#pragma once

#include "Observer.h"

template <typename T>
class IUpdateObserver
{
public:
	virtual void UpdateObserver(IObserver<T>* observer) = 0;
};

template <typename T>
class IObservable : public IUpdate<T>, public IUpdateObserver<T> {};

template <typename T>
class CUiObservable : public IObservable<T>
{
	IObserver<T>* observer {nullptr};
public:
	CUiObservable() = default;
	~CUiObservable() = default;

	virtual void UpdateObserver(IObserver<T>* observer) override
	{
		this->observer = observer;
	}

	virtual void Update(T* value)
	{
		if(observer && value) observer->Update(value);
	}
};
