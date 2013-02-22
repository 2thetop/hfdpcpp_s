#ifndef	_HFDP_CPP_FACTORY_CHICAGO_CLAM_PIZZA_HPP_
#define _HFDP_CPP_FACTORY_CHICAGO_CLAM_PIZZA_HPP_

#include "Hum_Log_Manager.h"
#include "Hum_Trace.h"

#include "Pizzafm.hpp"

namespace HeadFirstDesignPatterns {
  namespace Factory {
    namespace Method {

      class ChicagoStyleClamPizza : public Pizza {

      public:
        ChicagoStyleClamPizza()
        {
          HUM_TRACE(ACE_TEXT("ChicagoStyleClamPizza::ChicagoStyleClamPizza"));
          _name = "Chicago Style Clam Pizza";
          _dough = "Extra Thick Crust Dough";
          _sauce = "Plum Tomato Sauce";
          _toppings.push_back( "Shredded Mozzarella Cheese" );
          _toppings.push_back( "Frozen Clams from Chesapeake Bay" );
        }
        void cut() const
        {
          HUM_TRACE(ACE_TEXT("ChicagoStyleClamPizza::cut"));
          std::cout << "Cutting the pizza into square slices" << std::endl;
        }
      };

    } // namespace Method
  } // namespace Factory
} // namespace HeadFirstDesignPatterns

#endif
