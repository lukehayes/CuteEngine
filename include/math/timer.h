#pragma once

/**
 * Simple timer class to run something repeatedly N anout of times or one-shot.
 */
class Timer
{
	public:
		Timer(double time, bool oneshot)
			: time(time), oneshot(oneshot) {}

		/**
		 * Get the currently elapsed time of the timer.
		 *
		 * @return double.
		 */
		double getElapsedTime()
		{
			return this->elapsed;
		}

		template <typename fn>
		int update(double dt, fn&& lambda)
		{
			this->elapsed += dt;

			if(this->oneshot && !this->finished)
			{
				this->finished = true;
				lambda();
				return 0;
			}else
			{
				if(this->elapsed > time)
				{
					lambda();
					this->elapsed = 0;
					this->finished = false;
				}
			}
		}
		
		/**
		 * Has the timer finished?
		 *
		 * @return bool.
		 */
		bool hasFinished() const
		{
			return this->finished;
		}

	private:
		double time    = 1.0;
		bool oneshot   = false;
		double elapsed = 0.0;
		bool finished  = false;
};

