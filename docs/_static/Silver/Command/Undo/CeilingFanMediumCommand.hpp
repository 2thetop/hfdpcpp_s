#ifndef	_HFDP_CPP_COMMAND_UNDO_CEILING_FAN_MEDIUM_COMMAND_HPP_
#define _HFDP_CPP_COMMAND_UNDO_CEILING_FAN_MEDIUM_COMMAND_HPP_

#include "Hum_Log_Manager.h"
#include "Hum_Trace.h"

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
  namespace Command {
    namespace Undo {

      class CeilingFanMediumCommand : public Command {

        const CeilingFan* _ceilingFan;
        mutable int _prevSpeed;

      public:
        explicit CeilingFanMediumCommand( const CeilingFan* ceilingFan ) :
          _ceilingFan( ceilingFan )
        {
          assert( ceilingFan );
          HUM_TRACE(ACE_TEXT("CeilingFanMediumCommand"
                             "::CeilingFanMediumCommand"));
          _prevSpeed = _ceilingFan->getSpeed();
        }
        void execute() const
        {
          HUM_TRACE(ACE_TEXT("CeilingFanMediumCommand::execute"));
          _prevSpeed = _ceilingFan->getSpeed();
          _ceilingFan->medium();
        }
        void undo() const
        {
          HUM_TRACE(ACE_TEXT("CeilingFanMediumCommand::undo"));
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
