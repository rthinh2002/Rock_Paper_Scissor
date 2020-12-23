#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.cpp"

class Computer : public Player{
public: 
	std::string move() {
		std::string comp_choice;
		std::srand(time(0));
		int option = 1 + rand() % 3;
		if (option == 1) {
			comp_choice =  "Rock";
		}
		else if (option == 2) {
			comp_choice =  "Paper";
		}
		else if(option == 3){
			comp_choice =  "Scissor";
		}
		return comp_choice;
	}
};