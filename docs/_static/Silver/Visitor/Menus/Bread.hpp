#ifndef	_HFDP_CPP_VISITOR_BREAD_HPP_
#define _HFDP_CPP_VISITOR_BREAD_HPP_

namespace HeadFirstDesignPatterns {
  namespace Visitor {
    namespace Menus {

      class Bread : public Ingredient {

      public:
        explicit Bread( float amount = 1.0f ) :
          Ingredient( amount )
        {}
        void accept( Visitor* visitor )
        {
          assert( visitor );
          return visitor->visit( this );
        }
        float getCalories() const
        {
          return 120.0f;
        };
        float getCarbs() const
        {
          return 23.0f;
        };
        float getProtien() const
        {
          return 3.0f;
        }
        float getFat() const
        {
          return 1.0f;
        }
        float getCholesterol() const
        {
          return 0.0f;
        }
        float getSodium() const
        {
          return 0.306f;
        }
        bool isVegetarian() const
        {
          return true;
        }
        std::string toString() const
        {
          std::stringstream result;
          result << "Bread(" << _amount << ")";
          return result.str();
        }
      };

    } // namespace Menus
  } // namespace Visitor
} // namespace HeadFirstDesignPatterns

#endif
