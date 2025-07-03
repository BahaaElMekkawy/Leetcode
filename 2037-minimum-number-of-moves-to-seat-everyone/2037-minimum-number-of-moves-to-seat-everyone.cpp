//i can't add the a frequency array or map for the seats or students i has to check all the values before i assign a seat to a student and that will be  O(n*n) and i need to add the min val per seat and student so the better approach is simply to sort both and compare each student and seat of index which can be O(nlog(n)).

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int minMoves = 0;
        for (int i = 0; i < seats.size(); ++i) {
            minMoves += abs(students[i] - seats[i]);
        }
        return minMoves;
    }
};