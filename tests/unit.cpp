#include <gtest/gtest.h>

#include "../src/function/function.hpp"

class ChangeValueTest : public ::testing::Test {
protected:
  std::string text;
};

// Test 1: Replace every occurence
TEST_F(ChangeValueTest, ReplaceEveryOccurence) {
  text = "hello world";
  ChangeValue(text, 1, 'l', 'x');
  EXPECT_EQ(text, "hexxo worxd");
}

// Test 2: Replace every 2nd occurence
TEST_F(ChangeValueTest, ReplaceEverySecondOccurence) {
  text = "hello worldoo";
  ChangeValue(text, 2, 'o', 'x');
  EXPECT_EQ(text, "hello wxrldox");
}

// Test 3: Replace every 3rd occurence
TEST_F(ChangeValueTest, ReplaceEveryThirdOccurence) {
  text = "hello world";
  ChangeValue(text, 3, 'l', 'x');
  EXPECT_EQ(text, "hello worxd");
}

// Test 4: n equals to 0 - text remains the same
TEST_F(ChangeValueTest, ReplaceEveryZerothOccurence) {
  text = "highly doubtable statement";
  ChangeValue(text, 0, 'a', 'x');
  EXPECT_EQ(text, "highly doubtable statement");
}

// Test 5: n is below 0 - text remains the same
TEST_F(ChangeValueTest, ReplaceEveryNegativeOccurence) {
  text = "highly doubtable statement";
  ChangeValue(text, -1, 'a', 'x');
  EXPECT_EQ(text, "highly doubtable statement");
}

// Test 6: n is greater than number of letter encounters - text remains the same
TEST_F(ChangeValueTest, ReplaceEveryNonexistentlyLargeOccurence) {
  text = "highly doubtable statement";
  ChangeValue(text, 7, 'a', 'x');
  EXPECT_EQ(text, "highly doubtable statement");
}

// Test 7: Empty string - no change expected
TEST_F(ChangeValueTest, EmptyString) {
  text = "";
  ChangeValue(text, 1, ' ', 'x');
  EXPECT_EQ(text, "");
}

// Test 8: Zero occurences of an old value - no change expected
TEST_F(ChangeValueTest, NoOLdValueOccurences) {
  text = "hello world";
  ChangeValue(text, 1, 'z', 'x');
  EXPECT_EQ(text, "hello world");
}

// Test 9: An old value equals to a new one - no change expected
TEST_F(ChangeValueTest, OldEqualsNew) {
  text = "hello world";
  ChangeValue(text, 1, 'l', 'l');
  EXPECT_EQ(text, "hello world");
}

// Test 10: Case sensitivity - old value exists in the text in the lowercase -
// no change expected
TEST_F(ChangeValueTest, CaseSensitive) {
  text = "hello world";
  ChangeValue(text, 1, 'L', 'X');
  EXPECT_EQ(text, "hello world");
}

// Test 11: Single character string that matches
TEST_F(ChangeValueTest, SingleCharacterMatch) {
  text = "a";
  ChangeValue(text, 1, 'a', 'b');
  EXPECT_EQ(text, "b");
}

// Test 16: Single character string no match
TEST_F(ChangeValueTest, SingleCharacterNoMatch) {
  text = "a";
  ChangeValue(text, 1, 'b', 'c');
  EXPECT_EQ(text, "a");
}
