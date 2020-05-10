#!/usr/bin/perl

#Perl提供了三种文件句柄:STDIN,STDOUT,STDERR，分别代表标准输入、标准输出和标准出错输出

# Open函数
open(DATA, "<file.txt") or die "file.txt File can't be opened!, $!";
while(<DATA>){
  print "$_";
}
# > 或 w 表示写入
# < 或 r 表示只读
# +< 或 r+ 读写方式，不能删除内容
# +> 或 w+ 读写方式，能删除内容
# >> 或 a 追加数据
open(DATA,">>file.txt") || die "file.txt 文件无法打开, $!";
# +>> 或 a+ 读取要追加文件内容
open(DATA,"+>>file.txt") || die "file.txt 文件无法打开, $!";

# Sysopen函数
# 读写方式打开文件
sysopen(DATA, "file.txt", O_RDWR);
# 更新文件前清空文件
sysopen(DATA,"file.txt", O_RDWR|O_TRUNC);

#O_CREAT 来创建一个新的文件
#O_WRONLY 为只写模式， 
#O_RDONLY 为只读模式
#O_APPEND 追加文件
#O_TRUNC  将文件大小截为零
#O_EXCL   如果使用O_CREAT时文件存在，就返回错误信息，它可以测试文件是否存在
#O_NONBLOCK 非阻塞I/O使我们的操作要么成功，要么立即返回错误，不被阻塞

# Close函数
close(DATA) || die "无法关闭文件";

# 读写文件
print "runoob web?\n";
$name = <STDIN>;
print "Web: $name\n";

