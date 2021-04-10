#ifndef TABLE_HPP
#define TABLE_HPP

#include "abstract_table.hpp"
#include "array_list.hpp"
#include "linked_list.hpp"

#define HEADERSIZE 5

template <typename T>
class Table : public AbstractTable<T>
{

private:
	std::size_t numRow;
	std::size_t numCol;
	ArrayList<std::string> header;
	LinkedList<ArrayList<T>> content;


public:

	Table();
	~Table();
	std::size_t numRows() const noexcept;
	std::size_t numCols() const noexcept;
	void setHeader(std::size_t col, std::string name);
	std::string getHeader(std::size_t col);
	void insertRow(std::size_t position, T value);
	void appendRow(T value);
	void insertCol(std::size_t position, std::string name, T value);
	void appendCol(std::string name, T value);
	const T& operator()(std::size_t row, std::size_t col) const;
	T& operator()(std::size_t row, std::size_t col);
	void sortBy(std::size_t col);
	void sortBy(std::string colname);
	void reverseSortBy(std::size_t col);
	void reverseSortBy(std::string colname);
};

#include "table.tpp"

#endif
