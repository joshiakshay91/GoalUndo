/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
#include<iostream>
using namespace std;
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
//Sanity check test
TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//Just check empty goal
TEST(GoalUndoTest, GetEmptyGoal)
{
  GoalUndo G;
  std::string out="";
  ASSERT_EQ(out,G.getGoal());
}


//Just check goal there or not
TEST(GoalUndoTest, GetOneVal)
{
  GoalUndo G;
  G.addOperation("GoalNameTest","operationNameTest");
  std::string out="GoalNameTest";
  ASSERT_EQ(out,G.getGoal());
}


//Just check empty goal is not added
TEST(GoalUndoTest, TryEmptyGoal)
{
  GoalUndo G;
  G.addOperation("","operationNameTest");
  std::string out="";//to check this I will see wheter operation is also empty
  ASSERT_EQ(out,G.getOperations());
}


//Just check empty operation is not added
TEST(GoalUndoTest, TryEmptyOperation)
{
  GoalUndo G;
  G.addOperation("GoalNameTest","");
  std::string out="";//to check this I will see wheter operation is also empty
  ASSERT_EQ(out,G.getGoal());
}


//add operations in here
TEST(GoalUndoTest, AddingPrintingOps)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest","Test1");
  G.addOperation("Test2");
  G.addOperation("Test3");
  if(G.getOperations()=="Test1 Test2 Test3")
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}

//NO goals exist I add operation
TEST(GoalUndoTest, NgoalsAddOps)
{
  bool flag=false;
  GoalUndo G;
  G.addOperation("Name Of operation n goal");
  if(!(G.getGoal().compare("Name Of operation n goal")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}

//undo operation working check
TEST(GoalUndoTest,UndoWorkingCheck)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest","Test1");
  G.addOperation("Test2");
  G.addOperation("Test3");
  G.undoOperation("Test3");
  if(!(G.getOperations().compare("Test1 Test2")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);


}
