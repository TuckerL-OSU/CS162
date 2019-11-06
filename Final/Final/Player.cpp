/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Final Project
* Player.cpp
******************************************************************************/
#include "Player.hpp"

Player::Player() {
	this->y = 0;
	this->x = 0;
	this->moonStones = 0;

	bp = new Backpack();
}

Player::~Player() {
	delete bp;
}

void Player::setLoc(int row, int col) {
	this->y = row;
	this->x = col;
}

void Player::setY(int row) {
	this->y = row;
}
int Player::getY() {
	return y;
}

void Player::setX(int col) {
	this->x = col;
}
int Player::getX() {
	return x;
}
