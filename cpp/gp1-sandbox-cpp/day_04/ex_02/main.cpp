#include <iostream>
#include "non_playable_character.h"
#include "playable_character.h"
using namespace day_04::ex_02;
int main()
{
// object o; // must not compile
{
entity en;
std::cout << en.to_string() << ", entity life: " << en.life() << std::endl;
const object& o = en;
std::cout << "Entity as object: " << o.to_string().c_str() << std::endl;
}
{
non_playable_character pnj1;
playable_character player;
// const entity& e = pnj1; // must not compile
// const object& e = player; // must not compile
std::cout << pnj1.to_string() << std::endl;
std::cout << player.to_string() << std::endl;
std::cout << "pnj1 life : " << std::endl;
pnj1.print_life();
std::cout << "player life : " << std::endl;
player.print_life();
++pnj1;
++player;
std::cout << "pnj1 life : " << std::endl;
pnj1.print_life();
std::cout << "player life : " << std::endl;
player.print_life();
// std::cout << pnj1.life() << std::endl; //must not compile : inaccessible
// std::cout << player.life() << std::endl; //must not compile : inaccessible
player * pnj1;
std::cout << "pnj1 life : " << std::endl;
pnj1.print_life();
std::cout << "player life : " << std::endl;
player.print_life();
(player * pnj1) * pnj1;
// pnj1 * player; //must not compile : not match operator
std::cout << "pnj1 life : " << std::endl;
pnj1.print_life();
std::cout << "player life : " << std::endl;
player.print_life();
}
return EXIT_SUCCESS;
}