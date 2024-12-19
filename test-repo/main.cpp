#include <iostream>
#include <cassert>
#include "candle.h"

void test_body_contains() {
    // Тест 1: значение внутри тела свечи
    Candle candle(10.0, 20.0, 25.0, 5.0);
    assert(candle.body_contains(15.0) && "Test 1 failed: Value inside body");

    // Тест 2: значение на границе (open)
    assert(candle.body_contains(10.0) && "Test 2 failed: Value at open");

    // Тест 3: значение на границе (close)
    assert(candle.body_contains(20.0) && "Test 3 failed: Value at close");
}

void test_contains() {
    // Тест 1: значение внутри всей свечи
    Candle candle(10.0, 20.0, 25.0, 5.0);
    assert(candle.contains(15.0) && "Test 1 failed: Value inside full range");

    // Тест 2: значение на границе (low)
    assert(candle.contains(5.0) && "Test 2 failed: Value at low");

    // Тест 3: значение на границе (high)
    assert(candle.contains(25.0) && "Test 3 failed: Value at high");
}

void test_full_size() {
    // Тест 1: проверка полного размера
    Candle candle(10.0, 20.0, 25.0, 5.0);
    assert(candle.full_size() == 20.0 && "Test 1 failed: Incorrect full size");
}

void test_body_size() {
    // Тест 1: проверка размера тела
    Candle candle(10.0, 20.0, 25.0, 5.0);
    assert(candle.body_size() == 10.0 && "Test 1 failed: Incorrect body size");
}

void test_is_red() {
    // Тест 1: свеча красная
    Candle candle(20.0, 10.0, 25.0, 5.0);
    assert(candle.is_red() && "Test 1 failed: Candle should be red");

    // Тест 2: свеча не красная
    Candle candle2(10.0, 20.0, 25.0, 5.0);
    assert(!candle2.is_red() && "Test 2 failed: Candle should not be red");
}

void test_is_green() {
    // Тест 1: свеча зеленая
    Candle candle(10.0, 20.0, 25.0, 5.0);
    assert(candle.is_green() && "Test 1 failed: Candle should be green");

    // Тест 2: свеча не зеленая
    Candle candle2(20.0, 10.0, 25.0, 5.0);
    assert(!candle2.is_green() && "Test 2 failed: Candle should not be green");
}

void run_tests() {
    test_body_contains();
    test_contains();
    test_full_size();
    test_body_size();
    test_is_red();
    test_is_green();

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    run_tests(); // Запуск автотестов
    return 0;
}
