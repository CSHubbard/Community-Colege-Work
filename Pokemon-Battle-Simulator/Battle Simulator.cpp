// Developer: Cody Hubbard
//3/17/2014
//Pokemoon Battle Simulator

#include <iostream>
#include <iomanip>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  
#include <string>
#include <cstdlib>
#include<fstream>
using namespace std;

//prototypes

int ItemUse();
int BulbaBattle();
int BulbaAttack(int);
int WartortleBattle();
int WartortleAttack(int);
int CharBattle();
int CharAttack(int);
double DamageCalc(int, double, double[], double[], int, int, int);


//declarations&constants

//Damage = ((((2 * Level / 5 + 2) * AttackStat * AttackPower / DefenseStat) / 50) + 2) * STAB * Weakness/Resistance * RandomNumber / 100

//stats
double PikaLVL = 25;
double PikaHp[2] = { 60, 60 };			
double PikaStats[5] = { 36, 32, 50, 37, 57};//Atk, Def, SpAtk, SDef, Spd						
int QuickAttackDamage = 40, ThunderShockDamage = 40;//move Damage

double BulbaLVL = 15;
double BulbaHp[2] = { 43, 43 };
double BulbaStats[5] = { 21, 24, 31, 29, 23};//Atk, Def, SpAtk, SDef, Spd						
int TackleDamage = 50, VineWhipDamage = 45;//move Damage

double WartortleLVL = 20;
double WartortleHp[2] = { 59, 59};
double WartortleStats[5] = { 36, 43, 37, 43, 34};//Atk, Def, SpAtk, SDef, Spd					
int WaterGunDamage = 40, BiteDamage = 60;//move Damage

double CharLVL = 25;
double CharHp[2] = { 71, 71 };
double CharStats[5] = { 44, 41, 52, 45, 52}; //Atk, Def, SpAtk, SDef, Spd						
int EmberDamage = 40, ScratchDamage = 40, DargonRageDamage = 40; //move Damage

double BaseAttack[4] = {36, 21, 36, 44}; //pika, bulba, wartortle, char
double BaseDefense[4] = {32, 24, 43, 41}; //pika, bulba, wartortle, char
double ReductionStages[6] = {.67, .50, .40, .33, .29, .25};
double IncreaseStages[6] = {1.5, 2, 2.5, 3, 3.5, 4};
int TimesReducedPikaAtk = 0;
int TimesReducedPikaDef = 0;
int TimesReducedOppAtk = 0;
int TimesReducedOppDef = 0;
int TimesRaisedOppAtk = 0;
int TimesRaisedOppDef = 0;//these are all used for moves that increase and decrease stats

//Items
int Potions = 3;
int SuperPotions = 1;
int OranBerries = 4;
int MooMooMilk = 1;
int PokeBalls = 5;

//function declarations
int turns=0;
string Name = " ";
string CurrentPokemonFaced;

