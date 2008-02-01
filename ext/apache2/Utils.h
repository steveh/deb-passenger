#ifndef _PASSENGER_UTILS_H_
#define _PASSENGER_UTILS_H_

#include <ostream>

namespace Passenger {

#ifdef PASSENGER_DEBUG
	#define P_DEBUG(expr) \
		do { \
			if (Passenger::_debugStream != 0) { \
				*Passenger::_debugStream << \
					"[" << __FILE__ << ":" << __LINE__ << "] " << \
					expr << std::endl; \
			} \
		} while (false)
	#define P_TRACE P_DEBUG
#else
	#define P_DEBUG(expr) do { /* nothing */ } while (false)
	#define P_TRACE P_DEBUG
#endif

	// Internal; do not use directly.
	extern std::ostream *_debugStream;

	void initDebugging(const char *logFile = NULL);

} // namespace Passenger

#endif /* _PASSENGER_UTILS_H_ */