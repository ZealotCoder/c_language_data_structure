# 通信方式选择

## HTTPS

**`git clone`** 和 **`git pull`** 无限制，**`git push`** 需要提供 credential，一般是你的 github（如果 remote repository 托管在 github 上的话）的用户名和密码

## SSH

因为需要在托管平台上设置 ssh public key，所以要求你必须是该 repository 的拥有者或者管理员。**`git push`** 时，无需输入用户名，如果在生成 ssh key 的时候设置了密码，则需要输入密码，否则不需要。

## 选择建议

1. 如果开发环境在 windows ，产品环境在 linux，建议在 windows 下使用 https，在 linux 下使用 ssh
   1. 除了 ssh 本身的限制，这个建议还考虑到其他两个因素：方便、安全。
   2. 如果 linux 下使用 https，安全性没问题，但为了方便，当然希望在访问 remote repository 时可以免密码。关于这一点，网上大多数的解决方案是将用户名和密码包含在远程地址中，然后使用 `git config --global credential.helper store` 将 credential 信息以明文方式存储在 `.git-credentials` 文件中。这样一来，安全性不能保证。所以建议在 linux 下使用 ssh 方式。
   3. ssh key 的部署略微有点麻烦，但是一旦部署好，能同时保证安全性和便捷性
   4. windows 下建议使用 https 方式。windows 下有 `git-credential-winstore` 和 `git-credential-manager-for-windows` 用以存储 credential，所以安全性和便捷性同样可以保证
2. 如果有多人共同维护产品，ssh 无疑是最好的选择
   1. 因为多人维护，所以项目部署至产品环境，无论产品环境是 windows 还是 linux，需要一个统一的密码（即使这个密码为空）。
   2. 如果使用 https 方式，必须以一个人的账号和密码作为 credential， 这样会有两个问题，一是不利于个人隐私的保护，二是如果此人出现人事变动，会带来不必要的麻烦。

## 如何确定仓库的通信方式

```
[test@localhost cpp_language]$ git remote -v
origin	https://gitee.com/xizipan/cpp_language.git (fetch)		//如此标明是HTTPS通信方式
origin	https://gitee.com/xizipan/cpp_language.git (push)
[test@localhost cpp_language]$ 
```



# 远程仓库通信方式更换

```
[test@localhost cpp_language]$ git remote -v	//查看原有通信方式
origin	https://gitee.com/xizipan/cpp_language.git (fetch)
origin	https://gitee.com/xizipan/cpp_language.git (push)
[test@localhost cpp_language]$ ^C
[test@localhost cpp_language]$ git remote rm origin		//删除原有通信方式
[test@localhost cpp_language]$ git remote -v
[test@localhost cpp_language]$ git remote add origin git@gitee.com:xizipan/cpp_language.git					//添加新的ssh通信方式
[test@localhost cpp_language]$ git remote -v			//查看更换之后的仓库通信方式
origin	git@gitee.com:xizipan/cpp_language.git (fetch)
origin	git@gitee.com:xizipan/cpp_language.git (push)
[test@localhost cpp_language]$ 

```

# HTTP免密配置

## 全局免密

```
[test@localhost cpp_language]$ git remote add origin https://gitee.com/xizipan/cpp_language.git
[test@localhost cpp_language]$ git remote -v
origin	https://gitee.com/xizipan/cpp_language.git (fetch)
origin	https://gitee.com/xizipan/cpp_language.git (push)
[test@localhost cpp_language]$ git config -l
user.name=xizipan
user.email=ed6102324@gmail.com
credential.helper=store
push.default=simple
core.repositoryformatversion=0
core.filemode=false
core.bare=false
core.logallrefupdates=true
core.symlinks=false
core.ignorecase=true
remote.origin.url=https://gitee.com/xizipan/cpp_language.git
remote.origin.fetch=+refs/heads/*:refs/remotes/origin/*
[test@localhost cpp_language]$ git config --global credential.helper store

//配置credential.helper store之后会生成~/.gitconfig记录用户的账号名称和邮箱地址
[test@localhost cpp_language]$ cat ~/.gitconfig 	
[user]
	name = xizipan
	email = ed6102324@gmail.com
[credential]
	helper = store
[push]
	default = simple

//在经过一次提交push之后, 系统就会在~/.git-credentials 中记下用户名和密码, 可怕, 一不小心就被看到了!!!
[test@localhost cpp_language]$ cat ~/.git-credentials 	
https://username:password@gitee.com
[test@localhost cpp_language]$ 

```



## 单项目免密

