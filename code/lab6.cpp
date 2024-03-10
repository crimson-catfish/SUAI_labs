#include <cmath>
#include <stdio.h>
#include <iostream>
#include <tuple>
using namespace std;

// ========== colsole table header =============
#ifndef CONSOLE_TABLE_H
#define CONSOLE_TABLE_H

#include <vector>
#include <iterator>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <memory>
#include <sstream>
#include <forward_list>

enum class Align
{
    Left,
    Right,
    Center
};
typedef std::forward_list<std::string> Row;

class ConsoleTable
{
public:
    ConsoleTable() = delete;
    ~ConsoleTable() = default;
    ConsoleTable(unsigned int numberOfColumns);

public:
    void WriteTable(Align align = Align::Left, std::ostream *stream = &std::cout) const;
    void AddNewRow(const std::forward_list<std::string> &list);

private:
    void GenerateStream(std::stringstream &, Align align, int i, const std::vector<int> &columnsWidth) const;
    std::string AlignRowToLeftOrRight(Align align, int index, const std::vector<int> &columnsWidth) const;
    std::string AlignRowToCenter(int index, const std::vector<int> &columnsWidth) const;
    void WriteBorderToStream(int width, std::stringstream *stream) const;
    std::vector<int> GetColumnsMaxWidth() const;

private:
    unsigned int _numberOfColumns;
    std::vector<std::vector<std::string>> _rows;
};
#endif
// ========== end of colsole table header =============

double precision;

tuple<double, int> CalculateSum(double x);
int factorial(int num);

int main()
{
    float start, end, step;
    char quitOrRestart = 'r';

    do
    {
        cout << "\nEnter argument start: ";
        cin >> start;

        cout << "Enter argument end: ";
        cin >> end;

        cout << "Enter argument step (step != 0): ";
        cin >> step;
        if (step == 0)
        {
            cout << "Invalid input! step shouldn't be equal to 0";
            continue;
        }
        if (step > 0 && end < start)
        {
            cout << "Invalid input! step should be greater than 0 if end > start";
            continue;
        }
        if (step < 0 && end > start)
        {
            cout << "Invalid input! step should be less than 0 if end < start";
            continue;
        }

        cout << "Enter precision (0 < precision <= 0.1): ";
        cin >> precision;
        if (0 >= precision || precision > 0.1)
        {
            cout << "Invalid input! Please enter a number between than 0";
            continue;
        }
        if (max(fabs(start), fabs(end)) / precision > 1000)
        {
            cout << "too precise for given start-end. variables would overflow";
            continue;
        }

        ConsoleTable table(4);
        table.AddNewRow({"argument", "sum", "terms count", "reference value"});
        for (double x = start; x <= end; x += step)
        {
            tuple<double, int> result = CalculateSum(x);
            table.AddNewRow({to_string(x),
                             to_string(get<0>(result)),
                             to_string(get<1>(result)),
                             to_string(sinh(x))});
        }

        cout << "\n";
        table.WriteTable(Align::Center);

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}
tuple<double, int> CalculateSum(double x)
{
    double sum = 0;
    double currentTerm = x;
    double oddPoweredX = x;
    int n = 1;
    while (fabs(currentTerm) > precision)
    {
        currentTerm = (double)oddPoweredX / (double)factorial(n);
        printf("%i, %lf, %lf\n", n, currentTerm, oddPoweredX);
        sum += currentTerm;
        n += 2;
        oddPoweredX *= x * x;
        if (isinf(oddPoweredX))
        {
            cout << "overflow";
            break;
        }
    }
    cout << endl;
    return {sum, n};
}
int factorial(int num)
{
    if (num <= 1)
        return 1;
    return (num * factorial(num - 1));
}

// ========== colsole table lib =============
ConsoleTable::ConsoleTable(unsigned int numberOfColumns) : _numberOfColumns(numberOfColumns)
{
}

void ConsoleTable::WriteTable(Align align, std::ostream *outputStream) const
{
    int gridWidth = 0;
    std::stringstream stream;
    std::vector<int> columnsWidth = GetColumnsMaxWidth();

    for (int i = 0; i < _rows.size(); i++)
    {
        if (gridWidth == 0)
        {
            std::stringstream testStream;
            GenerateStream(testStream, align, i--, columnsWidth);
            gridWidth = testStream.str().length();
            continue;
        }
        WriteBorderToStream(gridWidth, &stream);
        GenerateStream(stream, align, i, columnsWidth);
    }
    WriteBorderToStream(gridWidth, &stream);

    // Write string stream to stream
    *outputStream << stream.str();
}

void ConsoleTable::AddNewRow(const std::forward_list<std::string> &list)
{
    std::vector<std::string> row;
    row.reserve(_numberOfColumns);
    std::copy_n(list.begin(), _numberOfColumns, std::back_inserter(row));
    _rows.emplace_back(row);
}

void ConsoleTable::GenerateStream(std::stringstream &stream, Align align, int i, const std::vector<int> &columnsWidth) const
{
    if (align == Align::Center)
        stream << AlignRowToCenter(i, columnsWidth);
    else
        stream << AlignRowToLeftOrRight(align, i, columnsWidth);
}

std::string ConsoleTable::AlignRowToLeftOrRight(Align align, int index, const std::vector<int> &columnsWidth) const
{
    std::stringstream stream;

    // Write Table to string stream
    for (int j = 0; j < _numberOfColumns; j++)
        stream << "|" << std::setw(columnsWidth.at(j)) << ((align == Align::Left) ? std::left : std::right) << _rows[index][j];
    stream << '|' << std::endl;

    return stream.str();
}

std::string ConsoleTable::AlignRowToCenter(int index, const std::vector<int> &columnsWidth) const
{
    std::stringstream stream;

    // Write Table to string stream
    for (int j = 0; j < _numberOfColumns; j++)
    {
        std::string word = _rows[index][j];
        stream << "|";
        if (word.length() == columnsWidth.at(j))
            stream << word;
        else
        {
            int index1 = int(columnsWidth.at(j) / 2) - (int(word.length() / 2));
            for (int i = 0; i < index1; i++)
                stream << " ";
            stream << word;
            for (int i = index1 + word.length(); i < columnsWidth.at(j); i++)
                stream << " ";
        }
    }
    stream << '|' << std::endl;

    return stream.str();
}

void ConsoleTable::WriteBorderToStream(int width, std::stringstream *stream) const
{
    *stream << "+";
    for (int k = 0; k <= width - 4; k++)
        *stream << "-";
    *stream << "+" << std::endl;
}

std::vector<int> ConsoleTable::GetColumnsMaxWidth() const
{
    std::vector<int> columnsWidth;
    for (int i = 0; i < _numberOfColumns; i++)
    {
        std::vector<int> width(_rows.size());
        for (int j = 0; j < _rows.size(); j++)
            width[j] = _rows[j][i].length();
        columnsWidth.push_back(*std::max_element(width.begin(), width.end()));
    }
    return columnsWidth;
}
// ========== end colsole table lib =============
