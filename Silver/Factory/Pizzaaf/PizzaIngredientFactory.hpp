#ifndef	_HFDP_CPP_FACTORY_ABSTRACT_PIZZA_INGREDIENT_FACTORY_HPP_
#define _HFDP_CPP_FACTORY_ABSTRACT_PIZZA_INGREDIENT_FACTORY_HPP_

#include "Pizzaaf.hpp"

namespace HeadFirstDesignPatterns {
  namespace Factory {
    namespace Abstract {

      class PizzaIngredientFactory {
      public:
        virtual Dough* createDough() const = 0;
        virtual Sauce* createSauce() const = 0;
        virtual Cheese* createCheese() const = 0;
        virtual std::vector< Veggies* > createVeggies() const = 0;
        virtual Pepperoni* createPepperoni() const = 0;
        virtual Clams* createClam() const = 0;
        virtual ~PizzaIngredientFactory() {
        }};

    } // namespace Abstract
  } // namespace Factory
} // namespace HeadFirstDesignPatterns

#endif
