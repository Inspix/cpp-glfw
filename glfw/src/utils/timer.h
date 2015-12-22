#pragma once

#include <chrono>

namespace inspix {

	template<typename Resolution>
	class Timer {
	private:
		std::chrono::steady_clock::time_point time;
		long long result;
	public:
		Timer() { result = -1; }
		~Timer() {}

		void run() { 
			time = std::chrono::steady_clock::now(); 
		}
		void stop() { 
			result = calc();
		}
		void reset() {
			time = std::chrono::steady_clock::now();
		};
		long long getElapsed() {
			return calc();
		}
		
	private:
		long long calc() {
			return (long long)std::chrono::duration_cast<Resolution>(std::chrono::steady_clock::duration(std::chrono::steady_clock::now() - time)).count();
		}
	};


	typedef Timer<std::chrono::nanoseconds> TimerNS;
	typedef Timer<std::chrono::microseconds> TimerMicS;
	typedef Timer<std::chrono::milliseconds> TimerMS;
	typedef Timer<std::chrono::seconds> TimerS;
}