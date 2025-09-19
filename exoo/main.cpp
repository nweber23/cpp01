#include "Zombie.hpp"

int main()
{
	randomChump("StackZombie");
	randomChump("AnotherStackZombie");

	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	Zombie stackZombie;
	stackZombie.setName("AnotherStackZombie");
	stackZombie.announce();

	return 0;
}