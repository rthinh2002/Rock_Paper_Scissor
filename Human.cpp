#include <iostream>
#include "Player.cpp"

class Human : public Player{
	std::string human_move;
public:


	Human(std::string move) {
		this->human_move = move;
	}



	std::string move() { //method for human move
		if (human_move == "rock" || human_move == "Rock") {
			human_move = "Rock";
		}
		else if (human_move == "paper" || human_move == "Paper") {
			human_move = "Paper";
		}
		else if (human_move == "scissor" || human_move == "Scissor") {
			human_move = "Scissor";
		}
		return human_move;
	}
};