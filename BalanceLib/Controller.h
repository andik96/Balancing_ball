#pragma once

#include "Ball.h"
#include "Beam.h"

class Controller
{
public:
	Controller();
	virtual ~Controller();

private:
	Ball ball(0,0);
	Beam beam();
};

