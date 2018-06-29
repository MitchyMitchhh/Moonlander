#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"


class Lander
{
private:
	Point _position;
	Velocity _velocity;
	int _fuel;
	bool _landed;
	bool _alive;
public:
	Lander();
	Point getPoint() const;
	Velocity getVelocity() const;
	bool isAlive() const;
	bool isLanded() const;
	int getFuel() const;
	bool canThrust();

	void setLanded(bool landed);
	void setAlive(bool alive);
	void setFuel(int fuel);

	void applyGravity();
	bool applyThrustLeft();
	bool applyThrustRight();
	bool applyThrustBottom();
	void draw();
	void advance();
};

#endif