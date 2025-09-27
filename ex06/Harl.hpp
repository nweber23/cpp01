#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	public:
		Harl();
		~Harl();
		void complain(std::string level);
	private:
		void debug();
		void info();
		void warning();
		void error();
		using Action = void(Harl::*)();
		Action _actions[4];
		static const std::string _levels[4];
};

#endif