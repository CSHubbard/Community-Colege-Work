//Developer: Cody Hubbard
//5/11/2015
//Pokemon Safari Zone Simulator

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <limits>

#include <stdlib.h> //used for rand
#include <time.h> //used for rand

#include "BasePokemon.h" //classes to be included
#include "SPokemon.h"
#include "BillsPC.h"

using namespace std;

//prototypes

struct PokemonStats
{
	string NameofPokemon; //name of species
	int BaseRates[2];  // catch,flee rates
	int pokemonHP; //hit points
};

void SearchCatchMain();
void SearchCatchBody(string, int[], int, SPokemon&);
void ViewStats();
bool checkLeave();
void exitSafariZone();
bool checkallcaught();

//declarations
string Name;
int defaultlevel = 30;
int SafariBalls = 30;
int Action;
bool Leave = false;
bool AllPokemonCaught = false;

BillsPC<string> mainPC;

//stats	(name, {catch, flee}, HP)
PokemonStats pkmnStats[12] = 
{
	{	"BULBASAUR", {65, 35}, 67 },
	{	"CHARMANDER",{60, 40}, 63 },
	{	"SQUIRTLE", {55, 45}, 66 },
	{	"PIDGEOTTO", {60, 40}, 77 },
	{	"PIKACHU", {50, 50}, 61 },
	{	"SANDSHREW", {50, 50}, 70 },
	{	"VULPIX", {40, 60}, 62 },
	{	"JIGGLYPUFF", {45, 55}, 109 },
	{	"MEOWTH", {45, 55}, 64 },
	{	"STARYU", {65, 55}, 58 },
	{	"SCYTHER", {35, 65}, 82 },
	{	"MAGIKARP", {75, 25}, 52 },
};


