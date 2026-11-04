class Solution {
    /** 735. Asteroid Collision
     * https://leetcode.com/problems/asteroid-collision/
     */
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (const int& a: asteroids) {
            if (s.empty() || 0 < a || 0 < s.back() * a) {
                s.push_back(a);
                continue;
            }
            while (0 > s.back() + a) { // only negative newcomers collides
                s.pop_back();
                if (s.empty() || 0 > s.back()) {
                    s.push_back(a);
                    break;
                }
            }
            if(0 == s.back() + a) s.pop_back();
            // for (const int& si: s) { cout << si << ' '; } cout << endl;
        }
        return s;
    }
};