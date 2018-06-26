#include "Clock.h"

Clock::Clock() : timestamp_control_{ get_time()-10 }, timestamp_update_{ get_time()-10 }
{
}

elapsed Clock::get_time() const
{
	elapsed time;

	#if _WIN32 || _WIN64
		auto now = std::chrono::system_clock::now().time_since_epoch();
		time = static_cast<elapsed>(std::chrono::duration_cast<std::chrono::milliseconds>(now).count());
	#else 
		time = static_cast<elapsed>(millis());
	#endif
	
	return time;
}