int main()
{
srand((unsigned int)time(NULL)); //random seed

//for (int i = 0; i <12; i++)
//{
//	mainPC.insertslot(pkmnStats[i].NameofPokemon);
//}
//
//mainPC.displayInOrder();

cout << "Please enter your name: ";
getline(cin, Name);

cout << endl;			//ascii art
cout << endl;
cout << endl;
cout << "                                     .::.\n";
cout << "                                   .;:**'            \n";
cout << "                                   `                  \n";
cout << "       .:XHHHHk.              db.   .;;.     dH  MX   \n";
cout << "     oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN\n";
cout << "     QMMMMMb  'MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM\n";
cout << "       `MMMM.  )M> :X!Hk. MMMM   XMM.o'  .  MMMMMMM X?XMMM MMM>!MMP\n";
cout << "        'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `` MX MMXXMM \n";
cout << "         ~MMMMM~ XMM. .XM XM`'MMMb.~* ? ** MMX M N MMbooMM XMMMMMP\n";
cout << "          ?MMM>  YMMMMMM! MM   `?MMRb.    ` '''  !L'MMMMM XM IMMM\n";
cout << "           MMMX   'MMMM'  MM       ~%:           !Mh.''' dMI IMMP\n";
cout << "           'MMM.                                              IMX\n";
cout << "            ~M!M                                              IMP\n";
cout << "                              SAFARI ZONE SIMULATOR              \n";
cout << endl;
cout << endl;

cout << "Hello " <<Name <<", Welcome to the Pokemon Safari Zone Simulator!\n";			//intro-Explanations
cout << "Press enter to continue.";
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
cout << endl;


cout << "During the simulation you will experience the basic Pokemon catching mechanics.\n";
cout << "Press enter to continue.";
cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
cout << endl;

cout << "You have been given 30 Safari Balls to catch Pokemon with.\n";
cout << "You may also throw mud or bait to affect your odds of catching \n   the Pokemon you find!\n";
cout << "There are twelve possible Pokemon to catch.\n";
cout << "The simulation will end once you have caught one of each species of Pokemon,\n   or when you run out of Safari Balls.\n";
cout << "You may also choose to leave the Safari Zone at any time. \n";
cout << endl;

cout << "Good luck!\n";
cout << "Press enter to continue.";
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
cout << endl;
																	//end of Intro-Expalations

do
{
	int Action = 0; //initalizes Action for the begining of the loop

	cout <<endl <<endl;
	cout << "The Pokemon Safari Zone spans before you.\n";
	cout << "You have " <<SafariBalls  <<" Safari Balls what will you do?" << endl;
	cout << "1.Search for Pokemon    2.View the Pokemon you have caught\n";
	cout << "3.Leave the Safari Zone\n\n";
	cout << "Enter the number (1-3) of the action you will take. \n";
	cin >> Action;

	while (Action != 1 && Action != 2 && Action != 3) //this checks to make sure a correct input is entered for the Action
	{
		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		cout << endl;

		cout <<endl <<endl;
		cout << "The Pokemon Safari Zone spans before you.\n";
		cout << "You have" <<SafariBalls  <<" Safari Balls what will you do?" << endl;
		cout << "1.Search for Pokemon    2.View the Pokemon you have caught\n";
		cout << "3.Leave the Safari Zone\n\n";
		cout << "Enter the number (1-3) of the action you will take. \n";
		cin >> Action;
	}
	 //these if statements will call the appropriate Action-fucntion and then reset the Action
	if (Action == 1) //Search and try to Catch a Pokemon
	{
		SearchCatchMain();
		Action = 0;
	}

	if (Action == 2) //View Pokemon Caught
	{
		ViewStats();
		Action = 0;
	}

	if (Action == 3) //LeaveSafariZone
	{
		char checkLeave; //will be used to confirm the user wants to leave

		cout << endl << endl;
		cout << "You still have " <<SafariBalls <<" Safari Balls left.\n";
		cout << "Are you sure you want to leave the Safari Zone? \n(enter 'y' or 'Y' for yes and 'n' or 'N' for no.)\n";
		cin >> checkLeave;

		while (toupper(checkLeave) != 'Y' && toupper(checkLeave) != 'N') //entry validation check
		{
			cout << endl;
			cout << endl << "Your input is invalid, please try again.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue.\n";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cout << endl;

			cout << endl << endl;
			cout << "You still have " <<SafariBalls <<" Safari Balls left.\n";
			cout << "Are you sure you want to leave the Safari Zone? \n(enter 'y' or 'Y' for yes and 'n' or 'N' for no.)\n";
			cin >> checkLeave;

		}

		if (toupper(checkLeave) == 'Y')
		{
			Leave = true;
		}

		if (toupper(checkLeave) == 'N')
		{
		}
		Action = 0;
	}

	//checks to see if one of each pokemon was caught
	if ( checkallcaught() == true )
	{ AllPokemonCaught = true; }

} while ((SafariBalls > 0) && (Leave == false) && (AllPokemonCaught == false));

if (AllPokemonCaught == true)
{
	cout <<"Wow! It looks like you've caught one of each Pokemon!\n";
	cout << "Press enter to continue.\n";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << endl;
	cin.clear();
	exitSafariZone();
}

else if (SafariBalls == 0)
{
	cout << "It looks like you have used up all of your Safari Balls!\n";
	cout << "Press enter to continue.\n";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << endl;
	cin.clear();
	exitSafariZone();
}

else if (Leave == true)
{
	cout << "\n\nThank you for visiting the Safari Zone!\n Come back anytime!\n";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << "Press enter to continue.\n";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << endl;
	cin.clear();
	exitSafariZone();
}


}

