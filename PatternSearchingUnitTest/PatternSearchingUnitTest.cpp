#include <gtest/gtest.h>
#include "PatternSearchingLib.h"

TEST(PatternSearchingUnitTest, NsearchBasic)
{
    std::string text = "1234";
    std::vector<int> index = Nsearch("23", text);
    ASSERT_EQ(index.size(), 1);
}

TEST(PatternSearchingUnitTest, NsearchEmptyPat)
{
    std::string text = "1234";
    ASSERT_THROW(std::vector<int> index = Nsearch("", text), std::logic_error);
}

TEST(PatternSearchingUnitTest, NsearchEmptyTXT)
{
    std::string text = "1234";
    ASSERT_THROW(std::vector<int> index = Nsearch("abc", ""), std::logic_error);
}

TEST(PatternSearchingUnitTest, NsearchPatLongestThanTxt)
{
    std::string text = "1";
    ASSERT_THROW(std::vector<int> index = Nsearch("ab", text), std::logic_error);
}

TEST(PatternSearchingUnitTest, NsearchPatEqualTxt)
{
    std::string text = "1234";
    std::vector<int> index = Nsearch("1234", text);
    ASSERT_EQ(index[0], 0);
}

TEST(PatternSearchingUnitTest, NsearchPatNotInTxt)
{
    std::string text = "4321";
    std::vector<int> index = Nsearch("1234", text);
    ASSERT_EQ(index.size(), 0);
}

TEST(PatternSearchingUnitTest, KMPSearchBasic)
{
    std::string text = "1234";
    std::vector<int> index = KMPSearch("23", text);
    ASSERT_EQ(index[0], 1);
}

TEST(PatternSearchingUnitTest, KMPSearchEmptyPat)
{
    std::string text = "1234";
    ASSERT_THROW( std::vector<int> index = KMPSearch("", text), std::logic_error);
}

TEST(PatternSearchingUnitTest, KMPSearchEmptyTxt)
{
    std::string text = "1234";
    ASSERT_THROW( std::vector<int> index = KMPSearch("abc", ""), std::logic_error);
}

TEST(PatternSearchingUnitTest, KMPSearchPatLongestThanTxt)
{
    std::string text = "1";
    ASSERT_THROW(std::vector<int> index = KMPSearch("ab", text), std::logic_error);
}

TEST(PatternSearchingUnitTest, KMPSearchPatEqualTxt)
{
    std::string text = "1234";
    std::vector<int> index = KMPSearch("1234", text);
    ASSERT_EQ(index[0], 0);
}

TEST(PatternSearchingUnitTest, KMPSearchPatNotInTxt)
{
    std::string text = "4321";
    std::vector<int> index = KMPSearch("1234", text);
    ASSERT_EQ(index.size(), 0);
}

TEST(PatternSearchingUnitTest, RKsearchBasic)
{
    std::string text = "1234";
    std::vector<int> index = RKsearch("23", text, 1);
    ASSERT_EQ(index[0], 1);
}

TEST(PatternSearchingUnitTest, RKsearchEmptyPat)
{
    std::string text = "1234";
    ASSERT_THROW(std::vector<int> index = RKsearch("", text, 1), std::logic_error);
}

TEST(PatternSearchingUnitTest, RKsearchEmptyTxt)
{
    std::string text = "1234";
    ASSERT_THROW(std::vector<int> index = RKsearch("abc", "", 1), std::logic_error);
}

TEST(PatternSearchingUnitTest, RKsearchPatLongestThanTxt)
{
    std::string text = "1";
    ASSERT_THROW(std::vector<int> index = RKsearch("ab", text, 1), std::logic_error);
}

TEST(PatternSearchingUnitTest, RKsearchPatEqualTxt)
{
    std::string text = "1234";
    std::vector<int> index = RKsearch("1234", text, 1);
    ASSERT_EQ(index[0], 0);
}

TEST(PatternSearchingUnitTest, RKsearchPatNotInTxt)
{
    std::string text = "4321";
    std::vector<int> index = RKsearch("23", text, 1);
    ASSERT_EQ(index.size(), 0);
}
