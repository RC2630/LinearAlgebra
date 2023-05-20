#include "general/numberUtility.h"
#include "general/abstractFunctions.h"
#include "general/stringUtility.h"

#include "matrix.h"

#ifndef self
#define self (*this)
#endif

Matrix::Matrix(const vector<vector<double>>& entries) {
    this->entries = entries;
}

double& Matrix::operator () (int i, int j) {
    return entries.at(i).at(j);
}

vector<double>& Matrix::getRow(int i) {
    return entries.at(i);
}

vector<double> Matrix::getColumn(int j) {
    return absFunc::map_f<vector<double>, double>(entries, [j] (const vector<double>& row) {
        return row.at(j);
    });
}

int Matrix::numRows() {
    return entries.size();
}

int Matrix::numColumns() {
    return entries.empty() ? 0 : entries.front().size();
}

int Matrix::numEntries() {
    return numRows() * numColumns();
}

/*
input: {{3, 2.4, 3.8}, {7, -6, -2.3}, {0, -0.1, 1.2}}
output:  _                     _
        |    3    2.4    3.8    |
        |    7     -6   -2.3    |
        |_   0   -0.1    1.2   _|
*/
string Matrix::toString(int precision) {
    
    vector<int> columnMaxSizes;
    for (int i = 0; i < numColumns(); i++) {
        columnMaxSizes.push_back(strUtil::maxStringLength(absFunc::map_f<double, string>(getColumn(i), [precision] (const double& entry) {
            return numUtil::roundToNplaces(to_string(entry), precision);
        })));
    }

    vector<string> strRows = {" _"};
    for (int i = 0; i < numRows(); i++) {
        
        string currRow;

        if (i != numRows() - 1) {
            currRow = "|    ";
        } else {
            currRow = "|_   ";
        }

        for (int j = 0; j < numColumns(); j++) {
            string entryStr = numUtil::roundToNplaces(to_string(self(i, j)), precision);
            currRow += strUtil::spaces(columnMaxSizes.at(j) - entryStr.size()) + entryStr + "   ";
        }

        if (i != numRows() - 1) {
            currRow += " |";
        } else {
            currRow += "_|";
        }

        strRows.push_back(currRow);
        
    }

    int rowStrSize = strRows.at(1).size();
    strRows.front() += strUtil::spaces(rowStrSize - 4) + "_";

    return accumulate(strRows.begin(), strRows.end(), string(), [] (string rsf, string curr) {
        return rsf + curr + "\n";
    });

}