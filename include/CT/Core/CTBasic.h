/** @file  CT/Core/CTBasic.h
 *
 * @brief CTBasic is the base class for all things.
 *
 * @namespace CT::Core.
 *
 * @author LDH.
 */
#ifndef CT_CORE_CTBASIC_H
#define CT_CORE_CTBASIC_H

#include "raylib.h"

namespace CT::Core
{
	class CTBasic
	{
	public:
		CTBasic();
		CTBasic(Vector2& position, Vector2& size, Color color);
		~CTBasic();

		Vector2 position;
		Vector2 size;
		Color color;
		float speed = GetRandomValue(10,300);
	private:
	};
}
#endif // !CT_CORE_CTBASIC_H