int main()
{
	srand((unsigned int)time(NULL)); //reandom seed
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
cout << "                               BATTLE SIMULATOR                \n";
cout << endl;
cout << endl;


cout << "Hello " <<Name <<", Welcome to the Pokemon Battle Simulator!\n";			//intro-Explanations
cout << "Press enter to continue.";
std::cin.get();
cout << endl;


cout << "During the simulation you will experience the basic Pokemon battling mechanics.\n";
cout << "Press enter to continue.";
std::cin.get();
cout << endl;


cout << "You have been given a level 25 Pikachu to battle with.\n";
cout << "This is the only Pokemon avalible to you, treat it well!\n";
cout << "You will be facing another trainer, he will have three Pokemon.\n";
cout << "The simulation will end once you have fainted all three of the\n   opposing Pokemon, or the opponent has fainted your Pikachu.\n";
cout << endl;
cout << "Good luck!\n";
cout << "Press enter to continue.";
std::cin.get();
cout << endl;
cout << endl;

cout << "Youngster Joey challenges you to battle!\n";
cout << "Youngster Joey says:\n   -You'll never beat my Pokemon, the're in the top 10 percentage of Pokemon!\n";
cout << "Press enter to start the battle!\n";
std::cin.get();
cout << endl;

cout << "Youngster Joey sent out Bulbasaur!\n";
cout << "You send out Pikachu!\n";
cout << "Press enter to continue.\n";
std::cin.get();
cout << endl;

//function declarations


//BATTLE START
CurrentPokemonFaced = "Bulba";
do
{
	//function declarations
	int move = 0;
	int Action = 0;
	cout << endl << endl;
	cout << "Bulbasaur: Lv." <<BulbaLVL <<"\nHP:" << static_cast<int>(BulbaHp[0]) << "/" << static_cast<int>(BulbaHp[1]) << endl; //displays HP
	cout << "Pikachu: Lv." << PikaLVL <<endl <<"Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
	cout << "What will you do?" << endl;
	cout << "1.Use a Move     2.Use an Item\n\n";
	cout << "Enter the number (1-2) of the action you will take.\n";
	cin >> Action;

	while (Action != 1 && Action != 2) //checks makes sure a correct vaule is enetered for Action
	{
		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		std::cin.get();
		cout << endl;

		cout << endl << endl;
		cout << "Bulbasaur: Lv." << BulbaLVL << "\nHP:" << static_cast<int>(BulbaHp[0]) << "/" << static_cast<int>(BulbaHp[1]) << endl; //displays HP
		cout << "Pikachu: Lv." << PikaLVL << endl << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
		cout << "What will you do?" << endl;
		cout << "1.Use a Move     2.Use an Item\n\n";
		cout << "Enter the number (1-2) of the action you will take.\n";
		cin >> Action;
	}

	if (Action == 1) //Use a Move
	{
		BulbaBattle();
		Action = 0;
	}
	
	if (Action == 2)	//Use an Item
	{
		ItemUse();
		Action = 0;
	}
	
} while ((PikaHp[0] > 0) && (BulbaHp[0] > 0));

while ((PikaHp[0] < 0) && (BulbaHp[0] > 0)) //lose to Bulba
{
	cout << "Pikachu fainted!\n";
	cout << "Youngster Joey says:\n   -You lost! Haha, I told you my Pokemon were good!\n";
	cout << "Press enter to continue.\n";
	std::cin.get();
	cout << endl;
	cout << "You may have lost but its not the end " << Name << ", please try again!\n";
	cout << "Press enter to close the Battle Simulator.\n";
	std::cin.get();
	exit(0);
}

//fainted Bulba info
cout << "The opposing Bulbasaur fainted!\n";
cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
cout << "Press enter to continue.\n";
std::cin.get();
cout << endl;

cout << "Youngster Joey sent out Wartortle!\n";
cout << "Press enter to continue.\n";
std::cin.get();
cout << endl;

//BATTLE STAGE 2 START

TimesReducedOppAtk = 0;
TimesReducedOppDef = 0;
TimesRaisedOppAtk = 0;
TimesRaisedOppDef = 0;//reset because the opponent changed

CurrentPokemonFaced = "Wartortle";
do
{
	//function declarations
	int move = 0;
	int Action = 0;

	cout << "Wartortle: Lv." << WartortleLVL << "\nHP:" << static_cast<int>(WartortleHp[0]) << "/" << static_cast<int>(WartortleHp[1]) << endl; //displays HP
	cout << "Pikachu: Lv." <<PikaLVL <<endl <<"Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
	cout << "What will you do?" << endl;
	cout << "1.Use a Move     2.Use an Item\n";
	cout << "Enter the number (1-2) of the action you will take.\n";
	cin >> Action;

	while (Action != 1 && Action != 2)
	{

		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		std::cin.get();
		cout << endl;

		cout << "Wartortle: Lv." << WartortleLVL << "\nHP:" << static_cast<int>(WartortleHp[0]) << "/" << static_cast<int>(WartortleHp[1]) << endl; //displays HP
		cout << "Pikachu: Lv." << PikaLVL << endl << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
		cout << "What will you do?" << endl;
		cout << "1.Use a Move     2.Use an Item\n";
		cout << "Enter the number (1-2) of the action you will take.\n";
		cin >> Action;
	}

	if (Action == 1) //Use a Move
	{
		WartortleBattle();
		Action = 0;
		turns++;
	}

	if (Action == 2)	//Use an Item
	{
		ItemUse();
		Action = 0;
		turns++;
	}
} while ((PikaHp[0] > 0) && (WartortleHp[0] > 0));

while ((PikaHp[0] < 0) && (WartortleHp[0] > 0)) //lost to Wartortle
{
	cout << "Pikachu fainted!\n";
	cout << "Youngster Joey says:\n   -You lost! Haha, I told you my Pokemon were good!\n";
	cout << "Press enter to continue.\n";
	std::cin.get();
	cout << endl;
	cout << "You may have lost but its not the end, please try again!\n";
	cout << "Press enter to close the Battle Simulator.\n";
	std::cin.get();
	exit(0);
}

//fainted Wartortle info
cout << "The opposing Wartortle fainted!\n";
cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
cout << "Press enter to continue.\n";
std::cin.get();
cout << endl;

cout << "Youngster Joey sent out Charmeleon!\n";
cout << "Press enter to continue.\n";
std::cin.get();
cout << endl;

//BATTLE STAGE 3 START

TimesReducedOppAtk = 0;
TimesReducedOppDef = 0;
TimesRaisedOppAtk = 0;
TimesRaisedOppDef = 0;//reset because the opponent changed

CurrentPokemonFaced = "Char";
do
{
	//function declarations
	int move = 0;
	int Action = 0;

	cout << "Charmeleon: Lv." << CharLVL << "\nHP:" << static_cast<int>(CharHp[0]) << "/" << static_cast<int>(CharHp[1]) << endl; //displays HP
	cout << "Pikachu: Lv." << PikaLVL << endl << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
	cout << "What will you do?" << endl;
	cout << "1.Use a Move     2.Use an Item\n";
	cout << "Enter the number (1-2) of the action you will take.\n";
	cin >> Action;

	while (Action != 1 && Action != 2)
	{

		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		std::cin.get();
		cout << endl;

		cout << "Charmeleon: Lv." << CharLVL << "\nHP:" << static_cast<int>(CharHp[0]) << "/" << static_cast<int>(CharHp[1]) << endl; //displays HP
		cout << "Pikachu: Lv." << PikaLVL << endl << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
		cout << "What will you do?" << endl;
		cout << "1.Use a Move     2.Use an Item\n";
		cout << "Enter the number (1-2) of the action you will take.\n";
		cin >> Action;
	}

	if (Action == 1) //Use a Move
	{
		CharBattle();
		Action = 0;
		turns++;
	}

	if (Action == 2)	//Use an Item
	{
		ItemUse();
		Action = 0;
		turns++;
	}
} while ((PikaHp[0] > 0) && (CharHp[0] > 0));

while ((PikaHp[0] < 0) && (CharHp[0] > 0)) //lost to Wartortle
{
	cout << "Pikachu fainted!\n";
	cout << "Youngster Joey says:\n   -You lost! Haha, I told you my Pokemon were good!\n";
	cout << "Press enter to continue.\n";
	std::cin.get();
	cout << endl;
	cout << "You may have lost but its not the end, please try again!\n";
	cout << "Press enter to close the Battle Simulator.\n";
	std::cin.get();
	exit(0);
}

//fainted Charmeleon info
cout << "The opposing Charmeleon fainted!\n";
cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
cout << "Press enter to continue.\n";
std::cin.get();
cout << endl;
cout << "You defeated Youngster Joey!\n";
cout << "Youngster Joey says:\n   -I cant beleive I lost, you sure are stong!\n";
cout << "Press enter to continue.\n";
std::cin.get();
cout << endl;
cout << endl;

//askii art
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

string Exit; //declaration for exit
//goodbye
cout << "You have won!\n";
cout << "It took you " << turns << " turns to defeat Youngster Joey.\n" <<endl;

ofstream score;
score.open("Scores.txt", fstream::app);
score << Name + "---" << turns <<endl;
score.close();

cout << "This concludes the Pokemon Battle Simulator\n";
cout << "Please type 'Exit' to close the Pokemon Battle Simulator\n or type 'Scores' to see how previous users have Scored.\n";
getline(cin, Exit);

while (Exit != "Exit" && Exit != "exit" && Exit != "Scores" && Exit != "scores")
{
	cout << endl;
	cout << endl << "Your input is invalid, please try again.\n";
	cout << "Please type 'Exit' to close the Pokemon Battle Simulator\n or type 'Scores' to see how previous users have Scored.\n";
	getline(cin, Exit);
}

if (Exit == "Exit" || Exit == "exit")
{
	cout << endl;
	cout << "Thank You!\n";
	cout << "Press enter to close the Pokemon Battle Simulator.\n";
	std::cin.get();
	exit(0);
}

if (Exit == "Scores" || Exit == "scores")
{
	cout << "\n These are the previously recorded scores: \n";
	ifstream score;
	string Display;
	score.open("Scores.txt");
	while (score >> Display)
	{
		cout << Display << endl;
	}		
	score.close();

	cout << endl;
	cout << "Thank You!\n";
	cout << "Press enter to close the Pokemon Battle Simulator.\n";
	std::cin.get();
	exit(0);
}
		return 0;
}



