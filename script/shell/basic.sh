#! /bin/bash

# 脚本语言是像剧本一样教计算机办某个事情的语言

# Shell
# 是一个C语言编写的程序，是用户使用Linux的桥梁，Shell既是一种命令语言，又是一种程序设计语言，
# Shell编程都是指shell脚本编程，不是指开发shell自身。

# Linux的shell种类众多，常见有：
# Bourne Shell(/usr/bin/sh或/bin/sh)
# Bourne Again Shell (/bin/bash) # Bash易用免费广泛使用，是大多数Linux系统默认的Shell
# C Shell, K Shell, Shell for Root

echo "hello world!"

# 运行方式
# 1. chmod +x ./test.sh; ./test.sh;
# 若不加./,Linux会默认去PATH中找，而其中只有/bin,/sbin,/usr/bin,/usr/sbin
# 2. 作为解释器参数，直接运行解释器，其参数就是shell脚本的文件名： /bin/sh test.sh

# source, sh, bash, ./执行脚本的区别
# 1、 source命令用法： source FileName
# 作用:在当前 bash 环境下读取并执行 FileName 中的命令。该 filename 文件可以无 "执行权限"。
# 注：该命令通常用命令 . 来替代。
# 2、 sh、bash的命令用法： sh FileName 或 bash FileName
# 作用:打开一个子 shell 来读取并执行 FileName 中命令。该 filename 文件可以无 "执行权限"。
# 注：运行一个shell脚本时会启动另一个命令解释器。
# 3、./的命令用法： ./FileName
# 作用: 打开一个子 shell 来读取并执行 FileName 中命令，该 filename 文件需要 "执行权限"。
# 注：运行一个 shell 脚本时会启动另一个命令解释器。

## 教程开始
# 1. Shell 变量
your_name="runoob.com"  #定义变量，变量名不加$(英文字母，数字和下划线，首个字符不以数字开头)
for file in `ls /etc`; do
#for file in $(ls /etc) # 语句给变量赋值
  echo "file"
done