void SearchCatchMain() //parent function for the SearchCatch Acton
{


	int randMon = rand() % 100; //initalises randMon to a random number which will determine what pokemon is found

	int areachoice = 0;	//initalizes areachoice for the begining of the loop

	cout <<endl <<endl;
	cout << "You decide to search the Safari Zone for Pokemon.\n";
	cout << "Where will you look?\n";
	cout << "1.The Grass    2.The Sea\n";
	cout << "3.The Caves    4.The Plains\n\n";
	cout << "Enter the number (1-4) of the action you will take. \n";
	cin >> areachoice;

	while (areachoice != 1 && areachoice != 2 && areachoice != 3 && areachoice != 4) //this checks to make sure a correct input is entered for the Action
	{
		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		cout << endl;

		cout <<endl <<endl;
		cout << "You decide to search the Safari Zone for Pokemon.\n";
		cout << "Where will you look?\n";
		cout << "1.The Grass    2.The Sea\n";
		cout << "3.The Caves    4.The Plains\n\n";
		cout << "Enter the number (1-4) of the action you will take. \n";
		cin >> areachoice;
	}

	string area = " "; //initalizes area name for output

	if (areachoice == 1)
		{ 	area = "grass"; }
	if (areachoice == 2)
		{ 	area = "sea"; }
	if (areachoice == 3)
		{ 	area = "caves"; }
	if (areachoice == 4)
		{ 	area = "plains"; }
		

	cout <<endl <<endl; 
	cout << "You search the " <<area <<" for Pokemon.....\n";
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << "Press enter to continue.";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << endl;

if (areachoice == 1) //grass zone
{

	if (randMon < 35)
	{
		SPokemon Bulbasaur(pkmnStats[0].BaseRates[0], pkmnStats[0].BaseRates[1], pkmnStats[0].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[0].NameofPokemon, pkmnStats[0].BaseRates, pkmnStats[0].pokemonHP, Bulbasaur); //passes specific pokemons info to the main function
	}

		if (randMon >= 36 && randMon <= 75)
	{
		SPokemon Pickachu(pkmnStats[4].BaseRates[0], pkmnStats[4].BaseRates[1], pkmnStats[4].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[4].NameofPokemon, pkmnStats[4].BaseRates, pkmnStats[4].pokemonHP, Pickachu); //passes specific pokemons info to the main function
	}
			
		if (randMon >= 76 && randMon <= 99)
	{
		SPokemon Scyther(pkmnStats[10].BaseRates[0], pkmnStats[10].BaseRates[1], pkmnStats[10].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[10].NameofPokemon, pkmnStats[10].BaseRates, pkmnStats[10].pokemonHP, Scyther); //passes specific pokemons info to the main function
		}
}


if (areachoice == 2) //sea zone
{

		if (randMon < 45)
	{
		SPokemon Magikarp(pkmnStats[11].BaseRates[0], pkmnStats[11].BaseRates[1], pkmnStats[11].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[11].NameofPokemon, pkmnStats[11].BaseRates, pkmnStats[11].pokemonHP, Magikarp); //passes specific pokemons info to the main function
	}
		if (randMon >= 46 && randMon <= 70)
	{
		SPokemon Squirtle(pkmnStats[2].BaseRates[0], pkmnStats[2].BaseRates[1], pkmnStats[2].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[2].NameofPokemon, pkmnStats[2].BaseRates, pkmnStats[2].pokemonHP, Squirtle); //passes specific pokemons info to the main function
	}

		if (randMon >= 71 && randMon <= 99)
	{
		SPokemon Staryu(pkmnStats[9].BaseRates[0], pkmnStats[9].BaseRates[1], pkmnStats[9].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[9].NameofPokemon, pkmnStats[9].BaseRates, pkmnStats[9].pokemonHP, Staryu); //passes specific pokemons info to the main function
	}
}


if (areachoice == 3) //cave zone
{

		if (randMon < 35)
	{
		SPokemon Charmander(pkmnStats[1].BaseRates[0], pkmnStats[1].BaseRates[1], pkmnStats[1].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[1].NameofPokemon, pkmnStats[1].BaseRates, pkmnStats[1].pokemonHP, Charmander); //passes specific pokemons info to the main function
	}
		if (randMon >= 36 && randMon <= 80)
	{
		SPokemon Sandshrew(pkmnStats[5].BaseRates[0], pkmnStats[5].BaseRates[1], pkmnStats[5].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[5].NameofPokemon, pkmnStats[5].BaseRates, pkmnStats[5].pokemonHP, Sandshrew); //passes specific pokemons info to the main function
	}

		if (randMon >= 81 && randMon <= 99)
	{
		SPokemon Vulpix(pkmnStats[6].BaseRates[0], pkmnStats[6].BaseRates[1], pkmnStats[6].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[6].NameofPokemon, pkmnStats[6].BaseRates, pkmnStats[6].pokemonHP, Vulpix); //passes specific pokemons info to the main function
	}
}


if (areachoice == 4) //plains zone
{

		if (randMon < 45)
	{
		SPokemon Pidgeotto(pkmnStats[3].BaseRates[0], pkmnStats[3].BaseRates[1], pkmnStats[3].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[3].NameofPokemon, pkmnStats[3].BaseRates, pkmnStats[3].pokemonHP, Pidgeotto); //passes specific pokemons info to the main function
	}
		if (randMon >= 46 && randMon <= 70)
	{
		SPokemon Jigglypuff(pkmnStats[7].BaseRates[0], pkmnStats[7].BaseRates[1], pkmnStats[7].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[7].NameofPokemon, pkmnStats[7].BaseRates, pkmnStats[7].pokemonHP, Jigglypuff); //passes specific pokemons info to the main function
	}

		if (randMon >= 71 && randMon <= 99)
	{
		SPokemon Meowth(pkmnStats[8].BaseRates[0], pkmnStats[8].BaseRates[1], pkmnStats[8].NameofPokemon);  //creates a SPokemon object of use in calcuations
		SearchCatchBody(pkmnStats[8].NameofPokemon, pkmnStats[8].BaseRates, pkmnStats[8].pokemonHP, Meowth); //passes specific pokemons info to the main function
	}
}

}
	