//This function calculates the damage of moves
//Damage = ((((2 * Level / 5 + 2) * AttackStat * AttackPower / DefenseStat) / 50) + 2) * STAB * Weakness/Resistance * RandomNumber / 100
double DamageCalc(int MoveDamage, double Level, double AttackerStats[], double DefenderStats[], int STAB, int TypeVantage, int AttackType)
{

	double Damage;	//final value to be calculated and returned
	int StatType;

	int RandomNum = rand() % 15 + 85;
	if (AttackType == 1)//This if statement distinguishes wich stats the damage is calculated with,
	{					//Special Attacks are calculated using each Pokemons respective Special Attack and Special Defense Stats
		StatType = 0;	//Physical Attacks are calculated using each Pokemons respective Attack and Defense Stats
	}
	else if (AttackType == 2)
	{
		StatType = 2;
	}

	Damage = ((((2 * Level / 5 + 2) * AttackerStats[StatType] * MoveDamage / DefenderStats[StatType+1]) / 50) + 2) * STAB * TypeVantage * RandomNum / 100;

	return Damage;
}


//this function handles item use throughout the entire battle
int ItemUse()
{
	int Itemselection;
	char use;
	bool cont = 1;
	int OpMove = rand() % 100;

	do
	{
		cout << endl << endl;
		cout << "These are the items you have avalible:\n 1.Potion x" << Potions << "\n 2.Super Potion x" << SuperPotions << "\n 3.Oran Berry x" << OranBerries
			<< "\n 4.Moomoo Milk x" << MooMooMilk << "\n 5.Poke Ball x" << PokeBalls << endl; //displays items
		cout << "Enter the number (1-5) of an item to see its description and/or us it,\n   or enter '0' to return to the previous menu." << endl;
		cin >> Itemselection; //gets users selection
		
		while (Itemselection != 0 && Itemselection != 1 && Itemselection != 2 && Itemselection != 3 && Itemselection != 4 && Itemselection != 5)//invalid
		{

			cout << endl;
			cout << endl << "Your input is invalid, please try again.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue.\n";
			std::cin.get();
			cout << endl;

			cout << endl << endl;
			cout << "These are the items you have avalible:\n 1.Potion x" << Potions << "\n 2.Super Potion x" << SuperPotions << "\n 3.Oran Berry x" << OranBerries
				<< "\n 4.Moomoo Milk x" << MooMooMilk << "\n 5.Poke Ball x" << PokeBalls << endl; //displays items
			cout << "Enter the number (1-5) of an item to see its description and/or us it,\n   or enter '0' to return to the previous menu." << endl;
			cin >> Itemselection; //gets users selection

		}

		if (Itemselection == 0)
		{
			return 0;
		}

		if (Itemselection == 1)
		{
			if (Potions == 0)
			{
				cout << endl;
				cout << "Oh no! It looks like you dont have any Potions left!\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Press enter to continue the battle!\n";
				std::cin.get();
				cout << endl;
			}
			if (Potions > 0)
			{
				cout << endl << endl;
				cout << "Potion x" << Potions << endl;
				cout << "Descritption: \nA spray-type medicine for wounds.\n It restores the HP of one Pokemon by just 20 points." << endl;
				cout << "Would you like to use the Potion? \n(enter 'y' or 'Y' for yes and 'n' or 'N' for no.)\n";
				cin >> use;
				while (toupper(use) != 'Y' && toupper(use) != 'N')
				{
					cout << endl;
					cout << endl << "Your input is invalid, please try again.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Press enter to continue.\n";
					std::cin.get();
					cout << endl;
				}
				if (toupper(use) == 'Y')
				{
					cout << endl;
					cout << Name << " used a Potion. Pikachu's HP was restored." << endl;
					PikaHp[0] += 20;
					Potions--;
					if (PikaHp[0] > PikaHp[1])
					{
						PikaHp[0] = PikaHp[1];
					}
					cout << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
					cont = 0;
				}
				if (toupper(use) == 'N')
				{
				}
			}
		}

		if (Itemselection == 2)
		{
			if (SuperPotions == 0)
			{
				cout << endl;
				cout << "Oh no! It looks like you dont have any Super Potions left!\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Press enter to continue the battle!\n";
				std::cin.get();
				cout << endl;
			}
			if (SuperPotions > 0)
			{
				cout << endl << endl;
				cout << "Super Potion x" << SuperPotions << endl;
				cout << "Descritption: \nA spray-type medicine for wounds.\n It restores the HP of one Pokemon by 50 points." << endl;
				cout << "Would you like to use the Super Potion? \n(enter 'y' or 'Y' for yes and 'n' or 'N' for no.)\n";
				cin >> use;
				while (toupper(use) != 'Y' && toupper(use) != 'N')
				{
					cout << endl;
					cout << endl << "Your input is invalid, please try again.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Press enter to continue.\n";
					std::cin.get();
					cout << endl;
				}
				if (toupper(use) == 'Y')
				{
					cout << endl;
					cout << Name << " used a Potion. Pikachu's HP was restored." << endl;
					PikaHp[0] += 50;
					SuperPotions--;
					if (PikaHp[0] > PikaHp[1])
					{
						PikaHp[0] = PikaHp[1];
					}
					cout << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
					cont = 0;
				}
				if (toupper(use) == 'N')
				{
				}
			}

		}

		if (Itemselection == 3)
		{
			if (OranBerries == 0)
			{
				cout << endl;
				cout << "Oh no! It looks like you dont have any Oran Berries left!\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Press enter to continue the battle!\n";
				std::cin.get();
				cout << endl;
			}
			if (OranBerries > 0)
			{
				cout << endl << endl;
				cout << "Oran Berry x" << OranBerries << endl;
				cout << "Descritption: \nIf held by or used on a Pokemon, it heals the user by just 10 HP." << endl;
				cout << "Would you like to use the Oran Berry? \n(enter 'y' or 'Y' for yes and 'n' or 'N' for no.)\n";
				cin >> use;
				while (toupper(use) != 'Y' && toupper(use) != 'N')
				{
					cout << endl;
					cout << endl << "Your input is invalid, please try again.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Press enter to continue.\n";
					std::cin.get();
					cout << endl;
				}
				if (toupper(use) == 'Y')
				{
					cout << endl;
					cout << Name << " used an Oran Berry. Pikachu's HP was restored." << endl;
					PikaHp[0] += 10;
					OranBerries--;
					if (PikaHp[0] > PikaHp[1])
					{
						PikaHp[0] = PikaHp[1];
					}
					cout << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
					cont = 0;
				}
				if (toupper(use) == 'N')
				{
				}
			}

		}

		if (Itemselection == 4)
		{
			if (MooMooMilk == 0)
			{
				cout << endl;
				cout << "Oh no! It looks like you dont have any Moomoo Milk left!\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Press enter to continue the battle!\n";
				std::cin.get();
				cout << endl;
			}
			if (MooMooMilk > 0)
			{
				cout << endl << endl;
				cout << "Moomoo Milk x" << MooMooMilk << endl;
				cout << "Descritption: \nMilk with a very high nutrition content.\n It restores the HP of one Pokemon by 100 points." << endl;
				cout << "Would you like to use the Moomoo Milk? \n(enter 'y' or 'Y' for yes and 'n' or 'N' for no.)\n";
				cin >> use;
				while (toupper(use) != 'Y' && toupper(use) != 'N')
				{
					cout << endl;
					cout << endl << "Your input is invalid, please try again.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Press enter to continue.\n";
					std::cin.get();
					cout << endl;
				}
				if (toupper(use) == 'Y')
				{
					cout << endl;
					cout << Name << " used a Moomoo Milk. Pikachu's HP was restored." << endl;
					PikaHp[0] += 100;
					MooMooMilk--;
					if (PikaHp[0] > PikaHp[1])
					{
						PikaHp[0] = PikaHp[1];
					}
					cout << "Hp:" << static_cast<int>(PikaHp[0]) << "/" << static_cast<int>(PikaHp[1]) << endl;
					cont = 0;
				}
				if (toupper(use) == 'N')
				{
				}
			}

		}

		if (Itemselection == 5)
		{
			if (PokeBalls == 0)
			{
				cout << endl;
				cout << "Oh no! It looks like you dont have any Poke Balls left!\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Press enter to continue the battle!\n";
				std::cin.get();
				cout << endl;
			}
			if (PokeBalls > 0)
			{
				cout << endl << endl;
				cout << "Poke Ball x" << PokeBalls << endl;
				cout << "Descritption: \nA device for catching wild Pokemon. It is thrown like a ball at the target.\n It is designed as a capsule system." << endl;
				cout << "Would you like to use the Poke Ball? \n(enter 'y' or 'Y' for yes and 'n' or 'N' for no.)\n";
				cin >> use;

				while (toupper(use) != 'Y' && toupper(use) != 'N')
				{
					cout << endl;
					cout << endl << "Your input is invalid, please try again.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Press enter to continue.\n";
					std::cin.get();
					cout << endl;
				}
				if (toupper(use) == 'Y')
				{
					cout << endl;
					cout << Name << " used a Poke ball." << endl;
					PokeBalls--;
					cout << "The trainer blocked your Poke Ball!\n";
					cout << "Youngster Joey says:\n   -Don't be a thief!\n   -You cant have my Pokemon just becasue they are better than yours!\n";
					cont = 0;
				}
				if (toupper(use) == 'N')
				{
				}
			}

		}
	} while (cont == 1);

	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Press enter to continue.\n";
	std::cin.get();
	cout << endl;
	cout << endl;

	if (CurrentPokemonFaced == "Bulba")
	{
		BulbaAttack(OpMove);
	}
	if (CurrentPokemonFaced == "Wartortle")
	{
		WartortleAttack(OpMove);
	}
	if (CurrentPokemonFaced == "Char")
	{
		CharAttack(OpMove);
	}

	cout << "Press enter to continue the battle!\n";
	std::cin.get();
	cout << endl;
	return 0;

}


