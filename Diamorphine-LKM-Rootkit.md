## 安装

```text
git clone git://github.com/m0nad/Diamorphine.git
# 在Diamorphine目录下
make
sudo insmod diamorphine.ko

```

## 卸载

```text
# 使模块可见
kill -63 0     
rmmod diamorphine

```

## 使用

隐藏文件或目录

隐藏 `diamorphine.h` 中定义的以MAGIC_PREFIX开头的文件或目录

![](https://tcs-devops.aliyuncs.com/storage/112d9b89c20827ffad8b6d872b92a630bbba?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmQ5Yjg5YzIwODI3ZmZhZDhiNmQ4NzJiOTJhNjMwYmJiYSJ9.-RiWr5Tetq96rx44B74onPNGV9TSQy4yPz5ESwTPpME&download=1.jpg "")



### 隐藏进程

```text
# 发送信号到进程号即可切换该进程的可见性
kill -31 进程号 

```

可见->不可见 (44838 myloop)

![](https://tcs-devops.aliyuncs.com/storage/112dca25fc6daf85cddb8748b8abbb359e1f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmRjYTI1ZmM2ZGFmODVjZGRiODc0OGI4YWJiYjM1OWUxZiJ9.4HIJTupepQZ5UdcKMHzxPe-MxU31Xvl4xYsQM-Sl08A&download=%E9%9A%90%E8%97%8F%E8%BF%9B%E7%A8%8B.png "")

不可见->可见 (44838 myloop)

![](https://tcs-devops.aliyuncs.com/storage/112d3e99b672c4a2f2d64312b302b0b4d667?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmQzZTk5YjY3MmM0YTJmMmQ2NDMxMmIzMDJiMGI0ZDY2NyJ9.FOxMQ3ewUL6kb4DVAcntddkFpkUMcd78bMycBmXtbPY&download=%E9%9A%90%E8%97%8F%E8%BF%9B%E7%A8%8B2.png "")



### 隐藏模块自身

```text
# 发送信号到任意进程即可切换 diamorphine 模块可见性
kill -63 任意进程号 

```

![](https://tcs-devops.aliyuncs.com/storage/112d3b5c0589dcbdff1e11181e7508c86c26?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmQzYjVjMDU4OWRjYmRmZjFlMTExODFlNzUwOGM4NmMyNiJ9.Ih2-SyMBvKwkl9YOmDREuB_1e7jaTJakWKboAO7n1E4&download=%E9%9A%90%E8%97%8F%E6%A8%A1%E5%9D%97.png "")



### 提权

```text
# 发送信号到任意进程即可提权
# 在卸载diamorphine模块后,当前终端的root权限会保持
kill -64 任意进程号 

```

![](https://tcs-devops.aliyuncs.com/storage/112dfa7d192fa8b1cdbd842ae990280e4cbd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmRmYTdkMTkyZmE4YjFjZGJkODQyYWU5OTAyODBlNGNiZCJ9.64Xc_FL0h_PqCyVrhTyr-ZBvJ6phR0a1Ek1q-MTydlM&download=%E6%8F%90%E6%9D%83.png "")



## 代码分析

所有都在diamorphine.c 中

基于内核版本选择相应的方法，模块版本控制

hook了三个系统调用getdents、getdents64、kill

获取系统调用表、强制修改读写保护位的方法和之前隐藏文件目录中的处理方法基本完全相同



### 隐藏进程

find_task(pid)函数：通过for_each_process(current) 扫描进程列表查找进程

is_invisible函数：通过进程描述符task_struct中flag第28位判断当前进程是否可见。

其余由隐藏文件目录实现



### 隐藏文件目录：hacked_getdents、_getdents64

隐藏文件的方法和之前隐藏文件目录中的处理方法基本相同，都是对原始调用返回的缓冲区加工后再返回（处理掉想要隐藏的inode）

实现进程的隐藏通过

1、判断当前是否在/proc/

2、使用is_invisible()+simple_strtoul(dir->d_name, NULL, 10)   /proc/pid/

### 提权 give_root()

主要由以下逻辑实现

`newcreds=prepare_creds()`通过创建一个新的凭证结构体

更新凭证red的权限(将其uid、gid等置为0)

`commit_creds(newcreds)`更新当前进程的 cred

### 隐藏模块

隐藏：保存链表节点后删除

`module_previous = THIS_MODULE->list.prev`

`list_del(&THIS_MODULE->list)`

显示：`list_add(&THIS_MODULE->list, module_previous)`

### hook kill

通过hook kill依据信号id对功能进行统一调度



## 基于保存系统调用表的检测

可以成功检测并实现纠正

![](https://tcs-devops.aliyuncs.com/storage/112df48c345aa4c18a865a7bbca8dea7df5f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmRmNDhjMzQ1YWE0YzE4YTg2NWE3YmJjYThkZWE3ZGY1ZiJ9.YNA7PR2Viv7u1cWCzPNdx20AbbTs5MbeLHcaRm7rxb8&download=%E6%97%A7%E6%A3%80%E6%B5%8B.png "")



## 基于bpftrace的检测

[__https://github.com/haozhuoD/bpftrace-detect-syscalltable_hook/blob/main/bpfc1.c__](https://github.com/haozhuoD/bpftrace-detect-syscalltable_hook/blob/main/bpfc1.c)

bpftrace版本：v0.14.0-35-g6cdd (源码安装,支持循环

在DEGIN模块中，对系统调用表中的函数跳转地址进行地址范围检查

(syscalltable-0x1000000 ~ syscalltable+0x1000000)

```text
// 获取内核系统调用表地址
// kaddr()功能与kallsyms_lookup_name()相似
@sys_call_table = kaddr("sys_call_table");
$i = 0;
while ($i <= 335) { 
        // 循环检查
        $i++}

```

思路来源：打印系统调用表及、地址及其kysm(syscall[x])发现

hook前

![](https://tcs-devops.aliyuncs.com/storage/112d479540263bce5b673ebcadb9289000c2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmQ0Nzk1NDAyNjNiY2U1YjY3M2ViY2FkYjkyODkwMDBjMiJ9.rneLOOO8L5maUG0Nl3ulPUxeVzrRK0vKdwRoI71qhAU&download=image.png "")

hook后

![](https://tcs-devops.aliyuncs.com/storage/112dc0be29efd518a63f69d90701629b917e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmRjMGJlMjllZmQ1MThhNjNmNjlkOTA3MDE2MjliOTE3ZSJ9.hyI0VAjxmJOWT3zsqIXMt_VpEVJKX_qjT_SZkk5d264&download=image.png "")

发现表项62(kill)、78(getdents)、217(getdents64)地址不同可以被观测到,同时也据此得出加减0x1000000的地址范围,以此实现检测。

需要注意,系统调用表等内核符号的地址每次重启之后都是不同的

![](https://tcs-devops.aliyuncs.com/storage/112d39732c574955a9623a851359c8b846b0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmQzOTczMmM1NzQ5NTVhOTYyM2E4NTEzNTljOGI4NDZiMCJ9.D6WFRbrW-3pyNrq2na7tKzgiD_Kix3gdmhGBV2VYQgU&download=image.png "")



### 检测成功：

![](https://tcs-devops.aliyuncs.com/storage/112d3a5da08d655c707ac2e84599cdceccb9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9hcHBJZCI6IjVlNzQ4MmQ2MjE1MjJiZDVjN2Y5YjMzNSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTY0OTY2MDk4MiwiaWF0IjoxNjQ5MDU2MTgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzExMmQzYTVkYTA4ZDY1NWM3MDdhYzJlODQ1OTljZGNlY2NiOSJ9.gbn4ZTMS0R0q3L5gRzSNCUq_r2soowYRzAieiChZDiY&download=image.png "")



