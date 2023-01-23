#pragma once

#include <memory>

template <typename T>
class IUpdate
{
public:
	virtual void UpdateValue(std::shared_ptr<T> pValue) = 0;
};

template <typename T>
class IObserver : public IUpdate<T>{};
