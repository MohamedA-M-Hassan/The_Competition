#https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i =0;
    int j=0;
    vector<int> Result;
    while(i < A.size() && j < B.size())
    {
        if(A[i] < B[j])
            i++;
        else if (A[i] > B[j])
            j++;
        else {
            Result.push_back(A[i]);
            i++;
            j++;
        }
    }
    return Result;
}