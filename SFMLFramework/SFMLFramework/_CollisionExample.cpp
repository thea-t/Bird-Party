#include <cmath>

struct Vector2
{
	float x;
	float y;

	float magnitude()
	{
		return sqrtf( ( x * x ) + ( y * y ) );
	}

	float magnitudeSquared()
	{
		return ( x * x ) + ( y * y );
	}

	float normalize()
	{
		float length = magnitude();
		x /= length;
		y /= length;
	}

};

struct Rectangle
{
	float x;
	float y;
	float width;
	float height;
};

//struct Rectangle
//{
//	float minX;
//	float maxX;
//	float minY;
//	float maxY;
//};

struct Circle
{
	Vector2 position;
	float radius;
};

bool testRectangleOverlap( const Rectangle& rect0, const Rectangle& rect1 )
{
	if(		(rect0.x + rect0.width * 0.5f ) < ( rect1.x - rect1.width * 0.5f) 
		|| ( rect0.x - rect0.width * 0.5f ) > ( rect1.x + rect1.width * 0.5f )
		|| ( rect0.y + rect0.height * 0.5f ) < ( rect1.y - rect1.height * 0.5f )
		|| ( rect0.y - rect0.height * 0.5f ) > ( rect1.y + rect1.height * 0.5f )
	   )
	{
		return false;
	}
	else
	{
		return true;
	}

}


bool testCircleOverlap( const Circle& circle0, const Circle& circle1 )
{
	float distanceBetweenCentresSquared = (circle0.position - circle1.position).magnitudeSquared();

	float sumOfRadii = circle0.radius + circle1.radius;
	//if( distanceBetweenCentres < sumOfRadii )
	if( distanceBetweenCentresSquared < (sumOfRadii* sumOfRadii) )
	{
		// Circles are overlapping!
		return true;
	}
	else
	{
		// Circles are not overlapping
		return true;
	}


}


int main()
{
	Rectangle r0;
	Rectangle r1;
	// Filled in rectangle data
	// :
	// :

	if( testRectangleOverlap( r0, r1 ) )
	{
		// They are overlapping!
	}

	//--------------------------------------------------------------

	Circle c0;
	Circle c1;
	// Filled in circle data
	// :
	// :

	if( testCircleOverlap( c0, c1 ) )
	{
		// They are overlapping!
	}



	return 0;
}