void SearchCatchBody(string pkmnName, int basestats[], int pkmnHP, SPokemon &FoundPokemon)		//displays primary inforamtion and holds logic for the SearchCatch function
{
		//function declarations
		int tAction;
		int wCatch, wFlee;
		bool fled = false;
		bool caught = false;

		cout << "A wild " << pkmnName << " appears! \n";
		cout << "Press enter to continue.\n";
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		cout << endl;

		do
		{
		cout << endl << endl;
		cout << pkmnName <<": Lv." <<defaultlevel <<"\nHP:" << pkmnHP << "/" << pkmnHP << endl; //displays HP
		cout << SafariBalls <<" Safari Balls remain.\n";
		cout << "What will " <<Name << " throw?" <<endl;
		cout << "1.Ball		2.Bait		3.Mud		4.Run\n\n";
		cout << "Enter the number (1-4) of the action you will take.\n";
		cin >> tAction; //get users action

		while (tAction !=1 && tAction !=2 && tAction !=3 && tAction!=4) //this checks to make sure a correct input is entered for the Action
		{
		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;

		cout << endl << endl;
		cout << pkmnName <<": Lv." <<defaultlevel <<"\nHP:" << pkmnHP << "/" << pkmnHP << endl; //displays HP
		cout << SafariBalls <<" Safari Balls remain.\n";
		cout << "What will " <<Name << " throw?" <<endl;
		cout << "1.Ball		2.Bait		3.Mud		4.Run\n\n";
		cout << "Enter the number (1-4) of the action you will take.\n";
		cin >> tAction; //get users action
		}																//end of check


		if (tAction == 1 && SafariBalls > 0) //use a safari ball
		{
			wCatch = rand() % 100; //makes a random value that the catch rate must succeed for the mon to be caught
			wFlee = rand() % 100; //makes a random value that the flee rate must succeed for the mon to flee

			cout << endl;
			cout << Name <<" used one Safari Ball!\n";
			cout << "The Pokemon entered the ball, The ball shakes as the Pokemon struggles inside!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue.\n";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

			if (wCatch <= FoundPokemon.CatchChance()) //calculates and compares chance to catch to see if catch succeeds
			{
				cout << "Gotcha! \n" << pkmnName <<" was caught!\n";
				cout << "Press enter to continue.\n";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				
				mainPC.insertslot(pkmnName); //this stores the caught pokemon in DefaultPC(binary tree)

				caught = true;
			}

			if (wCatch > FoundPokemon.CatchChance())
			{
				cout << "Oh, no! \n";
				cout << "The Pokemon broke free!\n";

				if (wFlee < FoundPokemon.FleeChance())
				{
				cout << "The wild " <<pkmnName <<" fled!\n";
				cout << "Press enter to continue.\n";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				fled = true;
				}

				else
				{
					cout << "The " <<pkmnName <<" is watching carefully!\n";
					cout << "Press enter to continue.\n";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				}

			}
			SafariBalls--;
			tAction = 0;
		}

		if ( tAction == 1 && SafariBalls == 0) //no Safari Balls left
		{
			cout <<endl;
			cout << "You don't have any Safari Balls left!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue.\n";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

			tAction = 0;
		}

		if (tAction == 2) //throw bait
		{
			wFlee = rand() % 100; //makes a random value that the flee rate must succeed for the mon to flee

			cout << endl;
			cout << Name <<" threw some Bait at the " <<pkmnName <<"!\n" ;
			cout << pkmnName <<" is eating!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue.\n";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

			FoundPokemon.decCRate();
			FoundPokemon.decFRate();

			if (wFlee < FoundPokemon.FleeChance())
				{
				cout << "The wild " <<pkmnName <<" fled!\n";
				cout << "Press enter to continue.\n";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				fled = true;
				}

			else
				{
					cout << "The " <<pkmnName <<" is watching carefully!\n";
					cout << "Press enter to continue.\n";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				}
			tAction = 0;
		}

		if (tAction == 3) //throw mud
		{
			wFlee = rand() % 100; //makes a random value that the flee rate must succeed for the mon to flee

			cout << endl;
			cout << Name <<" threw Mud at the " <<pkmnName <<"!\n" ;
			cout << pkmnName <<" is angry!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue.\n";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

			FoundPokemon.incCRate();
			FoundPokemon.incFRate();

			if (wFlee < FoundPokemon.FleeChance())
				{
				cout << "The wild " <<pkmnName <<" fled!\n";
				cout << "Press enter to continue.\n";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				fled = true;
				}

			else
				{
					cout << "The " <<pkmnName <<" is watching carefully!\n";
					cout << "Press enter to continue.\n";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				}
			tAction = 0;
		}

		if (tAction == 4)
		{
			cout << endl;
			cout << "Got away safely!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue.\n";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			fled = true;
			tAction = 0;
		}


	} while (fled == false && caught == false);
}

