#pragma once

#include "Observer.h"

#include <memory>

template <typename T>
class IUpdateObserver
{
public:
	virtual void UpdateObserver(std::function<void(T)> observerFun) = 0;
};

template <typename T>
class IObservable : public IUpdate<T>, public IUpdateObserver<T> {};

template <typename T>
class CUiObservable : public IObservable<T>
{
	std::function<void(T)> m_observerFun;
public:
	CUiObservable() = default;
	~CUiObservable() = default;

	virtual void UpdateObserver(std::function<void(T)> observerFun) override
	{
		m_observerFun = observerFun;
	}

	virtual void UpdateValue(T* pValue) override
	{
		if (m_observerFun && pValue) m_observerFun(*pValue);
	}
};
