
���ⱳ��:
������Windowsϵͳ�ϱ༭�����ļ�, Ȼ�����������ʵ�ֱ�������д���.


��������:
VM Workstations:
VM work station:VMware? Workstation 10.0.7 build-2844087

��������ϵͳ��
Windows 10 ��ͥ���İ�

centosϵͳ:
```
[test@localhost ~]$ cat /proc/version 
Linux version 3.10.0-1160.el7.x86_64 (mockbuild@kbuilder.bsys.centos.org) (gcc version 4.8.5 20150623 (Red Hat 4.8.5-44) (GCC) ) #1 SMP Mon Oct 19 16:18:59 UTC 2020
```
#case 1 �����ļ�����
##Windowsϵͳ
����һ�����ļ���C:\Centos7_64_Study_SharedFolder
![](./assets/�ļ�����1.png)

##VM WorkStations
����������Ĺ����ļ�Ŀ¼���ļ���
![](./assets/�ļ�����2.png)

##Centos7
```
[test@localhost ~]$ ls -l /mnt/
������ 0
[test@localhost ~]$ mkdir /mnt/hgfs
mkdir: �޷�����Ŀ¼"/mnt/hgfs": Ȩ�޲���
[test@localhost ~]$ su
���룺
[root@localhost test]# mkdir /mnt/hgfs
[root@localhost ~]# vmhgfs-fuse .host:/ /mnt/hgfs/ -o nonempty -o allow_other
[root@localhost ~]# mount | grep "hgfs"
vmhgfs-fuse on /mnt/hgfs type fuse.vmhgfs-fuse (rw,nosuid,nodev,relatime,user_id=0,group_id=0,allow_other)      //�鿴���ص����, Ŀǰ��ʾ�����Ѿ��ɹ�
[root@localhost ~]# ls -l /mnt/hgfs/
������ 4
drwxrwxrwx. 1 root root 4096 11�� 11 11:45 Centos7_64_Study_SharedFolder
[root@localhost ~]# 

```

#case2 ȡ�������ļ�����
```
[root@localhost ~]# 
[root@localhost ~]# umount /mnt/hgfs/       //����������һ����,����취������ĵ��Ľڵ�һС��
umount: /mnt/hgfs��Ŀ��æ��
        (��Щ�����ͨ�� lsof(8) �� fuser(1) ����
         �ҵ��й�ʹ�ø��豸�Ľ��̵�������Ϣ)
[root@localhost ~]# 
[root@localhost ~]# kill -9 3920
��ɱ��
[root@localhost test]# [root@localhost ~]# 

[test@localhost ~]$ su 
���룺
[root@localhost test]# umount /mnt/hgfs     //�ٴγ���ж�ع��صĹ����ļ�

[root@localhost test]# mount | grep "hgfs"      //ȷ���ٴ�ж�سɹ�
[root@localhost test]# 
```

#case3 �鿴���صĹ����ļ�
```
[root@localhost ~]# mount | grep "hgfs"
vmhgfs-fuse on /mnt/hgfs type fuse.vmhgfs-fuse (rw,nosuid,nodev,relatime,user_id=0,group_id=0,allow_other)
[root@localhost ~]# 
```

