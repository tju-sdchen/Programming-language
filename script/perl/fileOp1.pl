#!/usr/bin/perl

# 1.读取import.txt将每一行放到@lines数组中：
open(DATA, "<import.txt") or die "Cann't be opened!";
@lines = <DATA>;
print @lines[0];
foreach $a (@lines){
  printf "$a";
}
close(DATA);

# 2. getc函数
# 从指定的FILEHANDLE返回单一的字符，如果没指定返回STDIN
# getc FILEHANDLE
# getc

open(DATA, "<import.txt") or die "Cann't be opened!";
$a = getc(DATA);
print "$a";
close (DATA);

# 3. read函数
# 用于从缓存区的文件句柄读取信息，读取二进制文件

#read FILEHANDLE, SCALAR, LENGTH, OFFSET
#read FILEHANDLE, SCALAR, LENGTH

#FILEHANDLE：文件句柄，用于存放一个文件唯一标识符。
#SCALAR：存贮结果，如果没有指定OFFSET，数据将放在SCALAR的开头。否则数据放在SCALAR中的OFFSET字节之后。
#LENGTH：读取的内容长度。
#OFFSET：偏移量。
#如果读取成功返回读取的字节数，如果在文件结尾返回 0，如果发生错误返回 undef。

# 4. print函数
#print FILEHANDLE LIST
#print LIST
#print
print "hello world!\n";

# 5. 文件拷贝
# 只读方式打开文件
open(DATA1, "<file1.txt");
# 打开新文件并写入
open(DATA2, ">file2.txt");
# 拷贝数据
while(<DATA1>)
{
   print DATA2 $_;
}
close( DATA1 );
close( DATA2 );

# 6. 文件重命名
rename ("/usr/runoob/test/file1.txt", "/usr/runoob/test/file2.txt" );
# 删除文件
unlink ("/usr/runoob/test/file1.txt");
# 指定文件位置
# tell 函数来获取文件的位置
tell FILEHANDLE
tell
# 通过使用seek函数来指定文件内的位置
seek FILEHANDLE, POSITION, WHENCE
#FILEHANDLE：文件句柄，用于存放一个文件唯一标识符
#POSITION：表示文件句柄(读写位置指针)要移动的字节数
#WHENCE：表示文件句柄(读写位置指针)开始移动时的起始位置，可以取的值为0、1、2；分别表示文件开头、当前位置和文件尾
# 从文件开头读取256个字节
seek DATA, 256, 0;

# 7. 文件信息（文件是否存在，是否可读写）
my $file = "./file.txt";
my (@description, $size);

if (-e $file)
{
    push @description, '是一个二进制文件' if (-B _);
    push @description, '是一个socket(套接字)' if (-S _);
    push @description, '是一个文本文件' if (-T _);
    push @description, '是一个特殊块文件' if (-b _);
    push @description, '是一个特殊字符文件' if (-c _);
    push @description, '是一个目录' if (-d _);
    push @description, '文件存在' if (-x _);
    push @description, (($size = -s _)) ? "$size 字节" : '空';
    print "$file 信息：", join(', ',@description),"\n";
}
# 特殊的文件句柄用于缓存文件信息(fstat、stat和lstat)。
