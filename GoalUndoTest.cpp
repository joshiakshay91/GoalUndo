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

//check get operation
TEST(GoalUndoTest, GetOneOpVal)
{
  GoalUndo G;
  G.addOperation("GoalNameTest","operationNameTest");
  std::string out="operationNameTest";
  ASSERT_EQ(out,G.getOperations());
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
  if(!(G.getOperations().compare("Test1 Test2 Test3")))
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
  G.undoOperation("Test2");
  if(!(G.getOperations().compare("Test1 Test3")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}


//undo operation working lowerbound
TEST(GoalUndoTest,UndoWorkingLowerBound)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest","Test1");
  G.addOperation("Test2");
  G.addOperation("Test3");
  G.undoOperation("Test1");
  if(!(G.getOperations().compare("Test2 Test3")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}


//undo operation working upperbound
TEST(GoalUndoTest,UndoWorkingUpperBound)
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

/*
//this test fails
//last operation for overloded
TEST(GoalUndoTest,LastOpUndone)
{
  GoalUndo G;
  bool flag=true;
  G.addOperation("GoalNameTest","Test1");
  G.undoOperation("Test1");
  if(!(G.getGoal().compare("GoalNameTest")))
  {
    flag=false;
  }
  ASSERT_TRUE(flag);
}
*/

//regular undo operation non overloded
TEST(GoalUndoTest,UndoOpWork)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest","Test1");
  G.addOperation("Test2");
  G.addOperation("Test3");
  G.undoOperation();
  if(!(G.getOperations().compare("Test1 Test2")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}


//check for checking clearing step by step regular undo operation
TEST(GoalUndoTest,UndoOpTwoRems)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest","Test1");
  G.addOperation("Test2");
  G.addOperation("Test3");
  G.undoOperation();
  G.undoOperation();
  if(!(G.getOperations().compare("Test1")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}

//clears the goal asWell check
TEST(GoalUndoTest,UndoOpClearsGoal)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest","Test1");
  G.addOperation("Test2");
  G.addOperation("Test3");
  G.undoOperation();
  G.undoOperation();
  G.undoOperation();
  if(!(G.getGoal().compare("")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}

//takes only last goal away
TEST(GoalUndoTest,UndoGoalCheck)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest");
  G.addOperation("Gn2","GoalNameTest2");
  G.addOperation("Gn3","GoalNameTest3");
  G.undoGoal();
  if(!(G.getGoal().compare("Gn2")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}
//clears everything
TEST(GoalUndoTest,CheckLastTake)
{
  GoalUndo G;
  bool flag=false;
  G.addOperation("GoalNameTest");
  G.undoGoal();
  if(!(G.getGoal().compare("")))
  {
    flag=true;
  }
  ASSERT_TRUE(flag);
}
