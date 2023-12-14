/**
 *
 * 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 *
 *
 *
*/

#include <vector>
#include <cstring>
using namespace std;

// 暴力遍历
class Solution
{
public:
    int check[10];

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // check line
        for (auto v : board)
        {
            memset(check, 0, sizeof(check));
            for (auto c : v)
            {
                if (c == '.')
                    continue;

                int num = c - '0';
                if (check[num] == 1)
                    return false;
                else
                    check[num] = 1;
            }
        }

        // check row
        for (int i = 0; i < 9; ++i)
        {
            memset(check, 0, sizeof(check));
            for (int j = 0; j < 9; ++j)
            {
                auto c = board[j][i];
                if (c == '.')
                    continue;
                int num = c - '0';
                if (check[num] == 1)
                    return false;
                else
                    check[num] = 1;
            }
        }

        // check square
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                std::vector<int> square;
                for (int k = i; k < i + 3; ++k)
                {
                    for (int l = j; l < j + 3; ++l)
                    {
                        if( board [k][l] != '.')
                        square.push_back(board[k][l] - '0');
                    }
                }
                memset(check, 0, sizeof(check));
                for (auto num : square)
                {
                    if (check[num] == 1)
                        return false;
                    else
                        check[num] = 1;
                }
            }
        }

        return true;
    }
};

class Solution2
{
public:
    int rows[9][9];
    int cols[9][9];
    int square[3][3][9];

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '0' - 1;
                    if (rows[i][index] >= 1 || cols[j][index] >= 1 || square[i/3][j/3][index] >= 1)
                        return false;
                    
                    rows[i][index]++;
                    cols[j][index]++;
                    square[i/3][j/3][index]++;
                }
            }
        }
        return true;
    }
};