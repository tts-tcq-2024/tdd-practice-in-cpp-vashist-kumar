#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    std::string input = "";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    std::string input = "0";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    std::string input = "1,2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    ASSERT_THROW({
        std::string input = "-1,2";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers2) {
    ASSERT_THROW({
        std::string input = "1,-2,-3";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers3) {
    ASSERT_THROW({
        std::string input = "1,2";
        StringCalculator objUnderTest;
       objUnderTest.add(input);
        }, std::runtime_error);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
     StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    std::string input = "1,1001";
    StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan10002) {
    int expectedresult = 2;
    std::string input = "2,1001";
    StringCalculator objUnderTest;
    int result =objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    std::string input = "//;\n1;2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter2) {
    int expectedresult = 6;
    std::string input = "//[***]\n1***2***3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter3) {
    int expectedresult = 6;
    std::string input = "1\n2\n3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter4) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter5) {
    int expectedresult = 6;
    std::string input = "//[*][%]\n1*2%3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter6) {
    int expectedresult = 6;
    std::string input = "1,2,3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter7) {
    int expectedresult = 6;
    std::string input = "//[***][%%%]\n1***2%%%3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter8) {
    int expectedresult = 6;
    std::string input = "//;\n2;1001";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter9) {
    int expectedresult = 6;
    std::string input = "//;\n2;1001";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForoneNumber1) {
    int expectedresult = 1;
    std::string input = "1";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForfiveNumber1) {
    int expectedresult = 15;
    std::string input = "1,2,3,4,5";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}






assert(calc.add("") == 0);

    // Test 2: Single number
    assert(calc.add("1") == 1);

    // Test 3: Two numbers separated by a comma
    assert(calc.add("1,2") == 3);

    // Test 4: Multiple numbers separated by commas
    assert(calc.add("1,2,3,4,5") == 15);

    // Test 5: Numbers separated by new lines
    assert(calc.add("1\n2\n3") == 6);

    // Test 6: Mixed delimiters (commas and new lines)
    assert(calc.add("1\n2,3") == 6);

    // Test 7: Custom single-character delimiter
    assert(calc.add("//;\n1;2") == 3);

    // Test 8: Custom multi-character delimiter
    assert(calc.add("//[***]\n1***2***3") == 6);

    // Test 9: Custom multiple delimiters
    assert(calc.add("//[*][%]\n1*2%3") == 6);

    // Test 10: Custom multiple multi-character delimiters
    assert(calc.add("//[***][%%%]\n1***2%%%3") == 6);

    // Test 11: Ignore numbers larger than 1000
    assert(calc.add("2,1001") == 2);

    // Test 12: Custom delimiter with numbers larger than 1000
    assert(calc.add("//;\n2;1001") == 2);

    // Test 13: Multiple negatives
    try {
        calc.add("1,-2,-3");
        assert(false); // Should not reach this line
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "negatives not allowed: -2, -3");
    }

    // Test 14: Single negative number
    try {
        calc.add("-1,2");
        assert(false); // Should not reach this line
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "negatives not allowed: -1");
    }