#case4 ��֤�����Ƿ����Զ����� ���صĹ����ļ�
```
[test@localhost ~]$ ls -l /mnt/hgfs 
ls: �޷�����/mnt/hgfs: û���Ǹ��ļ���Ŀ¼
[test@localhost ~]$ su
���룺
[root@localhost test]# ls -l /mnt/hgfs 
ls: �޷�����/mnt/hgfs: û���Ǹ��ļ���Ŀ¼       //������������,û���Զ����ع��صĹ����ļ�
[root@localhost test]# 

[root@localhost test]# cat /etc/fstab       //�޸�fstab�ļ�

#
# /etc/fstab
# Created by anaconda on Sat Nov 11 01:31:40 2023
#
# Accessible filesystems, by reference, are maintained under '/dev/disk'
# See man pages fstab(5), findfs(8), mount(8) and/or blkid(8) for more info
#
/dev/mapper/centos-root /                       xfs     defaults        0 0
UUID=2ee5cdb1-7833-44f2-be33-a9621c7265ee /boot                   xfs     defaults        0 0
/dev/mapper/centos-swap swap                    swap    defaults        0 0
.host:/ /mnt/hgfs fuse.vmhgfs-fuse allow_other,defaults 0 0     //������һ�е�����
[root@localhost test]# mount -a         //ǰ�߹��ع���, ��ȡ��һ��, Ȼ���ٹ���
fuse: bad mount point `/mnt/hgfs': No such file or directory
[root@localhost test]# 

[root@localhost test]# umount /mnt/hgfs 
[root@localhost test]# mount -a
[root@localhost test]# mount | grep "hgfs"      //���سɹ�
vmhgfs-fuse on /mnt/hgfs type fuse.vmhgfs-fuse (rw,relatime,user_id=0,group_id=0,allow_other)
[root@localhost test]# 

//reboot ����һ���ٿ���
[test@localhost ~]$ ls -l /mnt/hgfs/        //�������
������ 4
drwxrwxrwx. 1 root root 4096 11�� 11 11:45 Centos7_64_Study_SharedFolder
[test@localhost ~]$ 


```

#case4 ��!
## umount: /mnt/hgfs��Ŀ��æ��
```
[root@localhost ~]# 
[root@localhost ~]# 
[root@localhost ~]# umount /mnt/hgfs/       //ȡ�����ص�ʱ�����Ŀ��æ������
umount: /mnt/hgfs��Ŀ��æ��
        (��Щ�����ͨ�� lsof(8) �� fuser(1) ����
         �ҵ��й�ʹ�ø��豸�Ľ��̵�������Ϣ)
[root@localhost ~]# lsof /mnt/hgfs/
lsof: WARNING: can't stat() fuse.gvfsd-fuse file system /run/user/1000/gvfs
      Output information may be incomplete.
COMMAND  PID USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
bash    3920 test  cwd    DIR   0,39     4096    1 /mnt/hgfs
[root@localhost ~]# 

//����취: ֱ�Ӹɵ�����̰߳�!, ��ʱû�ҵ���İ취
[root@localhost ~]# kill -9 3920
��ɱ��
[root@localhost test]# 

[root@localhost ~]# kill -9 3920
��ɱ��
[root@localhost test]# [root@localhost ~]# 

[test@localhost ~]$ su 
���룺
[root@localhost test]# umount /mnt/hgfs     //�ٴγ���ж�ع��صĹ����ļ�

[root@localhost test]# mount | grep "hgfs"      //ȷ���ٴ�ж�سɹ�
[root@localhost test]# 

```

##ls �޷����ʹ��ص��ļ�/ ����ʧ��bad mount point
```
[test@localhost mnt]$ ls -l

ls: �޷�����hgfs: û���Ǹ��ļ���Ŀ¼
������ 0
d????????? ? ? ? ?            ? hgfs
[test@localhost mnt]$ su
���룺
[root@localhost mnt]# rm -rf hgfs 
rm: �޷�ɾ��"hgfs": ��һ��Ŀ¼
[root@localhost mnt]# rm hgfs 
rm: �޷�ɾ��"hgfs": û���Ǹ��ļ���Ŀ¼
[root@localhost mnt]# 

[root@localhost mnt]# 
[root@localhost mnt]# vmhgfs-fuse .host:/Centos7_64_Study_SharedFolder /mnt/hgfs -o nonempty -o allow_other
fuse: bad mount point `/mnt/hgfs': No such file or directory
[root@localhost mnt]# 

//��Щ������Ϊ�Ѿ����ع���,����ȡ�������������¹��ؾ�����

```