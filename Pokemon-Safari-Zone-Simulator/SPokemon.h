#ifndef SPOKEMON_H
#define SPOKEMON_H
#include "BasePokemon.h"

#include <string>
using namespace std;

class SPokemon : public BasePokemon
{
private:
	string pokemonName; //holds name of pokemon species
	
public:
	SPokemon(int, int, string); //constructor initalizes 
	~SPokemon(); //currently unused destructor
	int CatchChance(); //calculates the chance for the pokemon to be caught
	int FleeChance(); //calculates the chance the pokemon flees

};

#endif