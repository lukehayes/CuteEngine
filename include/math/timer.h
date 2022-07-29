#pragma once

/**
 * Simple timer class to run something repeatedly N anout of times or one-shot.
 */
class Timer
{
	public:
		Timer(double time, bool oneshot)
			: time(time), oneshot(oneshot) {}

		double getElapsedTime()
		{
			return this->elapsed;
		}

		template <typename fn>
		int update(double dt, fn&& lambda)
		{
			this->elapsed += dt;

			if(this->elapsed > time)
			{
				lambda();

				if(this->oneshot)
				{
					return 0;
				}
			}
		}

	private:
		double time    = 1.0;
		bool oneshot   = false;
		double elapsed = 0.0;
};