编辑项目目录中.git 文件夹下的配置文件 config如下:

https://gitee.com/xizipan/cpp_language.git  -> https://username:password@gitee.com/xizipan/cpp_language.git

```
[test@localhost .git]$ cat config 
[core]
	repositoryformatversion = 0
	filemode = false
	bare = false
	logallrefupdates = true
	symlinks = false
	ignorecase = true
[branch "master"]
[remote "origin"]
	url = https://username:password@gitee.com/xizipan/cpp_language.git
	fetch = +refs/heads/*:refs/remotes/origin/*
[test@localhost .git]$
```



# SSH免密配置

## 全局用户(账号名称/邮箱)配置

```

[test@localhost Work_Code] git config --global user.name "xizipan" 
[test@localhost Work_Code] git config --global user.email "ed6102324@gmail.com"

[test@localhost Work_Code]$ git config -l
user.name=xizipan
user.email=ed6102324@gmail.com
credential.helper=store
push.default=simple
[test@localhost Work_Code]$
```

## 生成秘钥/公钥

```
[test@localhost test_repository]$ cd ~/.ssh
bash: cd: /home/test/.ssh: 没有那个文件或目录
[test@localhost test_repository]$ ssh-key
ssh-keygen   ssh-keyscan  
[test@localhost test_repository]$ ssh-key
ssh-keygen   ssh-keyscan  
[test@localhost test_repository]$ ssh-key
ssh-keygen   ssh-keyscan  
[test@localhost test_repository]$ ssh-keygen -t rsa -C "xizipan_VM10_Centos7_64_Study_Company"
Generating public/private rsa key pair.
Enter file in which to save the key (/home/test/.ssh/id_rsa): 
Created directory '/home/test/.ssh'.
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/test/.ssh/id_rsa.
Your public key has been saved in /home/test/.ssh/id_rsa.pub.
The key fingerprint is:
SHA256:***************** xizipan_VM10_Centos7_64_Study_Company
The key's randomart image is:
+---[RSA 2048]----+
|      .o+   .B   |
|       + o .*.=  |
|      o =   o*   |
|       o o .o.o  |
|        S o.oo . |
|         =oo.   =|
|   . .  +++. . +.|
|    + Eo++. + .  |
|   . ..=++   +.  |
+----[SHA256]-----+
[test@localhost test_repository]$ cat ~/.ssh/id_rsa.pub 
ssh-rsa ****** xizipan_VM10_Centos7_64_Study_Company		//藏住了, 不可能给你看的, 看了也不怕, 我立马就换了
[test@localhost test_repository]$
```



## 配置Gitee

![](../assets/gitee公钥.png)

## 仓库初始化并推送到远端

