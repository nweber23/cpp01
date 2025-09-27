#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac == 2)
	{
		harl.complain(av[1]);
		return 0;
	}
	std::string tests[] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};
	for (const auto& t : tests) {
		std::cout << "== " << t << " ==\n";
		harl.complain(t);
	}
	return 0;
}