int BulbaBattle()
{

	//function declarations
	int move = 0;
	double damage = 0;
	int OpMove;

	cout << endl << endl;
	cout << "You have chosen to use a move. What will Pikachu do?\n 1.Quick Attack     2.Growl\n 3.Thundershock     4.Tail Whip\n"; //displays moves
	cout << "Enter the number (1-4) of the move you will have Pikachu use,\n   or enter '0' to return to the previous menu." << endl;
	cin >> move; //gets users move

	while (move != 0 && move != 1 && move != 2 && move != 3 && move != 4)
	{		
		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		std::cin.get();
		cout << endl;
		
		cout << endl << endl;
		cout << "You have chosen to use a move. What will Pikachu do?\n 1.Quick Attack     2.Growl\n 3.Thundershock     4.Tail Whip\n"; //displays moves
		cout << "Enter the number (1-4) of the move you will have Pikachu use,\n   or enter '0' to return to the previous menu." << endl;
		cin >> move; //gets users move
	}

	if (move == 0)
	{
		return 0;
	}


	if (move == 1) //Quick Attack
	{

		cout << endl;
		cout << "Pikachu used Quick Attack!\n"; //tells what user chose
		damage = DamageCalc(QuickAttackDamage, PikaLVL, PikaStats, BulbaStats, 1, 1, 1);
		BulbaHp[0] -= (damage+5);
		cout << "  -It did " << static_cast<int>(damage + 5) << " damage.\n"; //reports damage
		damage = 0; //rests damage holder

		if (BulbaHp[0] > 0)
		{
			OpMove = rand() % 100;

			BulbaAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (BulbaHp <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
	}

	if (move == 2) //Growl
	{

		cout << endl;
		cout << "Pikachu used Growl!\n"; //tells what user chose
		TimesReducedOppAtk++;

		if (TimesReducedOppAtk <= 6)
		{
			cout << "  -Bulbasaurs's Attack fell! \n"; //reports status
			BulbaStats[0] = BaseAttack[1] * ReductionStages[TimesReducedOppAtk]; //reduces attack
		}
		else
		{
			TimesReducedOppAtk--;
			cout << "  -Bulbasaur's Attack cannot go any lower! \n"; //reports status
		}

		if (BulbaHp[0] > 0)
		{
			OpMove = rand() % 100;

				BulbaAttack(OpMove);

				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Press enter to continue the battle!\n";
				std::cin.get();
				cout << endl;
				return 0;
		}
		else if (BulbaHp <= 0)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}

	}

	if (move == 3) //Thundershock
	{

		cout << endl;
		cout << "Pikachu used Thundershock!\n"; //tells what user chose
		damage = DamageCalc(ThunderShockDamage, PikaLVL, PikaStats, BulbaStats, 1.5, 1, 2);
		BulbaHp[0] -= (damage + 5);
		cout << "  -It did " << static_cast<int>(damage + 5) << " damage.\n"; //reports damage
		damage = 0; //rests damage holder

		if (BulbaHp[0] > 0)
		{
			OpMove = rand() % 100;

			BulbaAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (BulbaHp <= 0)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
	}

	if (move == 4) //Tail Whip
	{

		cout << endl;
		cout << "Pikachu used Tail Whip!\n"; //tells what user chose
		TimesReducedOppDef++;

		if (TimesReducedOppDef <= 6)
		{
			cout << "  -Bulbasaurs's Defense fell! \n"; //reports status
			BulbaStats[1] = BaseDefense[1] * ReductionStages[TimesReducedOppDef]; //reduces attack
		}
		else
		{
			TimesReducedOppDef--;
			cout << "  -Bulbasaur's Defense cannot go any lower! \n"; //reports status
		}

		if (BulbaHp[0] > 0)
		{
			OpMove = rand() % 100;

			BulbaAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (BulbaHp <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;
		}
	}
	return 0;
}

int WartortleBattle()
{

	//function declarations
	int move = 0;
	double damage = 0;
	int OpMove;

	cout << endl << endl;
	cout << "You have chosen to use a move. What will Pikachu do?\n 1.Quick Attack     2.Growl\n 3.Thundershock     4.Tail Whip\n"; //displays moves
	cout << "Enter the number (1-4) of the move you will have Pikachu use,\n   or enter '0' to return to the previous menu." << endl;
	cin >> move; //gets users move

	while (move != 0 && move != 1 && move != 2 && move != 3 && move != 4)
	{
		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		std::cin.get();
		cout << endl;

		cout << endl << endl;
		cout << "You have chosen to use a move. What will Pikachu do?\n 1.Quick Attack     2.Growl\n 3.Thundershock     4.Tail Whip\n"; //displays moves
		cout << "Enter the number (1-4) of the move you will have Pikachu use,\n   or enter '0' to return to the previous menu." << endl;
		cin >> move; //gets users move
	}

	if (move == 0thre
	{
		return 0;
	}


	if (move == 1) //Quick Attack
	{

		cout << endl;
		cout << "Pikachu used Quick Attack!\n"; //tells what user chose
		damage = DamageCalc(QuickAttackDamage, PikaLVL, PikaStats, WartortleStats, 1, 1, 1);
		WartortleHp[0] -= (damage + 5);
		cout << "  -It did " << static_cast<int>(damage + 5) << " damage.\n"; //reports damage
		damage = 0; //rests damage holder

		if (WartortleHp[0] > 0)
		{
			OpMove = rand() % 100;

			WartortleAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (WartortleHp <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
	}

	if (move == 2) //Growl
	{

		cout << endl;
		cout << "Pikachu used Growl!\n"; //tells what user chose
		TimesReducedOppAtk++;

		if (TimesReducedOppAtk <= 6)
		{
			cout << "  -Wartortle's Attack fell! \n"; //reports status
			WartortleStats[0] = BaseAttack[2] * ReductionStages[TimesReducedOppAtk]; //reduces attack
		}
		else
		{
			TimesReducedOppAtk--;
			cout << "  -Wartortle's Attack cannot go any lower! \n"; //reports status
		}

		if (WartortleHp[0] > 0)
		{
			OpMove = rand() % 100;

			WartortleAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;
		}
		else if (WartortleHp <= 0)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}

	}

	if (move == 3) //Thundershock
	{

		cout << endl;
		cout << "Pikachu used Thundershock!\n"; //tells what user chose
		damage = DamageCalc(ThunderShockDamage, PikaLVL, PikaStats, WartortleStats, 1.5, 2, 2);
		WartortleHp[0] -= (damage + 5);
		cout << "  -It did " << static_cast<int>(damage + 5) << " damage.\n"; //reports damage
		damage = 0; //rests damage holder

		if (WartortleHp[0] > 0)
		{
			OpMove = rand() % 100;

			WartortleAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (WartortleHp <= 0)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
	}

	if (move == 4) //Tail Whip
	{

		cout << endl;
		cout << "Pikachu used Tail Whip!\n"; //tells what user chose
		TimesReducedOppDef++;

		if (TimesReducedOppDef <= 6)
		{
			cout << "  -Wartortle's Defense fell! \n"; //reports status
			WartortleStats[1] = BaseDefense[2] * ReductionStages[TimesReducedOppDef]; //reduces attack
		}
		else
		{
			TimesReducedOppDef--;
			cout << "  -Wartortle's Defense cannot go any lower! \n"; //reports status
		}

		if (WartortleHp[0] > 0)
		{
			OpMove = rand() % 100;

			WartortleAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (WartortleHp <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;
		}
	}
	return 0;
}

int CharBattle()
{

	//function declarations
	int move = 0;
	double damage = 0;
	int OpMove;

	cout << endl << endl;
	cout << "You have chosen to use a move. What will Pikachu do?\n 1.Quick Attack     2.Growl\n 3.Thundershock     4.Tail Whip\n"; //displays moves
	cout << "Enter the number (1-4) of the move you will have Pikachu use,\n   or enter '0' to return to the previous menu." << endl;
	cin >> move; //gets users move

	while (move != 0 && move != 1 && move != 2 && move != 3 && move != 4)
	{
		cout << endl;
		cout << endl << "Your input is invalid, please try again.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Press enter to continue.\n";
		std::cin.get();
		cout << endl;

		cout << endl << endl;
		cout << "You have chosen to use a move. What will Pikachu do?\n 1.Quick Attack     2.Growl\n 3.Thundershock     4.Tail Whip\n"; //displays moves
		cout << "Enter the number (1-4) of the move you will have Pikachu use,\n   or enter '0' to return to the previous menu." << endl;
		cin >> move; //gets users move
	}

	if (move == 0)
	{
		return 0;
	}


	if (move == 1) //Quick Attack
	{

		cout << endl;
		cout << "Pikachu used Quick Attack!\n"; //tells what user chose
		damage = DamageCalc(QuickAttackDamage, PikaLVL, PikaStats, CharStats, 1, 1, 1);
		CharHp[0] -= (damage + 5);
		cout << "  -It did " << static_cast<int>(damage + 5) << " damage.\n"; //reports damage
		damage = 0; //rests damage holder

		if (WartortleHp[0] > 0)
		{
			OpMove = rand() % 100;

			CharAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (CharHp <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
	}

	if (move == 2) //Growl
	{

		cout << endl;
		cout << "Pikachu used Growl!\n"; //tells what user chose
		TimesReducedOppAtk++;

		if (TimesReducedOppAtk <= 6)
		{
			cout << "  -Charmeleon's Attack fell! \n"; //reports status
			CharStats[0] = BaseAttack[3] * ReductionStages[TimesReducedOppAtk]; //reduces attack
		}
		else
		{
			TimesReducedOppAtk--;
			cout << "  -Charmeleon's Attack cannot go any lower! \n"; //reports status
		}

		if (CharHp[0] > 0)
		{
			OpMove = rand() % 100;

			CharAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;
		}
		else if (CharHp <= 0)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}

	}

	if (move == 3) //Thundershock
	{

		cout << endl;
		cout << "Pikachu used Thundershock!\n"; //tells what user chose
		damage = DamageCalc(ThunderShockDamage, PikaLVL, PikaStats, CharStats, 1.5, 1, 2);
		CharHp[0] -= (damage + 5);
		cout << "  -It did " << static_cast<int>(damage + 5) << " damage.\n"; //reports damage
		damage = 0; //rests damage holder

		if (CharHp[0] > 0)
		{
			OpMove = rand() % 100;

			CharAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (CharHp <= 0)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
	}

	if (move == 4) //Tail Whip
	{

		cout << endl;
		cout << "Pikachu used Tail Whip!\n"; //tells what user chose
		TimesReducedOppDef++;

		if (TimesReducedOppDef <= 6)
		{
			cout << "  -Charmeleon's Defense fell! \n"; //reports status
			CharStats[1] = BaseDefense[3] * ReductionStages[TimesReducedOppDef]; //reduces attack
		}
		else
		{
			TimesReducedOppDef--;
			cout << "  -Charmeleon's Defense cannot go any lower! \n"; //reports status
		}

		if (CharHp[0] > 0)
		{
			OpMove = rand() % 100;

			CharAttack(OpMove);

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;

		}
		else if (CharHp <= 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Press enter to continue the battle!\n";
			std::cin.get();
			cout << endl;
			return 0;
		}
	}
	return 0;
}

int BulbaAttack(int ranV)
{
	double damage;

	if (ranV >= 0 && ranV <= 40)
	{
		cout << "Joey's Bulbasaur used Tackle!\n"; //tells oponents move
		damage = DamageCalc(TackleDamage, BulbaLVL, BulbaStats, PikaStats, 1, 1, 1);
		PikaHp[0] -= (damage + 3);
		cout << "  -It did " << static_cast<int>(damage + 3) << " damage.\n"; //reports damage
		return 0;
	}

	if (ranV >= 41 && ranV <= 80)
	{
		cout << "Joey's Bulbasaur used Vine Whip!\n"; //tells oponents move
		damage = DamageCalc(VineWhipDamage, BulbaLVL, BulbaStats, PikaStats, 1.5, 1, 1);
		PikaHp[0] -= (damage+3);
		cout << "  -It did " << static_cast<int>(damage + 3) << " damage.\n"; //reports damage
		return 0;
	}

	if (ranV >= 81 && ranV <= 99)
	{
		cout << "Joey's Bulbasaur used Growl!\n"; //tells oponents move
		TimesReducedPikaAtk++;

		if (TimesReducedPikaAtk <= 6)
		{
			cout << "  -Pikachu's Attack fell! \n"; //reports status
			PikaStats[0] = BaseAttack[0] * ReductionStages[TimesReducedPikaAtk]; //reduces attack
			return 0;
		}
		else
		{
			TimesReducedPikaAtk--;
			cout << "  -Pikachu's Attack cannot go any lower! \n"; //reports status
			return 0;
		}
	}
	return 0;
}

int WartortleAttack(int ranV)
{
	double damage;

	if (ranV >= 0 && ranV <= 35)
	{
		cout << "Joey's Wartortle used Water Gun!\n"; //tells oponents move
		damage = DamageCalc(WaterGunDamage, WartortleLVL, WartortleStats, PikaStats, 1.5, 1, 2);
		PikaHp[0] -= (damage + 3);
		cout << "  -It did " << static_cast<int>(damage + 3) << " damage.\n"; //reports damage
		return 0;
	}

	if (ranV >= 36 && ranV <= 70)
	{
		cout << "Joey's Wartortle used Bite!\n"; //tells oponents move
		damage = DamageCalc(BiteDamage, WartortleLVL, WartortleStats, PikaStats, 1, 1, 1);
		PikaHp[0] -= (damage + 3);
		cout << "  -It did " << static_cast<int>(damage + 3) << " damage.\n"; //reports damage
		return 0;
	}

	if (ranV >= 71 && ranV <= 85)
	{
		cout << "Joey's Wartortle used Withdraw!\n"; //tells oponents move
		TimesRaisedOppDef++;

		if (TimesRaisedOppDef <= 6)
		{
			cout << "  -Wartortle's Defense rose! \n"; //reports status
			WartortleStats[1] = BaseDefense[2] * ReductionStages[TimesRaisedOppDef]; //reduces attack
			return 0;
		}
		else
		{
			TimesRaisedOppDef--;
			cout << "  -Wartortle's Defense cannot go any higher! \n"; //reports status
			return 0;
		}
	}

	if (ranV >= 86 && ranV <= 99)
	{
		cout << "Joey's Wartortle used Tail Whip!\n"; //tells oponents move
		TimesReducedPikaDef++;

		if (TimesReducedPikaAtk <= 6)
		{
			cout << "  -Pikachu's Defense fell! \n"; //reports status
			PikaStats[1] = BaseDefense[0] * ReductionStages[TimesReducedPikaAtk]; //reduces attack
			return 0;
		}
		else
		{
			TimesReducedPikaDef--;
			cout << "  -Pikachu's Defense cannot go any lower! \n"; //reports status
			return 0;
		}
	}
	return 0;
}

int CharAttack(int ranV)
{
	double damage;

	if (ranV >= 0 && ranV <= 45)
	{
		cout << "Joey's Charmeleon used Ember!\n"; //tells oponents move
		damage = DamageCalc(EmberDamage, CharLVL, CharStats, PikaStats, 1.5, 1, 1);
		PikaHp[0] -= damage;
		cout << "  -It did " << static_cast<int>(damage) << " damage.\n"; //reports damage
		return 0;
	}

	if (ranV >= 46 && ranV <= 90)
	{
		cout << "Joey's Charmeleon used Scratch!\n"; //tells oponents move
		damage = DamageCalc(ScratchDamage, CharLVL, CharStats, PikaStats, 1, 1, 1);
		PikaHp[0] -= damage;
		cout << "  -It did " << static_cast<int>(damage) << " damage.\n"; //reports damage
		return 0;
	}

	if (ranV >= 91 && ranV <= 99) //this move "Dragon Rage" is special in the fact that it always does
								  //40 damage no matter what
	{
		cout << "Joey's Charmeleon used Dragon Rage!\n"; //tells oponents move
		PikaHp[0] -= 20;
		cout << "  -It did 40 damage.\n"; //reports damage
		return 0;
	}
	return 0;
}