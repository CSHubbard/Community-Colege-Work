#ifndef BASEPOKEMON_H
#define BASEPOKEMON_H

//this is a base class that will be used for all pokemon in the program

class BasePokemon
{
protected:
	int basecatchRate;	//base threshhold the pokemon will be caught
	int basefleeRate;	//base threshhold the pokemon will flee
	int CRateInc;	//tracks the numer of times the catch rate has been increased
	int CRateDec;	//tracks the numer of times the catch rate has been decreased
	int FRateInc;	//tracks the numer of times the flee rate has been increased
	int FRateDec;	//tracks the numer of times the flee rate has been Decreased

public:
	BasePokemon();
	BasePokemon(int, int);	//constructors
	~BasePokemon();			//destructor currently unused

	void incCRate();	//increases catch rate
	void decCRate();	//decreases  catch rate
	void incFRate();	//increases  flee rate
	void decFRate();	//decreases  flee rate
};

#endif