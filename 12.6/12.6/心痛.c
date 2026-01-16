#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//    int n = 0, m = 0;
//    scanf("%d%d", &n, &m);
//    int arr[3001] = { 0 };
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    
//    int min = 0;
//   
//    for (i = 0; i < m; i++) {
//        min += arr[i];
//    }
//    int tmp = min;
//
//   
//    for (i = 1; i <= n - m; i++) {
//        
//        tmp = tmp - arr[i - 1] + arr[i + m - 1];
//        if (tmp < min) {
//            min = tmp;
//        }
//    }
//
//    printf("%d\n", min);
//    return 0;
//}