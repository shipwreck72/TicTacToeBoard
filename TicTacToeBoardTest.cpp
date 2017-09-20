/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

//EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, init)
{
	TicTacToeBoard Brd;
	for(int i=0; i<BOARDSIZE; i++)
    	for(int j=0; j<BOARDSIZE; j++)
			EXPECT_EQ( Blank, Brd.getPiece(i,j));
}

TEST(TicTacToeBoardTest, wincheck_X)
{
	TicTacToeBoard Brd;
	Brd.placePiece(0,0);
	Brd.placePiece(0,1);
	Brd.placePiece(0,2);
	Brd.placePiece(1,0);
	Brd.placePiece(1,1);
	Brd.placePiece(1,2);
	Brd.placePiece(2,0);
	Brd.placePiece(2,1);
	Brd.placePiece(2,2);
	ASSERT_EQ(X, Brd.getWinner());
}

TEST(TicTacToeBoardTest, wincheck_CG)
{
	TicTacToeBoard Brd;
	Brd.placePiece(0,0);
	Brd.placePiece(0,1);
	Brd.placePiece(0,2);
	Brd.placePiece(1,1);
	Brd.placePiece(1,0);
	Brd.placePiece(1,2);
	Brd.placePiece(2,1);
	Brd.placePiece(2,0);
	Brd.placePiece(2,2);
	ASSERT_EQ(Blank, Brd.getWinner());
}

TEST(TicTacToeBoardTest, wincheck_O)
{
	TicTacToeBoard Brd;
	Brd.placePiece(1,0);
	Brd.placePiece(0,0);
	Brd.placePiece(2,0);
	Brd.placePiece(0,1);
	Brd.placePiece(1,1);
	Brd.placePiece(0,2);
	ASSERT_EQ(O, Brd.getWinner());
}

TEST(TicTacToeBoardTest, wincheck_INC)
{
	TicTacToeBoard Brd;
	Brd.placePiece(0,0);
	Brd.placePiece(0,1);
	Brd.placePiece(0,2);
	Brd.placePiece(1,0);
	Brd.placePiece(1,1);
	Brd.placePiece(1,2);
	ASSERT_EQ(Invalid, Brd.getWinner());
}

TEST(TicTacToeBoardTest, firstPiece)
{
	TicTacToeBoard Brd;
	Brd.placePiece(1,1);
	ASSERT_EQ( X, Brd.getPiece(1,1));
}

TEST(TicTacToeBoardTest, fullGame)
{
	TicTacToeBoard Brd;
	Brd.placePiece(0,0);
	EXPECT_EQ( X, Brd.getPiece(0,0));
	Brd.placePiece(0,1);
	EXPECT_EQ( O, Brd.getPiece(0,1));
	Brd.placePiece(0,2);
	EXPECT_EQ( X, Brd.getPiece(0,2));
	Brd.placePiece(1,0);
	EXPECT_EQ( O, Brd.getPiece(1,0));
	Brd.placePiece(1,1);
	EXPECT_EQ( X, Brd.getPiece(1,1));
	Brd.placePiece(1,2);
	EXPECT_EQ( O, Brd.getPiece(1,2));
	Brd.placePiece(2,0);
	EXPECT_EQ( X, Brd.getPiece(2,0));
	Brd.placePiece(2,1);
	EXPECT_EQ( O, Brd.getPiece(2,1));
	Brd.placePiece(2,2);
	EXPECT_EQ( X, Brd.getPiece(2,2));
}

TEST(TicTacToeBoardTest, outBounds)
{
	TicTacToeBoard Brd;
	ASSERT_EQ( Invalid, Brd.getPiece(5,8));
}