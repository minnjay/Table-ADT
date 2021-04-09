#ifndef ABSTRACT_TABLE_HPP
#define ABSTRACT_TABLE_HPP

#include <string>
#include <cstddef>

template<typename T>
class AbstractTable{
public:

  // return the number of rows in the Table
  std::size_t numRows() const noexcept;

  // return the number of columns in the Table
  std::size_t numCols() const noexcept;

  // set column header to the string name
  // valid values for col is [1,numCols()]
  // throws std::invalid_argument if invalid column
  void setHeader(std::size_t col, std::string name);

  // get column header as string
  // valid values for col is [1,numCols()]
  // throws std::invalid_argument if invalid column
  std::string getHeader(std::size_t col);

  // insert row into table at position set to value 
  // valid values for position is [1,numRows()+1]
  // throws std::invalid_argument if invalid
  void insertRow(std::size_t position, T value);

  // append row to table set to value 
  void appendRow(T value);

  // insert column into table at position set to value 
  // valid values for position is [1,numCols()+1]
  // throws std::invalid_argument if invalid
  void insertCol(std::size_t position, std::string name, T value);

  // append column to table set to value 
  void appendCol(std::string name, T value);

  // return constant reference to table entry at (row, col)
  // throws std::invalid_argument if invalid row or column
  const T& operator()(std::size_t row, std::size_t col) const;

  // return reference to table entry at (row, col)
  // throws std::invalid_argument if invalid row or column
  T& operator()(std::size_t row, std::size_t col);

  // stable sort (low to high) of table rows using column col
  // throws std::invalid_argument if invalid column
  void sortBy(std::size_t col);

  // stable sort (low to high) of table rows using column with name
  // throws std::invalid_argument if invalid column name
  void sortBy(std::string colname);

  // stable sort (high to low) of table rows using column col
  // throws std::invalid_argument if invalid column
  void reverseSortBy(std::size_t col);

  // stable sort (high to low) of table rows using column with name
  // throws std::invalid_argument if invalid column name
  void reverseSortBy(std::string colname);
};

#endif

