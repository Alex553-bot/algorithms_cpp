// this code calculates de minimum (max element) of an array in O(n) with arrays of length 'k'
vector<int> v(n);
    auto f = [&](int k) {
        deque<array<int,2>> pq;
        auto add = [&](int x, int i) {
            while (pq.size() && pq.back()[0] < x) pq.pop_back();
            pq.push_back({x, i});
        };

        for (int i = 0; i<k; i++) add(v[i], i);
        int res = pq.front()[0]; 
        for (int i = k; i<n;i++) {
            while (pq.size() && pq.front()[1] <= i-k) pq.pop_front();
            add(v[i], i);
            res = min(res, pq.front()[0]);
        }
        return res; 
    };