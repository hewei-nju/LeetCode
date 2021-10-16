/* 
给出一个整数数组 A 和有序的整数数组 B ，请将数组 B 合并到数组 A 中，变成一个有序的升序数组

数据范围： 0≤n,m≤100，|A_i| <=100 ∣B_i∣<=100

注意：
1.保证 A 数组有足够的空间存放 B 数组的元素， A 和 B 中初始的元素数目分别为 m 和 n，A的数组空间大小为 m+n
2.不要返回合并的数组，将数组 B 的数据合并到 A 里面就好了
3. A 数组在[0,m-1]的范围也是有序的

*/



class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        while (j < n) {
            if (i < m) {
               if (A[i] <= B[j]) {
                   i++;
                } else {
                   for (int k = m - 1; k >= i; k--) {
                       A[k+1] = A[k];
                   }
                   A[i++] = B[j++];
                   m += 1;
               }
            } else {
                A[m++] = B[j++];
            }
        }
    }
};