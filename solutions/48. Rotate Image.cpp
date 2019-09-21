/** 48. Rotate Image
	https://leetcode.com/problems/rotate-image/
	You are given an n x n 2D matrix representing an image.

	Rotate the image by 90 degrees (clockwise).

	Note:

	You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        const int R = N >> 2;
        for (int rr = 0; rr < R; ++rr) {
            const int Er = N - rr - 1;
            for (int ee = rr; ee < Er; ++ee) {
                const int Ee = N - ee - 1;
                int temp = matrix[rr][ee];
                matrix[rr][ee] = matrix[Ee][rr];
                matrix[Ee][rr] = matrix[Er][Ee];
                matrix[Er][Ee] = matrix[ee][Er];
                matrix[ee][Er] = temp;
                cout << "(" << rr << "," << ee <<")" << " -> "
                    << "(" << Ee << "," << rr <<")" << " -> "
                    << "(" << Er << "," << Ee <<")" << " -> "
                    << "(" << ee << "," << Er <<")" << endl;
            }
        }
    }
};
