#include "BasePokemon.h"
#include <iostream>
using namespace std;

//member functions for base class "Pokemon"


	int basecatchRate;	//default threshhold the pokemon will be caught
	int basefleeRate;	//default threshhold the pokemon will flee
	int CRateInc;	//tracks the numer of times the catch rate has been increased
	int CRateDec;	//tracks the numer of times the catch rate has been decreased
	int FRateInc;	//tracks the numer of times the flee rate has been increased
	int FRateDec;	//tracks the numer of times the flee rate has been Decreased

	BasePokemon::BasePokemon()
	{
		CRateInc = 0;
		CRateDec = 0;
		FRateInc = 0;
		FRateDec = 0;
	}

	BasePokemon::BasePokemon(int BaseCR, int BaseFR)
	{
		basecatchRate = BaseCR;
		basefleeRate = BaseFR;
	}

	BasePokemon::~BasePokemon()
	{
	}

	void BasePokemon::incCRate()	//increases catch rate
	{ if (CRateInc<6)
		{CRateInc++;}
	}
	void BasePokemon::decCRate()	//decreases catch rate
	{	if (CRateDec<6)
		{CRateDec++; }
	}
	void BasePokemon::incFRate()	//increases flee rate
	{ if (FRateInc<6)
		{FRateInc++; }
	}
	void BasePokemon::decFRate()	//decreases flee rate
	{ if (FRateDec<6)
		{FRateDec++; }
	}