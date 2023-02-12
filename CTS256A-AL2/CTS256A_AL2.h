#pragma once

#include "System_I.h"

#include "SystemConsole.h"
#include "Ram.h"
#include "Rom.h"
#include "InOut_I.h"
#include "TMS7000CPU.h"
#include "TMS7000Disassembler.h"
#include "ConIOConsole.h"

#include <iostream>

#define DEBUG_CTR_RELOAD 999999
#define EOF_CTR_RELOAD 199999

class CTS256A_AL2_Data_InOut
	: public Memory_I, public InOut_I
{
public:
	CTS256A_AL2_Data_InOut( TMS7000CPU &cpu, std::istream &istr, std::ostream &ostr )
		: cpu_( cpu ), istr_( istr ), ostr_( ostr ), bport_( 0 ), initctr_( 6 ), eof_( false )
		, debug_( false ), verbose_( false ), echo_( false ), noOK_( false ), mode_( 'T' ), debugctr_( DEBUG_CTR_RELOAD )
	{
	}

	uchar read( ushort addr );

	uchar write( ushort addr, uchar data );

    reader_t getReader()
	{
		return 0;
	}

    writer_t getWriter()
	{
		return 0;
	}

    void* getObject()
	{
		return 0;
	}

	// out char
	virtual uchar out( ushort addr, uchar data );

	// in char
	virtual uchar in( ushort addr );

	void setOption( uchar option, uint value );

private:
	uchar					bport_;
	TMS7000CPU				&cpu_;
	uchar					ram_[0x800];
	std::istream			&istr_;
	std::ostream			&ostr_;
	uchar					initctr_;
	uint					debugctr_;
	uint					eofctr_;
	bool					eof_;
	bool					debug_;
	bool					verbose_;
	bool					echo_;
	bool					textMode_;
	bool					noOK_;
	char					mode_;
};


class CTS256A_AL2 : public System_I
{
public:
	CTS256A_AL2( std::istream &istr, std::ostream &ostr )
	: debug_( false ), istr_( istr), ostr_( ostr ), data_( cpu_, istr, ostr )
	{
		systemConsole_.setSystem( this );
		systemConsole_.setConsole( &console_ );
		cpu_.setExtMemory( &data_ );
		cpu_.setExtInOut( &data_ );
		cpu_.setConsole( &systemConsole_ );
		cpu_.setMode( &mode_ );
		disass_.setCode( &data_ );
	}

	~CTS256A_AL2(void)
	{
	}

	void run();
	void stop();
	void exit();
	void reset();
	void wakeup();
	void step();
	void callstep();

	void setOption( uchar option, uint value )
	{
		data_.setOption( option, value );
		if ( option == 'D' )
			debug_ = value != 0;
	}

private:
	TMS7000CPU				cpu_;
	CTS256A_AL2_Data_InOut	data_;
	Mode					mode_;
	ConIOConsole			console_;
	SystemConsole			systemConsole_;
	TMS7000Disassembler		disass_;
	bool					debug_;
	std::istream			&istr_;
	std::ostream			&ostr_;
};
