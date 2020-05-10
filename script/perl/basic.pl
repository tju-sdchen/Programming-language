#!/usr/bin/perl

#------------
# File permission 0755
print "hello world!\n";

#------------
# Single-line comment
=pod
This is multiline comment
=cut

#------------
# Here Document
$a = 10;
$var = <<"EOF";
This is a here doc instance for
how to use "".
such as: a = $a
EOF
print "$var\n";

#------------
# Escape character
$result = "菜鸟教程 \"runoob\"";
print "$result\n";
print "\$result\n";

#------------
# Perl identifier
# a~z, A~Z, 0~9, _, case-sensitive

# -----------
# Perl data type
# 1. scalar
$myfirst = 123; # number 123
$mysecond = "123"; # char 123
# 2. array
@arr = (1,2,3);
print "$arr[0]\n";
# also can define an array by "qw"
@arr = qw/google
taobao
...
runoob/;
print "$arr[-1]\n";

@var_10 = (1..10); # 1,2,3...10
$size = @array; # length
$max_index = $#array; # maximum index

# add and delete elements
@site = ("google", "runoob", "taobao");
$new_size = @site;
$new_size = push(@site, "baidu");  #tail
$new_size = unshift(@site, "weibo"); #head
$new_byte = pop(@site);
$new_byte = shift(@site);

# split array
@site = qw/google taobao runoob weibo qq facebook/;
@site2 = @site[3,4,5]; 
print "@site2, @site[3..5]\n";

# replacement
@nums = (1..20);
print "before @nums\n";
splice (@nums, 5, 5, 21..25); // array,source,offset,object
print "after @nums\n";

# string2array
$var_test = "runoob";
$var_string = "www-runoob-com";
$var_names = "google, taobao, runoob, weibo";

@test = split('', $var_test);
@string = split('-', $var_string);
@names = split(',', $var_names);
$str = "a b c d e f";
@array = split(' '.$str,3);a b cdef

# array2string
$string_1 = join('-', @string);
$names_1 = join(',', @names);

