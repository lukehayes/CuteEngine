#pragma once

/**
 * Simple timer class to run something repeatedly N anout of times or one-shot.
 */
class Timer
{
	public:
		Timer(double time, bool repeatable)
			: time(time), repeatable(repeatable) {}

		/**
		 * Get the currently elapsed time of the timer.
		 *
		 * @return double.
		 */
		double getElapsedTime()
		{
			return this->elapsed;
		}

		/**
		 * Get the currently elapsed time of the timer.
		 *
		 * @return double.
		 */
		template <typename fn>
		int update(double dt, fn&& lambda)
		{
			this->elapsed += dt;

			if(this->repeatable && !this->finished)
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
		bool repeatable   = false;
		double elapsed = 0.0;
		bool finished  = false;
};

