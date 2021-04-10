#include <iostream>
using namespace std;

// union Matrix
// {
//     struct
//     {
//         double _a11, _a12, _a13;
//         double _a21, _a22, _a23;
//         double _a31, _a32, _a33;
//     };

//     double _element[3][3];
// };

/**
 * Union结构中，是共享存储空间的，所以实际上_element和_a11,...,_a33是同一块区域的数据
 * 上述Union结构可以对3x3的矩阵通过_element实现批量处理；
 * 也可以通过_a11,...,_a33实现单独元素的处理，避免了一个一个取值的麻烦
 * 
*/

// int main() {
//     Matrix matrix;
//     for (int i = 0; i <= 2; ++i) {
//         for (int j = 0; j <= 2; ++j) {
//             cin >> matrix._element[i][j];
//         }
//     }
//     double v = matrix._a11*matrix._a22*matrix._a33 + 
// }




struct
{
    int a1;
    int a2;
    int a3;
} data={1,2,3};
int main ()
{
    printf("%d, %d, %d", data.a1, data.a2, data.a3);
    return 0;
}