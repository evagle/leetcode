#include <iostream>

using namespace std;
class Solution {
public:
    // 核心思想是去掉A，B中比Kth大得所有数
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // 如果m+n是奇数，找最中间的数
		if ((m + n) & 0x1) {
            return findKth(A, m, B, n, (m + n) / 2 + 1);
        } else { // 如果m+n是偶数，找最中间的两个取平均值
            return (findKth(A, m, B, n, (m + n) / 2) + 
                    findKth(A, m, B, n, (m + n) / 2 + 1)) / 2;
        }
    }
    double findKth(int A[], int m, int B[], int n, int k)
    {
		//cout<<m<<", "<<n<<endl;
        // 保证A数组是更短的一个
        if (m > n) 
            return findKth(B, n, A, m, k);
        // m = 0,说明A数组空了，那么就从B中找第K大的
        if (m == 0)
            return B[k-1];
	 
        // 如果已经排除掉m+n-k+1个元素，现在只剩下K个，那两个数组中最大数中更大得
        if (m + n <= k) {
            return std::max(A[m-1], B[n-1]);
        }
        /** 
		* p取其中k/2+1和m中的小值, 
		* 注意需要取k/2+1，因为q的取值没有限制，需要保证q满足q<m
		* 如果p取k/2,当k为奇数时，q就可能会小于m，
		* 例子:A={1,2,2}, B={1,2,3}, p,q会一直是1，3，出现死循环  
		*/
        int p = std::min(k/2+1, m);
        int q = k - p + 1;
		/**
		* 如果A[p-1] < B[q-1],
		* A[0..p-1]和B[0..q-2]都小于B[q-1]
		* 总共p+q-1=k个，所以有k个数小于B[q-1]，所以B[q-1]不可能是第K大
		* 将B[q-1..m]删除, 递归查找A[0..m]~B[0..q-1]
		*
		* A[p-1] < B[q-1]类似
		*
		* 如果相等，说明第K大和第K+1大的数相等，A[p-1] ，B[q-1]其中一个第K大，另一个第K+1大.
		* 直接返回A[p-1]
		*/
        if (A[p-1] < B[q-1]) 
            return findKth(A, m, B, q-1, k);
        else if (A[p-1] > B[q-1]) 
            return findKth(A, p-1, B, n, k);
        else 
            return A[p-1];
    }
	void p(int a[], int n)
	{
		for (int i = 0; i < n; i++) {
			cout<<a[i]<<"  ";
		}	 
		cout<<endl;
	}
};


int main(int argc, char *argv[]) {
	int A[] = {1,2,2};
	int B[] = {1,2,3};
	Solution s;
	cout<<s.findMedianSortedArrays(A,3,B,3);
}