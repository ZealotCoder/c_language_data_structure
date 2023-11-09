#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("hello world!\n");
    int i =0;
    scanf("%d",&i);
    printf("%d\n",i);
    //int *test;
    int * test = (int *)malloc(sizeof (int *));
    free(test);
    return 0;
}

//C/C++ 在vscode 上結合 mingw運行的配置文件
//https://blog.csdn.net/qq_39236499/article/details/134147316
//https://blog.csdn.net/baidu_38634017/article/details/99875321
//https://blog.csdn.net/bigfresh_chy/article/details/112387788
//https://blog.csdn.net/qq_36807551/article/details/83058378?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-83058378-blog-112387788.235%5Ev38%5Epc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-83058378-blog-112387788.235%5Ev38%5Epc_relevant_default_base3&utm_relevant_index=7
//https://www.zhihu.com/question/30315894
//https://blog.csdn.net/5hongbing/article/details/77620695
//https://blog.csdn.net/littlelittleR/article/details/121438006

/*
//解决gitignore不生效问题
git rm -r --cached .
git add .
git commit -m "update .gitignore"  // windows使用的命令时，需要使用双引号

*/