```
[test@localhost Work_Code]$ mkdir test_repository
[test@localhost Work_Code]$ cd test_repository/
[test@localhost test_repository]$ git init git remote add origin
usage: git init [-q | --quiet] [--bare] [--template=<template-directory>] [--shared[=<permissions>]] [directory]
[test@localhost test_repository]$ git init
初始化空的 Git 版本库于 /mnt/hgfs/Centos7_64_Study_SharedFolder/Work_Code/test_repository/.git/
[test@localhost test_repository]$ git remote add origin 
用法：git remote add [<选项>] <名称> <地址>

    -f, --fetch           抓取远程的分支
    --tags                抓取时导入所有的 tags 和关联对象
                          或不抓取任何 tag（--no-tags）
    -t, --track <分支>    跟踪的分支
    -m, --master <分支>   主线分支
    --mirror[=<push|fetch>]
                          把远程设置为用以推送或抓取的镜像

[test@localhost test_repository]$ git remote add origin git@gitee.com:xizipan/test_repository.git

[test@localhost Work_Note]$ cd ../../test_repository/
[test@localhost test_repository]$ git status
# 位于分支 master
#
# 初始提交
#
无文件要提交（创建/拷贝文件并使用 "git add" 建立跟踪）
[test@localhost test_repository]$ git add -A
[test@localhost test_repository]$ git commit -m "init commit"
# 位于分支 master
#
# 初始提交
#
无文件要提交（创建/拷贝文件并使用 "git add" 建立跟踪）
[test@localhost test_repository]$ git push
fatal: 当前分支 master 没有对应的上游分支。
为推送当前分支并建立与远程上游的跟踪，使用

    git push --set-upstream origin master

[test@localhost test_repository]$ git push --set-upstream origin master	

ssh: connect to host gitee.com port 22: Connection refused
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
//这就尴尬了, 本地初始化的一个仓库, 最后提交的时候GG了, 先去填坑吧 ,请先移步坑2 部分

//更新1:  Unit ssh.service could not be found.(未解决)
//更新2: 重启ssh 服务, 远端仓库和本地仓库关联然后再push(未解决)
[test@localhost test_repository]$ 
[test@localhost test_repository]$ su
密码：
[root@localhost test_repository]# sudo serv
servertool  service     
[root@localhost test_repository]# sudo service ssh status
Redirecting to /bin/systemctl status ssh.service
Unit ssh.service could not be found.
[root@localhost test_repository]# 


//现在去别的仓库试一下ssh的免密推送(GG,失败了)
[test@localhost Work_Code]$ rm -rf cpp_language/
[test@localhost Work_Code]$ ls -l
总用量 4
drwxrwxrwx. 1 root root 4096 11月 11 14:25 c_language_data_structure
[test@localhost Work_Code]$ git clone https://gitee.com/xizipan/cpp_language.git cpp_language		//新鲜克隆的仓库
正克隆到 'cpp_language'...
remote: Enumerating objects: 19, done.
remote: Counting objects: 100% (19/19), done.
remote: Compressing objects: 100% (19/19), done.
remote: Total 19 (delta 6), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (19/19), done.
[test@localhost Work_Code]$ git status
fatal: Not a git repository (or any parent up to mount point /mnt/hgfs)
Stopping at filesystem boundary (GIT_DISCOVERY_ACROSS_FILESYSTEM not set).
[test@localhost Work_Code]$ cd cpp_language/
[test@localhost cpp_language]$ git status
# 位于分支 master
无文件要提交，干净的工作区
[test@localhost cpp_language]$ git checkout -b develop origin/
origin/develop   origin/HEAD      origin/master    
[test@localhost cpp_language]$ git checkout -b develop origin/
origin/develop   origin/HEAD      origin/master    
[test@localhost cpp_language]$ git checkout -b develop origin/develop 
分支 develop 设置为跟踪来自 origin 的远程分支 develop。
切换到一个新分支 'develop'
[test@localhost cpp_language]$ git status
# 位于分支 develop
无文件要提交，干净的工作区
[test@localhost cpp_language]$ ls -l
总用量 12
-rwxrwxrwx. 1 root root 9592 11月 11 16:54 LICENSE
-rwxrwxrwx. 1 root root  956 11月 11 16:54 README.en.md
-rwxrwxrwx. 1 root root 1317 11月 11 16:54 README.md
[test@localhost cpp_language]$ touch ssh_test.cpp
[test@localhost cpp_language]$ git status
# 位于分支 develop
# 未跟踪的文件:
#   （使用 "git add <file>..." 以包含要提交的内容）
#
#	ssh_test.cpp
提交为空，但是存在尚未跟踪的文件（使用 "git add" 建立跟踪）
[test@localhost cpp_language]$ git remote -v		//准备换通信方式了
origin	https://gitee.com/xizipan/cpp_language.git (fetch)
origin	https://gitee.com/xizipan/cpp_language.git (push)
[test@localhost cpp_language]$ ssh yipeizhi 
^C
[test@localhost cpp_language]$ git remote rm 
add            prune          remove         rename         set-branches   set-head       set-url        show           update 
[test@localhost cpp_language]$ git remote rm 
add            prune          remove         rename         set-branches   set-head       set-url        show           update 
[test@localhost cpp_language]$ git remote rm origin
[test@localhost cpp_language]$ git remote -v
[test@localhost cpp_language]$ git remote add origin git@gitee.com:xizipan/cpp_language.git
[test@localhost cpp_language]$ git remote -v		//通信方式换完了
origin	git@gitee.com:xizipan/cpp_language.git (fetch)
origin	git@gitee.com:xizipan/cpp_language.git (push)
[test@localhost cpp_language]$ ls -l ~/.ssh/		//秘钥公钥已经配置完成
总用量 8
-rw-------. 1 test test 1679 11月 11 23:40 id_rsa
-rw-r--r--. 1 test test  419 11月 11 23:40 id_rsa.pub
[test@localhost cpp_language]$ git status
# 位于分支 develop
# 未跟踪的文件:
#   （使用 "git add <file>..." 以包含要提交的内容）
#
#	ssh_test.cpp
提交为空，但是存在尚未跟踪的文件（使用 "git add" 建立跟踪）
[test@localhost cpp_language]$ git add -A
[test@localhost cpp_language]$ git commit -m "ssh push test"
[develop 5ad80c7] ssh push test
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 ssh_test.cpp
[test@localhost cpp_language]$ git push
fatal: 当前分支 develop 没有对应的上游分支。
为推送当前分支并建立与远程上游的跟踪，使用

    git push --set-upstream origin develop

[test@localhost cpp_language]$ git push --set-upstream origin develop		//这怎么还他么的不行啊!!!
ssh: connect to host gitee.com port 22: Connection refused
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
[test@localhost cpp_language]$ 

//还是怀疑是ssh服务的锅!!!,转到 坑2 去了
//ssh 不接这个锅, 这可咋整??? 坑2 也别转了
[test@localhost ~]$ service sshd restart
Redirecting to /bin/systemctl restart sshd.service
[test@localhost ~]$ su
密码：
[root@localhost test]# systemctl status sshd
● sshd.service - OpenSSH server daemon
   Loaded: loaded (/usr/lib/systemd/system/sshd.service; enabled; vendor preset: enabled)
   Active: active (running) since 日 2023-11-12 00:09:33 CST; 53min ago
     Docs: man:sshd(8)
           man:sshd_config(5)
 Main PID: 15908 (sshd)
    Tasks: 1
   CGroup: /system.slice/sshd.service
           └─15908 /usr/sbin/sshd -D

11月 12 00:09:33 localhost.localdomain systemd[1]: Starting OpenSSH server daemon...
11月 12 00:09:33 localhost.localdomain sshd[15908]: Server listening on 0.0.0.0 port 22.
11月 12 00:09:33 localhost.localdomain sshd[15908]: Server listening on :: port 22.
11月 12 00:09:33 localhost.localdomain systemd[1]: Started OpenSSH server daemon.
[root@localhost test]# 


```





