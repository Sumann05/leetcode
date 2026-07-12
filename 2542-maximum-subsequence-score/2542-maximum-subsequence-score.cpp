class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int,int>> vp;

        for (int i = 0; i < n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }

        sort(vp.rbegin(), vp.rend());

        priority_queue<long long,
                       vector<long long>,
                       greater<long long>> pq;

        long long sum = 0;
        long long ans = 0;

        for (auto &[mn, val] : vp) {
            pq.push(val);
            sum += val;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, sum * mn);
            }
        }

        return ans;
    }
};