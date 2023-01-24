#pragma once

#include <memory>

template <typename T>
class IUpdate
{
public:
	virtual void UpdateValue(T* pValue) = 0;
};

template <typename T>
class IObserver : public IUpdate<T>{};