void ViewStats()		//displays the pokemon caught so far
{
	bool HaveOne = false; //tracks to see if atleast one pokemon was caught
	string pkmnName;
	int numCaught;

	cout <<endl <<endl;
	cout << "You view the Pokemon you have caught in the Safari Zone.....\n";
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << "Press enter to continue.";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << endl;

	cout <<endl;
	cout << "You have caught\n";
	for (int index = 0; index < 12; index++) //this will cycle throuch all 12 pokemon to see which have been caught, then display those that have.
	{
		pkmnName = pkmnStats[index].NameofPokemon;
		numCaught = mainPC.displayCount(pkmnName);

		if ( numCaught > 0)
		{
			HaveOne = true;
			cout << numCaught << " " << pkmnName <<".\n";
		}
	}

	 if (HaveOne == false )
	{
			cout << "Oh! It dosn't look like you have caught any Pokemon.\n";
	}
	cout << "Press enter to continue.";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cout << endl;
}

bool checkallcaught()
{
	int typescaught = 0;
	for (int index=0; index < 12; index++)
	{
		if (mainPC.searchslot(pkmnStats[index].NameofPokemon) == true)
		{ typescaught += 1; }
	}
	if ( typescaught == 12)
		return true;
	else
		typescaught = 0;
		return false;
}

