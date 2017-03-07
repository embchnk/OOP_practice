#ifndef Stan_h
#define	Stan_h

class Stan
{
public:
	char * _data;
	Stan * next;
	Stan( const char * );

	Stan operator()();
};

#endif //Stan_h