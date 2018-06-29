#include "lander.h"
#include "uiDraw.h"

	Lander::Lander() 
	{
		Velocity(0.1, 0.1);
		_position.setX(175);
		_position.setY(175);
		setLanded(false);
		setAlive(true);
		setFuel(0);
	}

	Point Lander::getPoint() const
	{
		return _position;
	}
	Velocity Lander::getVelocity() const 
	{
		return _velocity;
	}
	bool Lander::isAlive() const 
	{
		return _alive;
	}
	bool Lander::isLanded() const
	{
		return _landed;
	}
	int Lander::getFuel() const
	{
		return _fuel;
	}
	bool Lander::canThrust()
	{
		if (_fuel > 0)
			return true;
		else
			return false;
	}
	void Lander::setLanded(bool landed) 
	{
		this->_landed = landed;
	}
	void Lander::setAlive(bool alive)
	{
		this->_alive = alive;
	}
	void Lander::setFuel(int fuel)
	{
		this->_fuel = fuel;
	}

	void Lander::applyGravity()
	{
		// Vel
		_velocity.setDy(_velocity.getDy() - 0.1);
	}

	bool Lander::applyThrustLeft()
	{
		if (_fuel > 0)
		{
			// Vel
			float current = _velocity.getDx();
			current += 0.1;
			_velocity.setDx(current);

			_fuel -= 1;
		}
		else
			return 0;
	}

	bool Lander::applyThrustRight()
	{
		if (_fuel > 0)
		{
			float current = _velocity.getDx();
			current -= 0.1;
			_velocity.setDx(current);

			_fuel -= 1;
		}
		else
			return 0;
	}

	bool Lander::applyThrustBottom()
	{
		if (_fuel > 1)
		{
			float current = _velocity.getDy();
			current += 0.3;
			_velocity.setDy(current);

			_fuel -= 3;
		}
		else
			return 0;
	}
	void Lander::draw()
	{
		drawLander(_position);
	}

	void Lander::advance()
	{
		float currentX = _velocity.getDx();
		_position.addX(currentX);

		_position.addX(_velocity.getDx());

		float currentY = _velocity.getDy();
		_position.addY(currentY);

		_position.addY(_velocity.getDy());
	}
