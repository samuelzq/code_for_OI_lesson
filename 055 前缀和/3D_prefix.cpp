/**
 *
 * @File:   3D_prefix.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-09
 *
 */
#include <stdio.h>
#include <stdlib.h>

// 动态分配三维数组
int*** allocate3DArray(int x, int y, int z) {
    int*** array = (int***)malloc(x * sizeof(int**));
    for (int i = 0; i < x; ++i) {
        array[i] = (int**)malloc(y * sizeof(int*));
        for (int j = 0; j < y; ++j) {
            array[i][j] = (int*)malloc(z * sizeof(int));
        }
    }
    return array;
}

// 释放三维数组
void free3DArray(int*** array, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

// 计算三维前缀和
int*** computePrefixSum3D(int*** matrix, int x, int y, int z) {
    int*** prefixSum = allocate3DArray(x, y, z);

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                prefixSum[i][j][k] = matrix[i][j][k];
                if (i > 0) prefixSum[i][j][k] += prefixSum[i - 1][j][k];
                if (j > 0) prefixSum[i][j][k] += prefixSum[i][j - 1][k];
                if (k > 0) prefixSum[i][j][k] += prefixSum[i][j][k - 1];
                if (i > 0 && j > 0) prefixSum[i][j][k] -= prefixSum[i - 1][j - 1][k];
                if (i > 0 && k > 0) prefixSum[i][j][k] -= prefixSum[i - 1][j][k - 1];
                if (j > 0 && k > 0) prefixSum[i][j][k] -= prefixSum[i][j - 1][k - 1];
                if (i > 0 && j > 0 && k > 0) prefixSum[i][j][k] += prefixSum[i - 1][j - 1][k - 1];
            }
        }
    }

    return prefixSum;
}

int main() {
    // 示例：初始化一个 2x2x2 的三维数组
    int x = 2, y = 2, z = 2;
    int*** matrix = allocate3DArray(x, y, z);

    // 填充数据
    matrix[0][0][0] = 1; matrix[0][0][1] = 2;
    matrix[0][1][0] = 3; matrix[0][1][1] = 4;
    matrix[1][0][0] = 5; matrix[1][0][1] = 6;
    matrix[1][1][0] = 7; matrix[1][1][1] = 8;

    // 计算前缀和
    int*** prefixSum = computePrefixSum3D(matrix, x, y, z);

    // 打印结果
    printf("Prefix Sum:\n");
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                printf("prefixSum[%d][%d][%d] = %d\n", i, j, k, prefixSum[i][j][k]);
            }
        }
    }

    // 释放内存
    free3DArray(matrix, x, y);
    free3DArray(prefixSum, x, y);

    return 0;
}

