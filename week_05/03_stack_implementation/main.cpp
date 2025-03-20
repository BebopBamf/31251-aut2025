#include <gtest/gtest.h>
#include <string>
#include "myStack.hpp"

TEST(StackTest, defaultConstructor)
{
	MyStack<std::string> stack{};
	EXPECT_TRUE(stack.empty());
}

TEST(StackTest, pushSomeValues)
{
	MyStack<char> stack{};
	stack.push('c');
	stack.push('b');
	stack.push('a');
	EXPECT_EQ(stack.size(), 3);
	EXPECT_EQ(stack.top(), 'a');
}

TEST(StackTest, pushAndPop)
{
	MyStack<int> stack{};
	stack.push(3);
	stack.push(2);
	stack.push(1);
	EXPECT_EQ(stack.size(), 3);
	EXPECT_EQ(stack.top(), 1);
	stack.pop();
	EXPECT_EQ(stack.top(), 2);
	stack.pop();
	EXPECT_EQ(stack.top(), 3);
	stack.pop();
	EXPECT_TRUE(stack.empty());
}

TEST(StackTest, pushAndPopAndPush)
{
	MyStack<std::string> stack{};
	stack.push("you");
	stack.push("are");
	stack.push("how");
	EXPECT_EQ(stack.top(), "how");
	stack.pop();
	stack.push("what");
	EXPECT_EQ(stack.top(), "what");
	stack.push("now");
	EXPECT_EQ(stack.top(), "now");
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
