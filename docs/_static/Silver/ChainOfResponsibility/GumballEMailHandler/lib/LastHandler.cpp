#include "Handler.hpp"
#include "LastHandler.hpp"
#include "Utilities.hpp"
#include <string>


using namespace HFDP::ChainOfResponsibility::GumballEMailHandler;

LastHandler::LastHandler( const std::shared_ptr<Handler> successor ) :
  Handler( successor )
{
  PrintMessage("LastHandler::LastHandler");
}
void LastHandler::handleRequest( std::string request ) const
{
  PrintMessage("LastHandler::handleRequest");
  Handler::store( request );
}
void LastHandler::print() const
{
  PrintMessage("LastHandler::print");
  PrintMessage("Unclassified, send to AI team:");
  Handler::print();
}