# 坑1: 怎么把HTTPS那些泄密的内容(用户名/密码)去掉

坑2 还没有解决, 先在已创建的仓库测试消除https影响和ssh免密推送!

## 单项目

删除.git/config 中的账号密码

```
[test@localhost cpp_language]$ git remote -v
origin	https://username:password@gitee.com/xizipan/cpp_language.git (fetch)
origin	https://username:password@gitee.com/xizipan/cpp_language.git (push)
[test@localhost cpp_language]$ cd .git
[test@localhost .git]$ vi config 
[test@localhost .git]$ git remote -v
origin	https://gitee.com/xizipan/cpp_language.git (fetch)
origin	https://gitee.com/xizipan/cpp_language.git (push)
[test@localhost .git]$ 

```

## 全局

```
# 指导链接: https://blog.csdn.net/qq_29860591/article/details/116474775
# git config --system --unset credential.helper
# 除了system外，还有global、local等范围
# 使用 git config --list 命令这是展示配置属性，只要不存在credential.helper表示清除成功
[test@localhost ~]$ git config --global --unset credential.helper 	//先把全局的credential.helper store取消掉
[test@localhost ~]$ git config -l
user.name=xizipan
user.email=ed6102324@gmail.com
push.default=simple
[test@localhost ~]$ cat ~/.git
.gitconfig        .git-credentials  
[test@localhost ~]$ cat ~/.git
.gitconfig        .git-credentials  
[test@localhost ~]$ cat ~/.gitconfig 
[user]
	name = xizipan
	email = ed6102324@gmail.com
[credential]
[push]
	default = simple
[test@localhost ~]$ cat ~/.git-credentials 		//我草, 这里的怎么还在
https://username:password@gitee.com

//先去试一下 commit/push
[test@localhost ~]$ cd /mnt/hgfs/Centos7_64_Study_SharedFolder/Work_Code/cpp_language/
[test@localhost cpp_language]$ git status
# 位于分支 master
无文件要提交，干净的工作区
[test@localhost cpp_language]$ vi 
.git/         .gitee/       .gitignore    LICENSE       README.en.md  README.md     test.cpp      
[test@localhost cpp_language]$ vi test.cpp 
[test@localhost cpp_language]$ git status
# 位于分支 master
# 尚未暂存以备提交的变更：
#   （使用 "git add <file>..." 更新要提交的内容）
#   （使用 "git checkout -- <file>..." 丢弃工作区的改动）
#
#	修改：      test.cpp
#
修改尚未加入提交（使用 "git add" 和/或 "git commit -a"）
[test@localhost cpp_language]$ git add -A
[test@localhost cpp_language]$ git commit -m "clear credential.helper store"
[master 107f312] clear credential.helper store
 1 file changed, 2 insertions(+)
[test@localhost cpp_language]$ git push
Username for 'https://gitee.com': xizipan		//这里生效了, 需要 填写账号密码
Password for 'https://xizipan@gitee.com': 
Counting objects: 5, done.
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 290 bytes | 0 bytes/s, done.
Total 3 (delta 2), reused 0 (delta 0)
remote: Powered by GITEE.COM [GNK-6.4]
To https://gitee.com/xizipan/cpp_language.git
   19620b8..107f312  master -> master
[test@localhost cpp_language]$ cat ~/.gitconfig 
[user]
	name = xizipan
	email = ed6102324@gmail.com
[credential]
[push]
	default = simple
[test@localhost cpp_language]$ cat ~/.git-credentials 		//但是怎么这里还在啊, 这教程给的指导不太靠谱啊!!!
https://xizipan:pxy2023WORK@gitee.com
[test@localhost cpp_language]$ git config --system --unset credential.helper 
error: could not lock config file /etc/gitconfig: ????
[test@localhost cpp_language]$ rm ~/.git-credentials			//直接暴力删除!!!
[test@localhost cpp_language]$ cat ~/.git-credentials 
cat: /home/test/.git-credentials: 没有那个文件或目录
[test@localhost cpp_language]$ 

```



