#include "headers/HashTable.hpp"

#include <gtest/gtest.h>

TEST(HashTable, table) 
{
    std::string S1 = "anagram";
    std::string S2 = "agnaram";
    HashTable<std::string,std::string> table;
    table.insert(S1,S1);
    table.insert(S2,S2);
    table.printValue(S1);
    table.printValue(S2);
    EXPECT_TRUE(table.anagram(S1,S2));
}

TEST(HashTable, table2) 
{
    std::string S1 = "rat";
    std::string S2 = "cat";
    HashTable<std::string,std::string> table;
    table.insert(S1,S1);
    table.insert(S2,S2);
    table.printValue(S1);
    table.printValue(S2);
    EXPECT_TRUE(table.anagram(S1,S2));
}

TEST(HashTable, table3) 
{
    std::string S1 = "heart";
    std::string S2 = "earth";
    HashTable<std::string,std::string> table;
    table.insert(S1,S1);
    table.insert(S2,S2);
    table.printValue(S1);
    table.printValue(S2);
    EXPECT_TRUE(table.anagram(S1,S2));
}

TEST(HashTable, find)
{
    std::string S1 = "heart";
    std::string S2 = "earth";
    HashTable<std::string,std::string> table;
    table.insert(S1,S1);
    table.insert(S2,S2);
    EXPECT_TRUE(table.find("heart",S1));
}

TEST(HashTable, remove)
{
    std::string S1 = "heart";
    std::string S2 = "earth";
    HashTable<std::string,std::string> table;
    table.insert(S1,S1);
    table.insert(S2,S2);
    table.remove(S1);
    table.printValue(S1);
}

int
main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

