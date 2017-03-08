#include <string.h>
#include "MaszynaStanow.h"

	MaszynaStanow::MaszynaStanow()
		: _actStan ( -1 )
		//, _counter ( 0 )
	{}
	/*************************************************************************************/
	MaszynaStanow::~MaszynaStanow(){
		for( int i = 0; i < ( int )_stanTable.size(); ++i ){
			delete _stanTable[i];
		}
		_stanTable.clear();
	}
	/*************************************************************************************/
	void MaszynaStanow::start(){
		if( _stanTable.size() )
			_actStan = 0;
	}
	/*************************************************************************************/
	Stan& MaszynaStanow::operator()(){
		std::cout << "Wykonanie w stanie: ";
		return *( _stanTable[ _actStan ] );
	}
	/*************************************************************************************/
	MaszynaStanow& MaszynaStanow::operator++(){
		if( _actStan + 1 < ( int )_stanTable.size() )
			_actStan += 1;
		return *this;
	}	
	/*************************************************************************************/
	MaszynaStanow& MaszynaStanow::operator--(){
		if( _actStan )
			_actStan -= 1;
		return *this;
	}
	/*************************************************************************************/
	MaszynaStanow& MaszynaStanow::operator+=( Stan* ptr ){
		/*if( !_counter ){
			_stanTable = new Stan* [1];
			_stanTable[0] = ptr;
			_counter += 1;
			return *this;
		}
		Stan* temp[ _counter ];
		for( int i = 0; i < _counter; ++i )
			temp[i] = _stanTable[i];
		delete [] _stanTable;
		_counter += 1;
		_stanTable = new Stan* [ _counter ];
		for( int i = 0; i < _counter - 1; i++ )
			_stanTable[i] = temp[i];
		_stanTable[ _counter - 1 ] = ptr;
		return *this;*/
		_stanTable.push_back( ptr );
		return *this;
	}
	/*************************************************************************************/
	std::ostream& operator<<( std::ostream& out, const MaszynaStanow& stanMach ){
		out << "Maszyna Stanow:\n";
		for( int i = 0; i < ( int )stanMach._stanTable.size(); ++i ){
			if( i == stanMach._actStan )
				out << i << " " << stanMach._stanTable[i] -> stan() << " < " << std::endl;
			else
				out << i << " " << stanMach._stanTable[i] -> stan() << std::endl;
		}
		return out;
	}
	/*************************************************************************************/
