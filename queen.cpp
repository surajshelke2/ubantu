#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<bool>>&arr , int n)
{

    for (int i = 0; i < n; i++)
    {

       
        for (int j = 0; j < n; j++)
        {

            if (arr[i][j] == true)
            {

                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
         cout << endl;
    }
     cout << endl;
}

bool isSafe(vector<vector<bool>>&arr, int row, int col,int n)
{

    for (int i = 0; i < row; i++)
    {
        if (arr[i][col])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {

        if (arr[i][j])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {

        if (arr[i][j])
        {

            return false;
        }
    }
    return true;
}

int Queen(vector<vector<bool>> &arr, int row, int n)
{
    if (row == n)
    {
        display(arr,n);
        return 1;
    }

    int count = 0;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, row, col,n))
        {
            arr[row][col] = true;
            count += Queen(arr, row + 1,n);
            arr[row][col] = false;
        }
    }

    return count;
}

int main()
{

    cout << "Enter the Size of the Queen :";
    int n;
    cin >> n;

    vector<vector<bool>> arr(n, vector<bool>(n, false));

    cout << "No os the Possibility :", Queen(arr, 0, n);
}