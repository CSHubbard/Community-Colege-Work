#include "SPOKEMON.h"
using namespace std;
#include <iostream>


SPokemon::SPokemon(int BCRate, int BFRate, string pkmnname)	: BasePokemon(BCRate, BFRate)	//constructor initalizes variables
	{
		pokemonName = pkmnname;
	}

int SPokemon::CatchChance()		//calculates and returns chance the pokemon will be caught
{
	return (basecatchRate+(10*CRateInc)-(10*CRateDec));
}

int SPokemon::FleeChance()		//calculates and returns chance the pokemon will flee
{
	return (basefleeRate+(10*FRateInc)-(10*FRateDec));
}

SPokemon::~SPokemon()
{
}