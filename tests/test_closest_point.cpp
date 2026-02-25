#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <MathVier/vector.hpp>
#include <geom/primitives2d.hpp>

using Catch::Matchers::WithinAbs;

TEST_CASE("ClosestPoint - Ponto no meio do segmento", "[closest_point]") {
    auto result = geom::closestPointOnSegment({0.0f, 1.0f}, {-1.0f, 0.0f}, {1.0f, 0.0f});
    REQUIRE_THAT(result.x, WithinAbs(0.0f, 1e-5f));
    REQUIRE_THAT(result.y, WithinAbs(0.0f, 1e-5f));
}

TEST_CASE("ClosestPoint - Ponto antes do inicio", "[closest_point]") {
    auto result = geom::closestPointOnSegment({-5.0f, 0.0f}, {-1.0f, 0.0f}, {1.0f, 0.0f});
    // Ponto mais próximo deve ser o endpoint 'a'
    REQUIRE_THAT(result.x, WithinAbs(-1.0f, 1e-5f));
    REQUIRE_THAT(result.y, WithinAbs(0.0f, 1e-5f));
}

TEST_CASE("ClosestPoint - Ponto depois do fim", "[closest_point]") {
    auto result = geom::closestPointOnSegment({5.0f, 0.0f}, {-1.0f, 0.0f}, {1.0f, 0.0f});
    // Ponto mais próximo deve ser o endpoint 'b'
    REQUIRE_THAT(result.x, WithinAbs(1.0f, 1e-5f));
    REQUIRE_THAT(result.y, WithinAbs(0.0f, 1e-5f));
}

TEST_CASE("ClosestPoint - Segmento de comprimento zero", "[closest_point]") {
    // Caso degenerado: a == b, deve retornar o próprio ponto a
    auto result = geom::closestPointOnSegment({3.0f, 4.0f}, {1.0f, 1.0f}, {1.0f, 1.0f});
    REQUIRE_THAT(result.x, WithinAbs(1.0f, 1e-5f));
    REQUIRE_THAT(result.y, WithinAbs(1.0f, 1e-5f));
}
