#pragma once





template <class command>
struct HandlerOf
{
	void Handle(command c, std::stop_token token) {}
};


struct MyConcept
{
	virtual ~MyConcept() {}
	virtual void Handle(std::stop_token token) = 0;
};

template<class C, class H = HandlerOf<C>>
struct model : MyConcept
{
	model(C c) : command(std::move(c)), handler(H()) {}

	virtual ~model() {}
	virtual void Handle(std::stop_token token)
	{
		handler.Handle(command, token);
	}
	C command;
	H handler;
};

class Handler
{
public:
	template<class Command>
	Handler(Command c) : self(std::make_shared<model<Command>>(std::move(c)))
	{
	}


	virtual void Handle(std::stop_token token)
	{
		std::cerr << "handling user command.";
		self->Handle(token);
	}

	std::shared_ptr<MyConcept> self;
};




class Mediator
{
public:

	template <class Command >
	void Send(Command c, std::stop_token token)
	{
		Handler h{std::move(c)};
		h.Handle(token);
	}
};

