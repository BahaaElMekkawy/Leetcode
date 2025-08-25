// Approach:
// - Maintain a queue to store all request timestamps.
// - On each ping(t):
//     - Push the current timestamp t into the queue.
//     - Remove all timestamps from the front that are older than (t - 3000).
// - The size of the queue after cleanup = number of recent requests.

// Time Complexity: O(n) in worst case across all calls, but amortized O(1) per ping 
//                  (since each timestamp is pushed and popped at most once).
// Space Complexity: O(n), where n = number of pings in the last 3000ms.

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */