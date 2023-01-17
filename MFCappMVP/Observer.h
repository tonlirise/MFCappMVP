#pragma once

template <typename T>
class IUpdate
{
public:
	virtual void Update(T* value) = 0;
};

template <typename T>
class IObserver : public IUpdate<T>{};