# array sort
@site = sort(@site);
$[ = 1; #default first index=0

foreach(@site) {
	print $_."\n";
}            # traverse the array

# merge array
@nums = (1,2,(3,4,5)); # (@odd, @even)

# list
$var = (5,4,3,2,1)[4] # 1
$var = (5,4,3,2,1)[1..3]


# 3. hash (out-of-ordered key/value sets)
$data{'google'} = 'google.com'; # 1
%h = ('a'=>1,'b'=>2); # 2
%data = (-a=>1,-b=>2); # 3
$val = $data{-a};
%data = ('google', 45, 'runoob', 30, 'taobao', 40); #4
print "$h{a},$data{google}\n";
print "@data{-taobao, -runoob}";

@names = keys %data;
@value = values %data;
$size = @names;

# add elements
$data{'facebook'}='facebook.com';

# delete elements
delete $data{'taobao'};

if (exists($data{'facebook'})){
  print "$data{'facebook'}\n";
}

#-----------
# numeric liberal
# 1. int
$x = 12345;
if(1217 + 116 == 1333){
  print "$x\n";
}
$var1 = 047; # octal
$var2 = 0x1f; # hex
# 2. float
# exponent range of -309 ~ +308
$value = 9.01e+21 + 0.01 -9.01e+21;
print("first value:",$value,"\n");
$value = 9.01e+21 - 9.01e+21 + 0.01;
print("second value:",$value,"\n");
# 3.string
=pod
$val='This is a instance by
using multiline string
to define a text';
print($var);
=cut
$str = "hello" . "world"; # string connect
print "$str\n";
$num1 = 5;
$num2 = 10;
$num = $num1 . $num2;
print "$num\n";
# special charter
print "file name".__FILE__."\n";
print "line number".__LINE__."\n";
print "package name".__PACKAGE__."\n";
# v string
$foo = v102.111.111;
print "$foo\n";

# variable context
@names = ('google', "runoob", 'taobao');
@copy = @names;
$size = @names;  # return the size of array
print(@copy, $size,"\n");

#---------------------
# condition statement
# if
$a = 10;
if ($a < 10){
  printf "$a\n";
}
# if ... else ...
$a = 10;
if ($a < 0){
  printf "$a\n";
}else{
  printf "$a+1\n"
}

# if ... elsif ... else
$a = 10;
if ($a == 20){
	printf "$a\n";
}elsif ($a == 30){
  printf "$a+1\n";
}else{
  printf "$a+2\n";
}

# unless (condition=False)
$a = 20;
unless($a < 20){
  printf " a < 20 is False\n";
}

# unless ... else ...
unless ($a == 20){
  printf "false";
}else{
  printf "True";
}

# unless ... elsif ... else
unless ($a == 30){
  printf "False";
}elsif ($a == 30){
  printf "True";
}else{
  printf "default";
}

# switch
use Switch;

switch(argument){
  case 1            { print "1\n"; next;}
	case "a"          { print "char"}
	case [1..10,42]   { print "in list"}
	case (\@array)    { print "in array"}
	case (\@array)    { print "数字在数组中" }
  case /\w+/        { print "正则匹配模式" }
  case qr/\w+/      { print "正则匹配模式" }
  case (\%hash)     { print "哈希" }
  case (\&sub)      { print "子进程" }
  else              { print "不匹配之前的条件" }
}

# condition ? a : b;
$name = "runoob";
$f = 10;
$status = ($f > 30)? "hot" : "cold";

#--------------------
# perl loop 
# while
$a = 10;
while ($a < 10) {
  printf "$a\n";
	$a = $a + 1;
}
# until (condition = False)
$a = 5;
until ($a > 10){
  printf "$a";
	$a = $a + 1
}
# for 
for ($a = 0; $a < 10; $a = $a + 1){
  print "$a\n";
}

# foreach
@list = (2, 12, 36, 42, 51);
foreach $a (@list){
  print "$a\n";
}
# do .. while
$a = 10;

do{
  printf "$a\n";
	$a = $a + 1;
}while ($a < 15);

# nested loop statement
$a = 0;
$b = 0;

while($a < 3){
  $b = 0;
	while($b < 3){
	  print "$a,$b\n";
		$b = $b + 1;
	}
	$a = $a + 1;
  print "$a";
}
# next skip to continue statement
$a = 10;
while ($a < 10){
  if($a == 15){
	  $a = $a + 1;
		next;
	}
	print "$a\n";
	$a = $a + 1;
}

# last skip out from loop
$a = 10;
while ($a < 20){
  if ($a == 15){
	  $a = $a + 1;
		last;
	}
	print "$a\n";
	$a = $a + 1;
}
# continue operate before condition statement
@list = (1,2,3,4,5);
foreach $a (@list){
  print "$a\n";
}continue{
  last if $a == 4;
}

# redo skip to start to operate again this iteration
$a = 0;
while($a < 10){
  if ($a == 5){
	  $a = $a + 1;
		redo;
	}
	print "$a\n"
}continue{
  $a = $a + 1;
}

# goto (LABEL, EXPR, $NAME)
$a = 10;
$str1 = "LO";
$str2 = "OP";

LOOP: do{
  if ($a == 15){
   $a = $a + 1;
	 goto $str1.$str2;
	 goto LOOP;
 }
 print "$a\n";
 $a = $a + 1;
}while($a < 20);

# infinite loop
for ( ; ; ){
  print "infinite loop.\n"
}

# operator
# 1. arithmetic: + - * / % **
# 2. comparison: == != <=>(-1,0,1) > < >= <=
#           lt gt le ge eq ne cmp(1,0,-1)   
$a = "abc";
$b = "xyz";
$c = $a cmp $b;
# 3. assignment: = += -= *= /= %= **=
# 4. bit: & | ^ ~ << >>
$a = 0011 1100
$b = 0000 1101
$a & $b
# 5. logic: and && or || not
# 6. quotation: q{} qq{} qx{}
$b = q{a = $a}
$b = qq{a = $a}
# 7. other: . x('-' x 3)=--- .. ++ -- ->

# time and date
time() # reture second counts from 1970-01-01
localtime() # local time zone
gmtime() # Greemwich mean time

@months = qw( 一月 二月 三月 四月 五月 六月 七月 八月 九月 十月 十一月 十二月 );
@days = qw(星期天 星期一 星期二 星期三 星期四 星期五 星期六);
($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime();
print "$mday $months[$mon] $days[$wday]\n";
print("%02d:%02d:%02d",$hour,$min,$sec);

$datestr = localtime();
$epoc = time();

use POSIX qw(strftime);
$datestring = strftime "%Y-%m-%d %H:%M:%S", localtime;
printf("时间日期 - $datestring\n");

# sub function
# function define
sub hello{
  print "hello, world!\n"
}
hello();
#传递参数用 @_
sub Average{
  $n = scalar(@_);
	$sum = 0;
	foreach $item (@_){
	  $sum += $item;
	}
	$average = $sum / $n;
}
Average(10,20,30); # 20

#传递列表
# 定义函数
sub PrintList{
   my @list = @_;
   print "列表为 : @list\n";
}
$a = 10;
@b = (1, 2, 3, 4);
# 列表参数
PrintList($a, @b); # 列表参数放在最后一个参数

#传递哈希
# 方法定义
sub PrintHash{
   my (%hash) = @_;
   foreach my $key ( keys %hash ){
      my $value = $hash{$key};
      print "$key : $value\n";
   }
}
%hash = ('name' => 'runoob', 'age' => 3);
 
# 传递哈希
PrintHash(%hash);

#子程序返回值
# 方法定义
sub add_a_b{
   # 不使用 return
   $_[0]+$_[1];  
 
   # 使用 return
   # return $_[0]+$_[1];  
}
print add_a_b(1, 2)

# 子程序的私有变量
sub somefunc {
   my $variable; # $variable 在方法 somefunc() 外不可见
   my ($another, @an_array, %a_hash); #  同时声明多个变量
}

# 全局变量
$string = "Hello, World!";

# 函数定义
sub PrintHello{
   # PrintHello 函数的私有变量
   my $string;
   $string = "Hello, Runoob!";
   print "函数内字符串：$string\n";
}
# 调用函数
PrintHello();
print "函数外字符串：$string\n";

# 变量的临时赋值
# 全局变量
$string = "Hello, World!";
 
sub PrintRunoob{
   # PrintHello 函数私有变量
   local $string;
   $string = "Hello, Runoob!";
   # 子程序调用的子程序
   PrintMe();
   print "PrintRunoob 函数内字符串值：$string\n";
}
sub PrintMe{
   print "PrintMe 函数内字符串值：$string\n";
}
 
sub PrintHello{
   print "PrintHello 函数内字符串值：$string\n";
}
 
# 函数调用
PrintRunoob();
PrintHello();
print "函数外部字符串值：$string\n";

#静态变量
use feature 'state';
 
sub PrintCount{
   state $count = 0; # 初始化变量
 
   print "counter 值为：$count\n";
   $count++;
}
 
for (1..5){
   PrintCount();
}

#子程序调用上下文
# 标量上下文
my $datestring = localtime( time );
print $datestring; 
print "\n";
# 列表上下文
($sec,$min,$hour,$mday,$mon, $year,$wday,$yday,$isdst) = localtime(time);
printf("%d-%d-%d %d:%d:%d",$year+1990,$mon+1,$mday,$hour,$min,$sec);
print "\n";

# perl 引用
$scalarref = \$foo;     # 标量变量引用
$arrayref  = \@ARGV;    # 列表的引用
$hashref   = \%ENV;     # 哈希的引用
$coderef   = \&handler; # 子过程引用
$globref   = \*foo;     # GLOB句柄引用
$aref= [ 1,"foo",undef,13 ];
my $aref = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
]
$href= { APR =>4, AUG =>8 };
$coderef = sub { print "Runoob!\n" };

#取消引用 $ @ %
$var = 10; 
# $r 引用 $var 标量
$r = \$var;
# 输出本地存储的 $r 的变量值
print "$var 为 : ", $$r, "\n";
@var = (1, 2, 3);
# $r 引用  @var 数组
$r = \@var;
# 输出本地存储的 $r 的变量值
print "@var 为: ",  @$r, "\n";
%var = ('key1' => 10, 'key2' => 20);
# $r 引用  %var 数组
$r = \%var;
# 输出本地存储的 $r 的变量值
print "\%var 为 : ", %$r, "\n";

# ref 确认引用类型
$var = 10;
$r = \$var;
print "r 的引用类型 : ", ref($r), "\n";
@var = (1, 2, 3);
$r = \@var;
print "r 的引用类型 : ", ref($r), "\n";
%var = ('key1' => 10, 'key2' => 20);
$r = \%var;
print "r 的引用类型 : ", ref($r), "\n";

# 循环引用
my $foo = 100;
$foo = \$foo;
print "Value of foo is:",$$foo,"\n";

# 引用函数
# 函数定义
sub PrintHash{
   my (%hash) = @_;
   foreach $item (%hash){
      print "元素 : $item\n";
   }
}
%hash = ('name' => 'runoob', 'age' => 3);
# 创建函数的引用
$cref = \&PrintHash;
# 使用引用调用函数
&$cref(%hash);
