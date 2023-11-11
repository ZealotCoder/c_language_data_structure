!!!重要提醒
按照下面的提示进行配置后, 我们运行linked_list_struct\single_linked_list\single_linked_list.c和linked_list_struct\single_linked_list\example.c
全都报错, 报错位置我在代码标注了, 实在是找不到原因, 所以,我放弃了!!!TMD

然后上面的两个报错, 我将文件拷贝到Linux 下, 正常运行......
我转到VM&Centos下去了,
再见!!!


开发环境软件版本说明：
OS: 
    版本：Windows 10 企业版 
    版本号：22H2
    处理器：11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz

VSCode：Visual Studio Code 1.84.1
MinGW:  x86_64-posix-seh-rev0, Built by MinGW-W64 project
Git:    Git [Git.Git] 版本 2.42.0.2

环境配置步骤：
1. 安装VSCode
2. 安装MinGW
3. 安装Git
4. 配置VSCode & MinGW 开发环境并运行 环境测试代码
5. 创建代码仓库， 并向Gitee 推送代码
6. 环境配置完成

详解步骤：
1. 安装VScode，过程自行百度。参考链接：https://blog.csdn.net/weixin_43492780/article/details/119876493
2. 安装MinGW，过程自行百度。参考链接：https://blog.csdn.net/weixin_43492780/article/details/119876493
    请注意配置MinGW的环境变量！配置完在Windows 的cmd中使用以下命令进行检查是否成功！
        where gcc
        gcc --version
        g++ --version
        gdb --version
3. 配置VSCode & MinGW的开发环境，（这是保证代码能编译并且最终跑起来， 但是她不会生成exe文件， 无法进行gdb调试）
    3.1 创建空文件夹， 并且在VSCode中打开该文件夹， 创建test.c 文件，
    3.2 在VScode中 Ctrl + Shift + P 调出命令面板，
        输入 C/C++ ，选择 Edit Configurations(UI) 进入 IntelliSense配置;
        点击c_cpp_properties.json文件进行编辑以下内容：
    ```
        {
            "configurations": [
                {
                    "name": "MinGW_C",
                    "includePath": [
                        "c:/C_language_data_structure/**"
                    ],
                    "defines": [
                        "_DEBUG",
                        "UNICODE",
                        "_UNICODE"
                    ],
                    "windowsSdkVersion": "10.0.22000.0",
                    "compilerPath": "C:/mingw64/bin/gcc.exe",
                    "cStandard": "c17",
                    "cppStandard": "c++17",
                    "intelliSenseMode": "gcc-x64"
                },
                {
                    "name": "MinGW_CPP",
                    "includePath": [
                        "${workspaceFolder}/**"
                    ],
                    "defines": [
                        "_DEBUG",
                        "UNICODE",
                        "_UNICODE"
                    ],
                    "windowsSdkVersion": "10.0.22000.0",
                    "compilerPath": "C:/mingw64/bin/g++.exe",
                    "cStandard": "c17",
                    "cppStandard": "c++17",
                    "intelliSenseMode": "gcc-x64"
                }
            ],
            "version": 4
        }
    ```


3.3 配置构建任务（这是为了方便后边的gdb调试）
    Ctrl+Shift+P 调出命令面板，输入 tasks ，选择 Tasks:Configure Default Build Task
    选择 C/C++: g++.exe 生成活动文件，此时会生成 ***.exe文件
```
            {
                "tasks": [
                    {
                        "type": "cppbuild",
                        "label": "C/C++: g++.exe 生成活动文件",
                        "command": "C:/mingw64/bin/g++.exe",
                        "args": [
                            "-fdiagnostics-color=always",
                            "-g",
                            "${file}",
                            "-o",
                            "${fileDirname}\\${fileBasenameNoExtension}.exe"
                        ],
                        "options": {
                            "cwd": "C:/mingw64/bin"
                        },
                        "problemMatcher": [
                            "$gcc"
                        ],
                        "group": {
                            "kind": "build",
                            "isDefault": true
                        },
                        "detail": "调试器生成的任务。"
                    }
                ],
                "version": "2.0.0"
            }
```

3.4 配置调试设置
    选择 运行 - 添加配置
        选择 C++(GDB/LLDB)
            launch.json文件，若文件内容配置为空，点击右下角添加配置
```
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) 启动",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/test.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/mingw64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "将反汇编风格设置为 Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        }

    ]
}

```

4. 安装Git
    从官网下载太慢了， 推荐这个国内的下载站：https://registry.npmmirror.com/binary.html?path=git-for-windows/
