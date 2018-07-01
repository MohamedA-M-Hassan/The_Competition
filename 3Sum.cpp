#https://www.interviewbit.com/problems/3-sum/
int Solution::threeSumClosest(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    sort(A.begin(), A.end());
    int bestSum = 1000000000, sum = 0;
    // Fix the smallest number in the three integers
    for (int i = 0; i < A.size() - 2; i++) {
        // Now num[i] is the smallest number in the three integers in the solution
        int ptr1 = i + 1, ptr2 = A.size() - 1;
        while (ptr1 < ptr2) {
            sum = A[i] + A[ptr1] + A[ptr2];
            if (abs(B - sum) < abs(B - bestSum)) {
                bestSum = sum;
            }
            if (sum > B) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
    }
    return bestSum;
    
}