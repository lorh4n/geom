#include <geom/primitives2d.hpp>
#include <algorithm>
#include <cmath>

namespace geom
{

   MathVier::Vec2<float> closestPointOnSegment(
       MathVier::Vec2<float> p,
       MathVier::Vec2<float> a,
       MathVier::Vec2<float> b)
   {
      auto ab = b - a;
      auto ap = p - a;

      float abLenght = ab.dot(ab);

      if (abLenght < 1e-9f) {
         return a;
      }

      // Projeção escalar normalizada
      // t = (AP . AB) / (AB . AB)
      auto t = ap.dot(ab) / abLenght;

      t = std::clamp(t, 0.0f, 1.0f);

      return a + (ab * t);
   }

}