
// Constraints : 
// Odd Y = -x, Odd X = -y
// Even Y = +x, Even X = +y

// Strategy :
// 1. Check if current coordinate is the target
// 2. If so, exit, else, find possible moves
// 3. Compute distance to target for possible moves
// 4. Take lesser, else, take first
// 5. Increment moves


class Point
{
	friend class Pathfinding;

public:
	Point( int x, int y )
	{
		m_nX = x;
		m_nY = y;
	}
	
	//TODO: Overload == and != operators

private:
	int m_nX;
	int m_nY;
};


class Pathfinding
{
public:
	int getDirections( int x, int y )
	{
		m_CurrentLoc = Point( 0, 0 );
		m_TargetLoc = Point( x, y );

		int nextHorizontal;
		int nextVertical;

		while ( m_CurrentLoc.m_nX != m_TargetLoc.m_nX || m_CurrentLoc.m_nY != m_TargetLoc.m_nY )
		{
			//Get new possible coordinates
			nextHorizontal = ( m_CurrentLoc.m_nX % 2 > 0 ) ? ( m_CurrentLoc.m_nX - 1 ) : ( m_CurrentLoc.m_nX + 1 );
			nextVertical   = ( m_CurrentLoc.m_nY % 2 > 0 ) ? ( m_CurrentLoc.m_nY - 1 ) : ( m_CurrentLoc.m_nY + 1 );

			//Compare coordinates
		
		}
	}

private:
	Point m_CurrentLoc;
	Point m_TargetLoc;
};


int main( )
{

	return 0;
}