void exitSafariZone()
{
//askii art
cout << endl;
cout << endl;
cout << endl;
cout << "                                     .::.\n";
cout << "                                   .;:**'            \n";
cout << "                                   `                  \n";
cout << "       .:XHHHHk.              db.   .;;.     dH  MX   \n";
cout << "     oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN\n";
cout << "     QMMMMMb  'MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM\n";
cout << "       `MMMM.  )M> :X!Hk. MMMM   XMM.o'  .  MMMMMMM X?XMMM MMM>!MMP\n";
cout << "        'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `` MX MMXXMM \n";
cout << "         ~MMMMM~ XMM. .XM XM`'MMMb.~* ? ** MMX M N MMbooMM XMMMMMP\n";
cout << "          ?MMM>  YMMMMMM! MM   `?MMRb.    ` '''  !L'MMMMM XM IMMM\n";
cout << "           MMMX   'MMMM'  MM       ~%:           !Mh.''' dMI IMMP\n";
cout << "           'MMM.                                              IMX\n";
cout << "            ~M!M                                              IMP\n";
cout << "                               BATTLE SIMULATOR                \n";
cout << endl;
cout << endl;

bool HaveOne = false; //tracks to see if atleast one pokemon was caught

//used to see if any pokemon were caught
string pkmnName;	//holds the name of a pokemon
int numCaught;		//holds how many were caught

string Exit; //declaration for exit

ofstream score;	//this will write the users score to a text file
score.open("Scores.txt", fstream::app);
score <<endl <<"Trainer " <<Name + " had " <<SafariBalls <<" Safari Balls remaining and caught";

for (int index = 0; index < 12; index++) //this will cycle throuch all 12 pokemon to see which have been caught, then store those that have.
	{
		pkmnName = pkmnStats[index].NameofPokemon;
		numCaught = mainPC.displayCount(pkmnName);

		if ( numCaught > 0)
		{
			HaveOne = true;
			score <<endl <<numCaught << " " << pkmnName <<".";
		}
	}
if (HaveOne == false )
	{
		score << " no Pokemon.\n";
	}
score.close();

cout << endl << endl;
cout << "This concludes the Pokemon Safari Zone Simulator\n";
cout << "Please type 'Exit' to close the Safari Zone Simulator\n or type 'Scores' to see how previous users have scored.\n";
getline(cin, Exit);

while (Exit != "Exit" && Exit != "exit" && Exit != "Scores" && Exit != "scores")
{
	cout << endl << endl;
	cout << endl << "Your input is invalid, please try again.\n";
	cout << "Press enter to continue.\n";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

	cout << endl << endl;
	cout << "Please type 'Exit' to close the Pokemon Safari Zone Simulator\n or type 'Scores' to see how you and previous users have scored.\n";
	getline(cin, Exit);
}

if (Exit == "Exit" || Exit == "exit")
{
	cout << endl;
	cout << "Thank You!\n";
	cout << "Press enter to close the Pokemon Safari Zone Simulator.\n";
	std::cin.get();
	exit(0);
}

if (Exit == "Scores" || Exit == "scores")
{
	string Display; //used to hold line of Scores to be displayed

	cout << "\nThese are the previously recorded scores: \n";
	ifstream score;
	score.open("Scores.txt");

	while (score.good())
	{
		getline(score, Display);
		cout << Display << endl;
	}		
	score.close();

	cout << endl;
	cout << "Thank You!\n";
	cout << "Press enter to close the Pokemon Safari Zone Simulator.\n";
	std::cin.get();
	exit(0);
}
}