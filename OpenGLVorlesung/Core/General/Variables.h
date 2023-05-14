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
		void operator += (Position a_pos);
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

	struct UVCoord
	{
		float u, v;

	} uv{ 0.0f,0.0f };

	inline static const int GetSize(void) { return 8 * sizeof(float); }
	inline static const int GetElemSize(void) { return 3 * sizeof(float); }
};

struct Transform 
{
	struct Position
	{
		float x, y, z;

		static Position Zero(void);
		static Position Forward(void);

		//void operator += (float a_x, float a_y, float a_z);
		void operator += (Position a_pos);
	} position = Position::Zero();

	struct Rotation
	{
		float x, y, z;

		static Rotation Zero(void);
	} rotation = Rotation::Zero();

	struct Scale
	{
		float x, y, z;

		static Scale One(void);
	} scale = Scale::One();
};
#endif // !VARIABLES_H



