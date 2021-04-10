#include "catch.hpp"
#include "table.hpp"


TEST_CASE("Test basic operation of table", "[Table]")
{
	ArrayList<int> a;
	ArrayList<int> b(5);
	a = b;
	REQUIRE(a.getLength() == 5);

	Table<int> test;
	REQUIRE(test.getHeader(1) == "ID");
	test.setHeader(1, "lala");
	REQUIRE(test.getHeader(1) == "lala");
	test.setHeader(1, "ID");
	REQUIRE(test.getHeader(1) == "ID");
	REQUIRE(test.getHeader(2) == "Assignment 1 Grade");
	REQUIRE(test.getHeader(3) == "Assignment 2 Grade");
	REQUIRE(test.getHeader(4) == "Assignment 3 Grade");
	REQUIRE(test.getHeader(5) == "Assignment 4 Grade");

	REQUIRE(test.numCols() == 5);
	REQUIRE(test.numRows() == 0);

}

TEST_CASE("Test append and insert row and col", "[Table]")
{
	Table<int> test;	
	test.appendRow(0);

	REQUIRE(test.numCols() == 5);
	REQUIRE(test.numRows() == 1);
	test.appendRow(2);
	REQUIRE(test.numRows() == 2);
	test.insertRow(2,1);
	REQUIRE(test.numRows() == 3);

	test.appendCol("lastCol", 0);
	REQUIRE(test.numRows() == 3);
	REQUIRE(test.numCols() == 6);

	test.insertCol(2,"midCol", 10);
	REQUIRE(test.numRows() == 3);
	REQUIRE(test.numCols() == 7);
}

TEST_CASE("Test operator()", "[Table]")
{
	Table<int> test;
	test.appendRow(0);
	test.appendRow(1);
	test.appendRow(2);

	REQUIRE(test(1, 3) == 0);
	REQUIRE(test(1, 4) == 0);
	REQUIRE(test(1, 5) == 0);
	REQUIRE(test(2, 3) == 1);
	REQUIRE(test(2, 4) == 1);
	REQUIRE(test(2, 5) == 1);
	REQUIRE(test(3, 3) == 2);
	REQUIRE(test(3, 4) == 2);
	REQUIRE(test(3, 5) == 2);


	test(1, 1) = 12345;
	test(1, 2) = 80;
	test(1, 3) = 74;
	test(1, 4) = 92;
	test(1, 5) = 65;

	test(2, 1) = 55634;
	test(2, 2) = 98;
	test(2, 3) = 94;
	test(2, 4) = 90;
	test(2, 5) = 94;

	test(3, 1) = 98637;
	test(3, 2) = 54;
	test(3, 3) = 49;
	test(3, 4) = 66;
	test(3, 5) = 72;

	REQUIRE(test(1, 1) == 12345);
	REQUIRE(test(2, 3) == 94);
	REQUIRE(test(3, 2) == 54);
	REQUIRE(test(3, 5) == 72);

	test.sortBy(5);
	REQUIRE(test(2, 1) == 98637);
	REQUIRE(test(2, 5) == 72);
	REQUIRE(test(3, 1) == 55634);
	REQUIRE(test(3, 5) == 94);

	test.reverseSortBy(5);
	REQUIRE(test(3, 1) == 12345);
	REQUIRE(test(3, 5) == 65);
	REQUIRE(test(1, 1) == 55634);
	REQUIRE(test(1, 5) == 94);

	test.sortBy("Assignment 4 Grade");
	REQUIRE(test(1, 1) == 12345);
	REQUIRE(test(1, 5) == 65);
	REQUIRE(test(3, 1) == 55634);
	REQUIRE(test(3, 5) == 94);

	test.reverseSortBy("Assignment 4 Grade");
	REQUIRE(test(3, 1) == 12345);
	REQUIRE(test(3, 5) == 65);
	REQUIRE(test(1, 1) == 55634);
	REQUIRE(test(1, 5) == 94);

}