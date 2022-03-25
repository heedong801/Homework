#pragma once
#include <memory>


template<class T>
class ThreadHandlerBase
{
public:
	// message std::shared_ptr<T> req
	ThreadHandlerBase(std::shared_ptr<T> req) {}

	virtual ~ThreadHandlerBase() {}


protected:
	std::shared_ptr<T> Message_;
};

