#ifndef VARIABLES_H
#define VARIABLES_H
struct Vertex
{
	/*struct // Also possible as anonymous
	{
		float x, y, z;
	} position;*/

	struct Position
	{
		float x, y, z;

		static Position Zero(void);
		static Position Forward(void);
	} position = Position::Zero();

	struct Color
	{
		float r, g, b;

		static Color Black(void);
		static Color White(void);
		static Color Red(void);
		static Color Green(void);
		static Color Blue(void);

	} color = Color::Black();

	inline static const int GetSize(void) { return 6 * sizeof(float); }
	inline static const int GetElemSize(void) { return 3 * sizeof(float); }
};
#endif // !VARIABLES_H



