#include <stop_token>
#include <memory>
#include <vector>
#include <thread>
#include <iostream>

#include "Mediator.h"



struct IncreaseSalaryCommand
{
	int PersonId;

	void Increase()
	{
		std::cerr << "inside our source code";
	}
};

template<>
struct HandlerOf<IncreaseSalaryCommand>
{
	//here should be repositories,
	//services...



	void Handle(IncreaseSalaryCommand c, std::stop_token token)
	{
		std::cerr << "starting handling IncreaseSalaryCommand";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		c.Increase();
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cerr << "ending handling IncreaseSalaryCommand";
	}
};







int main()
{
	Mediator mediator;

	IncreaseSalaryCommand c{};

	std::stop_token token;

	mediator.Send(c, token);

	return 0;
}










































//template <class Response>
//struct RequestHandlerDelegate
//{
//    void* context;
//    void* function;
//    Response operator()()
//    {
//        return function(context);
//    }
//};



//template<class TRequest, class TResponse>
//struct IPipelineBehaviour
//{
//    TResponse Handle(TRequest Request, std::stop_token token, RequestHandlerDelegate<TResponse> next) = 0;
//};
//


//class CommandHandler : IRequestHandler<Command>
//{
//    virtual void Handle(Command c) override
//    {
//
//    }
//};
