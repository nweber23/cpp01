#include "Harl.hpp"

const std::string Harl::_levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {
	_actions[0] = &Harl::debug;
	_actions[1] = &Harl::info;
	_actions[2] = &Harl::warning;
	_actions[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info() {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error() {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == _levels[i])
		{
			index = i;
			break ;
		}
	}
	if (index == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return ;
	}
	(this->*_actions[index])();
}