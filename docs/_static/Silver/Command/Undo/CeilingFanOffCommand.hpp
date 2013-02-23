#ifndef	_HFDP_CPP_COMMAND_UNDO_CEILING_FAN_OFF_COMMAND_HPP_
#define _HFDP_CPP_COMMAND_UNDO_CEILING_FAN_OFF_COMMAND_HPP_

#include "Hum_Log_Manager.h"
#include "Hum_Trace.h"

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
  namespace Command {
    namespace Undo {

      class CeilingFanOffCommand :public Command {

        const CeilingFan* _ceilingFan;
        mutable int _prevSpeed;

      public:
        explicit CeilingFanOffCommand( const CeilingFan* ceilingFan ) :
          _ceilingFan( ceilingFan )
        {
          assert( ceilingFan );
          HUM_TRACE(ACE_TEXT("CeilingFanOffCommand::CeilingFanOffCommand"));
          _prevSpeed = _ceilingFan->getSpeed();
        }
        void execute() const
        {
          HUM_TRACE(ACE_TEXT("CeilingFanOffCommand::execute"));
          _prevSpeed = _ceilingFan->getSpeed();
          _ceilingFan->off();
        }
        void undo() const
        {
          HUM_TRACE(ACE_TEXT("CeilingFanOffCommand::undo"));
          if( _prevSpeed == CeilingFan::HIGH ) {
            _ceilingFan->high();
          } else if( _prevSpeed == CeilingFan::MEDIUM ) {
            _ceilingFan->medium();
          } else if( _prevSpeed == CeilingFan::LOW ) {
            _ceilingFan->low();
          } else if( _prevSpeed == CeilingFan::OFF ) {
            _ceilingFan->off();
          }
        }
      };

    } // namespace Undo
  } // namespace Command
} // namespace HeadFirstDesignPatterns

#endif
