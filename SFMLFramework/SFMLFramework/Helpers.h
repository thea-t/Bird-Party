#ifndef HELPERS_H
#define HELPERS_H

#define SAFE_DELETE(p)	\
	if( p )				\
	{					\
		delete p;		\
		p = nullptr;	\
	}

//void safeDelete( const void*& p )
//{
//	if( p )
//	{
//		delete p;
//		p = nullptr;
//	}
//}

#endif // End of '#ifndef HELPERS_H'
