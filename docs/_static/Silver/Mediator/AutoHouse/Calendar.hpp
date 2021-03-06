#ifndef	_HFDP_CPP_MEDIATOR_AUTO_HOUSE_CALENDAR_HPP_
#define _HFDP_CPP_MEDIATOR_AUTO_HOUSE_CALENDAR_HPP_

#include <windows.h>

namespace HeadFirstDesignPatterns {
  namespace Mediator {
    namespace AutoHouse {

      class Calendar : public Appliance {
        int _today;
        void* _thread;
        unsigned long _threadId;
        mutable unsigned long _interval;	// length of day (in seconds)
        mutable unsigned long _iterations;	// number of day (events)

        void run()
        {
          _mediator->output( "Calendar is on" );

          do {
            onEvent( _today );	// a calendar event is a new day
            Sleep( _interval * 1000 );	// duration in milliseconds
            if( _today == Saturday ) {
              _today =  Sunday;
            } else {
              _today++;
            }
          } while( 0 != _interval && 0 != _iterations );

          _mediator->output( "Calendar is off" );
          _thread = 0;
        }

      public:
        enum DayOfWeek {
          Sunday=0, Monday=1, Tuesday=2, Wednsday=3, Thursday=4, Friday=5,
          Saturday=6
        };

        Calendar( Mediator* mediator, unsigned long iterations ) :
          _iterations( iterations ), Appliance( mediator )
        {
          _today = Sunday;
          _thread = 0;
        }
        bool isTrashDay( int dayOfWeek )
        {
          if( Monday == dayOfWeek || Friday == dayOfWeek ) {
            return true;
          } else {
            return false;
          }
        }
        bool isWeekDay( int dayOfWeek )
        {
          if( Monday <= dayOfWeek && Friday >= dayOfWeek ) {
            return true;
          } else {
            return false;
          }
        }
        int today() const
        {
          return _today;
        }
        int today( DayOfWeek dayOfWeek )
        {
          assert( Sunday <= dayOfWeek && Saturday >= dayOfWeek );
          if( Sunday <= dayOfWeek && Saturday >= dayOfWeek ) {
            _today = dayOfWeek;
          }
          return _today;
        }
#if defined( WIN32 )
        void on( unsigned long interval )
        {
          assert( interval > 0 );
          _interval = interval;
          if( _thread == 0 ) {
            _thread = CreateThread(0, 0, Calendar::start, this, 0, &_threadId);
          }
          WaitForSingleObject( _thread, INFINITE );
        }
#else
#error Calendar::on() not implemented for this platform
#endif
        void off()
        {
          _interval = 0;
        }
        void onEvent( unsigned long value ) const
        {
          if( _iterations > 0 ) {
            _iterations--;
            _mediator->onEvent( this, value );
          } else {
            _interval = 0;	// calendar has expired
          }
        }
        static unsigned long __stdcall start( void* self )
        {
          assert( self );
          reinterpret_cast< Calendar* >( self )->run();
          return 0;
        }

        std::string toString() const
        {
          assert( _today >= Sunday && _today <= Saturday );
          switch( _today ) {
          case Sunday:	return "Sunday";
          case Monday:	return "Monday";
          case Tuesday:	return "Tuesday";
          case Wednsday:	return "Wednsday";
          case Thursday:	return "Thursday";
          case Friday:	return "Friday";
          case Saturday:	return "Saturday";
          }
          return "Error! Invalid day value.";
        }
      };

    } // namespace AutoHouse
  } // namespace Mediator
} // namespace HeadFirstDesignPatterns

#endif