# 坑2: ssh: connect to host gitee.com port 22: Connection refused

```
//更新1: Unit ssh.service could not be found.
//猜测原因: ssh 服务没有开启!
//解决办法: 重启ssh 服务

[root@localhost test_repository]# sudo service ssh status
Redirecting to /bin/systemctl status ssh.service
Unit ssh.service could not be found.
[root@localhost test_repository]# ls -l
总用量 0

[test@localhost ~]$ rpm -qa | grep -E "openssh"
openssh-7.4p1-21.el7.x86_64
openssh-server-7.4p1-21.el7.x86_64
openssh-clients-7.4p1-21.el7.x86_64
[test@localhost ~]$ service sshd restart
Redirecting to /bin/systemctl restart sshd.service
[test@localhost ~]$ 

[root@localhost test_repository]# su test
[test@localhost test_repository]$ git push --set-upstream origin master
ssh: connect to host gitee.com port 22: Connection refused
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
[test@localhost test_repository]$ 

//目前还没搞定
[test@localhost Work_Code]$ sudo service ssh status
[sudo] test 的密码：
test 不在 sudoers 文件中。此事将被报告。
[test@localhost Work_Code]$ su
密码：
[root@localhost Work_Code]# sudo service ssh status
Redirecting to /bin/systemctl status ssh.service
Unit ssh.service could not be found.	//ssh服务也没开起来!!!
[root@localhost Work_Code]# 

//更新2: 重启ssh 服务, 远端仓库和本地仓库关联然后再push
//ssh服务重启之后, git init 之后就和远程仓库关联了, 但是push还是不太行, 这个稍等我验证完ssh push之后再填!!!
//应该不是坑, git本地初始化后, 应该是先在远端创建一个仓库, 然后将本地和远端关联, 最后才能将本地推送到远端!!!!
[test@localhost Work_Code]$ mkdir test_repository
[test@localhost Work_Code]$ cd test_repository/
[test@localhost test_repository]$ git init
初始化空的 Git 版本库于 /mnt/hgfs/Centos7_64_Study_SharedFolder/Work_Code/test_repository/.git/
[test@localhost test_repository]$ git status
# 位于分支 master
#
# 初始提交
#
无文件要提交（创建/拷贝文件并使用 "git add" 建立跟踪）
[test@localhost test_repository]$ git remote add origin git@gitee.com:xizipan/test_repository.git		//远端仓库此前已经创建
[test@localhost test_repository]$ git add -A
[test@localhost test_repository]$ git commit -m "push in ssh without passwd"
# 位于分支 master
#
# 初始提交
#
无文件要提交（创建/拷贝文件并使用 "git add" 建立跟踪）
[test@localhost test_repository]$ git log
fatal: bad default revision 'HEAD'
[test@localhost test_repository]$ git branch 
[test@localhost test_repository]$ git status
# 位于分支 master
#
# 初始提交
#
无文件要提交（创建/拷贝文件并使用 "git add" 建立跟踪）
[test@localhost test_repository]$ git checkout master
error: pathspec 'master' did not match any file(s) known to git.
[test@localhost test_repository]$ git push -u origin master
ssh: connect to host gitee.com port 22: Connection refused
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
[test@localhost test_repository]$ git push -u origin master
ssh: connect to host gitee.com port 22: Connection refused
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.

```



