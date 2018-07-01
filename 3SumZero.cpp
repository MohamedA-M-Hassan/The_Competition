#https://www.interviewbit.com/problems/3-sum-zero/
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
            
    int sum = 0;
    vector<vector<int> > result;
    int sz = A.size();
    for (int i = 0; i < sz - 2; i++) {
        if (i > 0 && A[i] == A[i - 1]) {
            continue;
        }
        int ptr1 = i + 1, ptr2 = A.size() - 1;
        while (ptr1 < ptr2) {
            sum = A[i] + A[ptr1] + A[ptr2];
            if (sum == 0) {
                vector<int> tmp = {A[i],A[ptr1],A[ptr2]}; 
                result.push_back(tmp);    
            }
            if (sum > 0) {
                ptr2--;
            } else if (sum < 0) {
                ptr1++;
            } else if (sum == 0) {
                //always go left (increasing)
                ptr1++;
                while (ptr1 < ptr2 && A[ptr1] == A[ptr1 - 1]) {
                    ptr1++;
                }
            }
        }
    }
    return result;

}