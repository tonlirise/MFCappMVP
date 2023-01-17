#pragma once

#include "Observer.h"

template <typename T>
class IUpdateObserver
{
public:
	virtual void UpdateObserver(IObserver<T>* pObserver) = 0;
};

template <typename T>
class IObservable : public IUpdate<T>, public IUpdateObserver<T> {};

template <typename T>
class CUiObservable : public IObservable<T>
{
	IObserver<T>* m_pObserver {nullptr};
public:
	CUiObservable() = default;
	~CUiObservable() = default;

	virtual void UpdateObserver(IObserver<T>* pObserver) override
	{
		m_pObserver = pObserver;
	}

	virtual void Update(T* pValue)
	{
		if(m_pObserver && pValue) m_pObserver->Update(pValue);
	}
};
