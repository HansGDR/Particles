#include "Matrices.h"

namespace Matrices 
{
    Matrix::Matrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        a.resize(rows);
        for (int i = 0; i < rows; i++) 
        {
            a.at(i).resize(cols);
            for (int j = 0; j < cols; j++)
            {
                a.at(i).at(j) = 0;
            }
        }
        
    }
    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            throw runtime_error("Error: dimensions must agree");
        }

        Matrix c(a.getRows(), a.getCols());
        for (int i = 0; i < c.getRows(); i++)
        {
            for (int j = 0; j < c.getCols(); j++) 
            {
                c(i, j) = a(i, j)+ b(i, j);
            }
        }

        return c;
    }
    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getRows())
        {
            throw runtime_error("Error: dimensions must agree");
        }

        Matrix c(a.getRows(), b.getCols());
        
        for (int i = 0; i < c.getRows(); i++)
        {
            for (int j = 0; j < c.getCols(); j++)
            {
                double sum = 0;
                for (int k = 0; k < a.getCols(); k++)
                {
                    sum += a(i, k) * b(k, j);
                }
                c(i, j) = sum;
            }
        }

        return c;
    }
    bool operator==(const Matrix& a, const Matrix& b)
    {
        bool isEqual = true;
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            isEqual = false;
        }
        else
        {
            for (int i = 0; i < a.getRows() && isEqual; i++)
            {
                for (int j = 0; j < a.getCols() && isEqual; j++)
                {
                    if (a(i,j) != b(i,j))
                    {
                        isEqual = false;
                    }
                }
            }
        }
        return isEqual;
    }
    bool operator!=(const Matrix& a, const Matrix& b)
    {
        return !(a == b);
    }
    ostream& operator<<(ostream& os, const Matrix& a)
    {
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                os << setw(10) << a(i, j) << ' ';
            }
            os << endl;
        }
        
        return os;
    }

    RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
    {
        a.at(0).at(0) = cos(theta);
        a.at(0).at(1) = -sin(theta);
        a.at(1).at(0) = sin(theta);
        a.at(1).at(1) = cos(theta);
    }
    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
    {
        a.at(0).at(0) = scale;
        a.at(0).at(1) = 0;
        a.at(1).at(0) = 0;
        a.at(1).at(1) = scale;
    }
    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                if (i == 0) a.at(i).at(j) = xShift;
                else if (i == 1) a.at(i).at(j) = yShift;
            }
        }
    }
}
