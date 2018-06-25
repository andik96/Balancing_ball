#pragma once

#include "using_types.h"

class Clock
{
public:
	Clock();
	elapsed get_time() const;

	elapsed timestamp_control_;
	elapsed timestamp_update_;
};