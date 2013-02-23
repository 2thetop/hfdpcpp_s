#ifndef	_HFDP_CPP_COMMAND_UNDO_LIGHT_ON_COMMAND_HPP_
#define _HFDP_CPP_COMMAND_UNDO_LIGHT_ON_COMMAND_HPP_

#include "Hum_Log_Manager.h"
#include "Hum_Trace.h"

#include "Undo.hpp"

namespace HeadFirstDesignPatterns {
  namespace Command {
    namespace Undo {

      class LightOnCommand : public Command {
        const Light* _light;

      public:
        explicit LightOnCommand( const Light* light) :
          _light(light)
        {
          assert(light);
          HUM_TRACE(ACE_TEXT("LightOnCommand::LightOnCommand"));
        }
        void execute() const
        {
          HUM_TRACE(ACE_TEXT("LightOnCommand::execute"));
          _light->on();
        }
        void undo() const
        {
          HUM_TRACE(ACE_TEXT("LightOnCommand::undo"));
          _light->off();
        }
      };

    } // namespace Undo
  } // namespace Command
} // namespace HeadFirstDesignPatterns

#endif
