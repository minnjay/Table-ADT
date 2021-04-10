#include "table.hpp"

#include <stdexcept>

template<typename T>
Table<T>::Table()
{
	numRow = 0;
	numCol = 5;
	ArrayList<std::string> temp(5);
	header = temp;
	(*this).setHeader(1,"ID");
	(*this).setHeader(2,"Assignment 1 Grade");
	(*this).setHeader(3,"Assignment 2 Grade");
	(*this).setHeader(4,"Assignment 3 Grade");
	(*this).setHeader(5,"Assignment 4 Grade");

}

template<typename T>
Table<T>::~Table()
{
	numRow = 0;
	numCol = 0;
	header.clear();
	content.clear();
}

template<typename T>
std::size_t Table<T>::numRows() const noexcept
{
	return numRow;
}


template<typename T>
std::size_t Table<T>::numCols() const noexcept
{
	return numCol;
}

template<typename T>
void Table<T>::setHeader(std::size_t col, std::string name)
{
	if(col<=0 || col>numCols())
	{
		throw std::invalid_argument("invalid column position");
	}
	else
	{
		header.getEntry(col) = name;
	}
}

template<typename T>
std::string Table<T>::getHeader(std::size_t col)
{
	if(col<=0 || col>numCols())
	{
		throw std::invalid_argument("invalid column position");
	}
	else
	{
		return header.getEntry(col);
	}
	
}

template<typename T>
void Table<T>::insertRow(std::size_t position, T value)
{
	if(position<=0 || position>numRows()+1)
	{
		throw std::invalid_argument("invalid row position");
	}
	else
	{
		ArrayList<T> temp(numCols());
		for(std::size_t i = 1; i<=temp.getLength(); ++i)
		{
			temp.getEntry(i) = value;
		}
		content.insert(position, temp);
		numRow++;
	}

}

template<typename T>
void Table<T>::appendRow(T value)
{
	(*this).insertRow(numRows()+1, value);
}

template<typename T>
void Table<T>::insertCol(std::size_t position, std::string name, T value)
{
	if(position<=0 || position>numCols()+1)
	{
		throw std::invalid_argument("invalid col position");
	}
	else
	{
		header.insert(position, name);
		for(std::size_t i = 1; i<=content.getLength(); ++i)
		{
			content.getEntry(i).insert(position, value);
		}
		numCol++;
	}
}

template<typename T>
void Table<T>::appendCol(std::string name, T value)
{
	(*this).insertCol(numCols()+1, name, value);
}

template<typename T>
const T& Table<T>::operator()(std::size_t row, std::size_t col) const
{
	if(col<=0 || col>numCols() || row<=0 || row>numRows())
	{
		throw std::invalid_argument("invalid position");
	}
	else
	{
		const T& a = content.getEntry(row).getEntry(col);
		return a;
	}

}

template<typename T>
T& Table<T>::operator()(std::size_t row, std::size_t col)
{
	if(col<=0 || col>numCols() || row<=0 || row>numRows())
	{
		throw std::invalid_argument("invalid position");
	}
	else
	{
		T& a = content.getEntry(row).getEntry(col);
		return a;
	}

}

template<typename T>
void Table<T>::sortBy(std::size_t col)
{
	if(col<=0 || col>numCols())
	{
		throw std::invalid_argument("invalid position");
	}
	else
	{
		std::size_t index;
		for(std::size_t i = 1; i <= numRows(); ++i)
		{
			index = i;
			for(std::size_t j = i+1; j <= numRows(); ++j)
			{
				if(content.getEntry(j).getEntry(col) < content.getEntry(index).getEntry(col))
				{
					index = j;
				}
			}
			ArrayList<T> temp = content.getEntry(index);
			content.getEntry(index) = content.getEntry(i);
			content.getEntry(i) = temp;
		}
	}

}

template<typename T>
void Table<T>::sortBy(std::string colname)
{
	std::size_t target;
	bool check = false;
	for(std::size_t i = 1; i<= numCols(); ++i)
	{
		if(header.getEntry(i) == colname)
		{
			check = true;
			target = i;
			break;
		}
	}
	if(!check)
	{
		throw std::invalid_argument("invalid column name");
	}
	else
	{
		std::size_t index;
		for(std::size_t i = 1; i <= numRows(); ++i)
		{
			index = i;
			for(std::size_t j = i+1; j <= numRows(); ++j)
			{
				if(content.getEntry(j).getEntry(target) < content.getEntry(index).getEntry(target))
				{
					index = j;
				}
			}
			ArrayList<T> temp = content.getEntry(index);
			content.getEntry(index) = content.getEntry(i);
			content.getEntry(i) = temp;
		}
		
	}

}

template<typename T>
void Table<T>::reverseSortBy(std::size_t col)
{
	if(col<=0 || col>numCols())
	{
		throw std::invalid_argument("invalid position");
	}
	else
	{
		std::size_t index;
		for(std::size_t i = 1; i <= numRows(); ++i)
		{
			index = i;
			for(std::size_t j = i+1; j <= numRows(); ++j)
			{
				if(content.getEntry(j).getEntry(col) > content.getEntry(index).getEntry(col))
				{
					index = j;
				}
			}
			ArrayList<T> temp = content.getEntry(index);
			content.getEntry(index) = content.getEntry(i);
			content.getEntry(i) = temp;
		}
	}

}

template<typename T>
void Table<T>::reverseSortBy(std::string colname)
{
	std::size_t target;
	bool check = false;
	for(std::size_t i = 1; i<= numCols(); ++i)
	{
		if(header.getEntry(i) == colname)
		{
			check = true;
			target = i;
			break;
		}
	}
	if(!check)
	{
		throw std::invalid_argument("invalid column name");
	}
	else
	{
		std::size_t index;
		for(std::size_t i = 1; i <= numRows(); ++i)
		{
			index = i;
			for(std::size_t j = i+1; j <= numRows(); ++j)
			{
				if(content.getEntry(j).getEntry(target) > content.getEntry(index).getEntry(target))
				{
					index = j;
				}
			}
			ArrayList<T> temp = content.getEntry(index);
			content.getEntry(index) = content.getEntry(i);
			content.getEntry(i) = temp;
		}
		
	}

}


