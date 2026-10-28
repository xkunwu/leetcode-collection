class Solution {
	/** 841. Keys and Rooms
	 * https://leetcode.com/problems/keys-and-rooms/
	 */
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> opened(rooms.size(), false);
        vector<vector<int>> cur, nxt;
        cur.push_back(move(rooms[0]));
        opened[0] = true;
        while (!cur.empty()) {
            for (const vector<int>& room: cur) {
                for (const const int& k: room) {
                    opened[k] = true;
                    nxt.push_back(move(rooms[k]));
                }
            }
            cur = move(nxt);
            // cout << '[';
            // for (const vector<int>& room: rooms) {
            //     cout << '[';
            //     for (const const int& k: room) {
            //         cout << k << ',';
            //     }
            //     cout << ']';
            // }
            // cout << ']' << endl;
            // cout << "cur: [";
            // for (const vector<int>& room: cur) {
            //     cout << '[';
            //     for (const const int& k: room) {
            //         cout << k << ',';
            //     }
            //     cout << ']';
            // }
            // cout << ']' << endl;
            // cout << "opened: [";
            // for (const bool& o: opened) {
            //     cout << o << ',';
            // }
            // cout << ']' << endl;
        }
        for (const int& o: opened) {
            if (false == o) {
                return false;
            }
        }
        return true;
    }
};