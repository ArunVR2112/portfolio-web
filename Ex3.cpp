vector<int> geeksJourney(vector<int>& geeksTown, int n,  
                             vector<int>& journey, int m,  
                             vector<vector<int>>& queries, int q) 
    { 
        // code here 
        vector<int> res; 
        vector<pair<int, int>> sub_arr; // To store the indices of geeksTown subarrays 
 
        for (int i = 0; i <= m - n; ++i) { 
            bool match = true; 
            for (int j = 0; j < n; ++j) { 
                if (geeksTown[j] != journey[i + j]) { 
                    match = false; 
                    break; 
                } 
            } 
            if (match) { 
                sub_arr.push_back(make_pair(i, i + n - 1)); 
            } 
        } 
 
        for (int i = 0; i < q; ++i) { 
            int left = queries[i][0]; 
            int right = queries[i][1]; 
            int count = 0; 
 
            for (const auto& indices : sub_arr) { 
                if (indices.first >= left && indices.second <= right) { 
                    ++count; 
                } 
            } 
 
            res.push_back(count); 
        } 
 
        return res;