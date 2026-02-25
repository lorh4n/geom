// geom/include/geom/primitives2d.hpp
#include <MathVier/vector.hpp>  // já está no path porque linkamos MathVier

namespace geom {
    // Usa Vec2 do MathVier diretamente
    MathVier::Vec2<float> closestPointOnSegment(
        MathVier::Vec2<float> p,
        MathVier::Vec2<float> a,
        MathVier::Vec2<float> b
    );
}