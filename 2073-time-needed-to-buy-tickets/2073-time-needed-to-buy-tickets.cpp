// Approach:
// We simulate the queue of people buying tickets. Each second:
// 1. The person at the front buys 1 ticket.
// 2. If they still need tickets, they go to the back of the queue.
// 3. If they finish, they leave the queue.
// We track the position of the k-th person with an index variable `k`.
// Every second we increment `time`. The loop stops when the k-th person finishes buying tickets.
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = tickets.size();

        for (int i = 0; i < n; ++i) {
            q.push(tickets[i]);
        }

        int time = 0;

        while (q.size()>=1) {
            int curr = q.front(); 
            q.pop();

            curr--; 
            time++; 

            if (k == 0 && curr == 0) {
                break;
            }

            if (curr > 0) {
                q.push(curr);
            }

            if (k == 0) {
                k = q.size() - 1; 
            } else {
                k--; 
            }
        }

        return time;
    }
};
