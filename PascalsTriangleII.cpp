#include <vector>

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        vector<int> result;

        for(int i = 0; i <= rowIndex; i++) {
            result.clear();
            result.push_back(1);

            for(int j = 1; j < i; j++) {
                result.push_back(temp[j - 1] + temp[j]);
            }

            if(i > 0) {
                result.push_back(1);
            }

            temp = result;
        }

        return result;
    }

    //    public:
    //     vector<int> getRow(int rowIndex) {
    //         vector<vector<int>> result;

    //         for(int i = 0; i <= rowIndex; i++) {
    //             vector<int> row;
    //             row.push_back(1);

    //             for(int j = 1; j < i; j++) {
    //                 row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
    //             }

    //             if(i > 0) {
    //                 row.push_back(1);
    //             }

    //             result.push_back(row);
    //         }

    //         return result[rowIndex];
    //     }
};