#include <stdio.h>
#include <stdlib.h>
// 1. 第一个c程序
/*
int main(){  // void main(){ return; }
  
  printf("hello,world!\n");
	system("pause");  //暂停函数，请按任意键继续
	return 0;
}
*/
// 2. 传入参数
int main(int argc, char *argv[]){

	printf("可执行程序名字%s,参数个数[%d],运行输出:[%s]\n",argv[0],argc,argv[1]);
	return 0;
}
// 使用./a.out hello,world!
// c语言所产生的代码运行速度与汇编语言编写的代码运行速度几乎一样，C99标准
// 使用c的实例：操作系统、语言编译器、汇编器、文本编辑器、打印机、网络驱动器、现代程序、数据库、语言解释器、实体工具
// gcc -E hello.c hello.i  //预编译文件
// gcc -S hello.i -o hello.s  //汇编代码
// gcc -c hello.s -o hello.o //生成目标文件
// gcc hello.o -o hello  //生成可执行文件
// 3. c程序主要包括：预处理器指令，函数，变量，语句&表达式，注释
// 类型为void *的指针代表对象的地址，而不是类型，如内存分配函数 void *malloc（size_t
// size);返回指向void的指针
// 4.c变量
int i, j, k;
char c, ch;
float f, salary;
double d;
// c中变量声明:1,需要建立存储空间的；2不需要建立存储空间的，通过使用extern关键字声明但不定义
extern int i; //声明，不是定义
int i; //声明，也是定义
//如果需要在一个源文件引用另一个源文件中定义的变量，只需在引用的文件中将变量加上extern关键字声明即可
//内存寻址由大到小，优先分配内存地址比较大的字节给先定义的变量
int main(){
  int a;
	int b;
	printf("a的地址是%p,b的地址是%p\n",&a,&b);
	return 0;
}
// 5.c的常量
#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

int main(){
  int area;
	area = WIDTH * LENGTH;
	printf("value of area :%d", area);
	printf("%c", NEWLINE);

	return 0;
}

int main(){
  const int LENGTH = 10;
	const int WIDTH = 5;
	const char NEWLINE = '\n';

	int area;
	area = WIDTH * LENGTH;
	printf("value of area :%d", area);
	printf("%c", NEWLINE);

	return 0;
}

// 6.c的存储类
// auto存储类是所有局部变量默认的存储类，auto只能修饰局部变量
int mount;
auto int month;
//register存储类用于定义存储在寄存器中而不是RAM中的局部变量，只用于需要快速访问的变量
register int miles;
//static存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁
void func(void){
  static int thingy = 5; //每次调用func，thingy值不会被重置
	thingy ++;
}
//extern存储类用于提供一个全局变量的引用，全局变量对所有程序文件都是可见的
#include <stdio.h>
int count ;
extern void write_extern();
int main(){
	   count = 5;
		 write_extern();
}
#include <stdio.h>
extern int count;
void write_extern(void){
	   printf("count is %d\n", count);
}// count is 5

// 6.c中的杂项运算符
#include <stdio.h>
int main(){
  int a = 4;
	short b;
	double c;
	int* ptr;				 
	/* sizeof 运算符实例 */
	printf("Line 1 - 变量 a 的大小 = %lu\n", sizeof(a) );
	printf("Line 2 - 变量 b 的大小 = %lu\n", sizeof(b) );
	printf("Line 3 - 变量 c 的大小 = %lu\n", sizeof(c) );							  
  /* & 和 * 运算符实例 */
	ptr = &a;    /* 'ptr' 现在包含 'a' 的地址 */
	printf("a 的值是 %d\n", a);
	printf("*ptr 是 %d\n", *ptr);
  /* 三元运算符实例 */
	a = 10;
	b = (a == 1) ? 20: 30;
	printf( "b 的值是 %d\n", b );
	b = (a == 10) ? 20: 30;
	printf( "b 的值是 %d\n", b );
}
// 7.c中的判断 非零和非空=True 零或null=False
// if-else 语句
int main(){
  int a = 10;
	if(a < 20){
		printf("a < 20\n");
	else{
	  printf("a > 20\n");
	}
	printf(a=%d\n, a);
	return 0;
}
// switch case
int main(){
  char grade = 'B';
	switch(grade){
	  case 'A':
			printf("good");
		  break;
		case 'B':
		case 'C';
		  printf("well");
	  default:
			printf("null");
	}
}
// ?：运算符
int main(){
  int num;
	printf("Input a number:");
	scanf("%d",&num);
	(num%2==0)? printf("even"): printf("odd");
}
// C循环
// while
int main(){
  int a = 10;
	while(a < 20){
	  printf("a:%d\n", a)
	  a++;
	}
  return 0;
}
// for
int main(){
  for(int a = 10; a < 20; a = a + 1)
		printf("%d\n",a);
  return 0;
}
// do .. while
int main(){
  int a = 10;
	do{
	 printf("a:%d",a);
	 a = a + 1;
	}while(a < 20);
	return 0;
}
// 2到100中的质数
int main(){
 int i,j;
 for(i=2;i<100;i++){
   for(j=2; j<(i/j);j++)
		 if(!(i%j)) break;
	 if(j>(i%j)) printf("%d is odd",i);
 }
}
// break语句，continue语句
// goto语句
int main(){
  int a = 10;
  LOOP:do{
    if(a == 15){
    	a = a + 1;
    	goto LOOP;
    }
    printf("a=%d\n",a);
    a++;
  }while(a < 20);
  return 0;
}

//无线循环
int main(){
  for( ; ; ){
  	printf("无线循环！\n");
  }
  return 0;
}
// 8.函数
// 传值调用，形参不会影响实参；引用调用，指针传递，对实参本身进行操作
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  return;
}

int a = 100;
int b = 200;
swap(&a, &b);
// 内部函数，只能被本文件中其他函数所调用，函数名和函数类型加static，又名静态函数
static int max(int a, int b);
// 外部函数，能被其他源文件调用，加关键词extern,默认为外部函数
extern int max(int a, int b);
// file1.c
#include <stdio.h>
static void delete_string(char str[],char ch);
int main()
{
    extern void enter(char str[]); // 对函数的声明
    extern void print(char str[]); // 对函数的声明
    char c,str[100];
    enter(str);
    scanf("%c",&c);
    delete_string(str,c);
    print(str);
    return 0;
}
static void delete_string(char str[],char ch)//内部函数
{
    int i,j;
    for(i=j=0;str[i]!='\0';i++)
    if(str[i]!=ch)
    str[j++]=str[i];
    str[j]='\0';
}
// file2.c
#include <stdio.h>
void enter(char str[100]){ // 定义外部函数 enter
    fgets(str, 100, stdin); // 向字符数组输入字符串
}
// file3.c
#include <stdio.h>
void print(char str[]){ // 定义外部函数 print
    printf("%s\n",str);
}

// 内联函数，用inline关键词修饰的函数，类内定义的函数被默认成内联函数，有函数结构，编译后，却不具备函数性质
// 内联扩展用来消除函数调用时的时间开销，通常用于频繁执行的函数
// 递归函数不能定义为内联函数；一般适合不存在while和switch结构且只有1~5条语句的小函数；只能先定义后使用，否则认定为普通函数
// 对内联函数不能进行异常的借口声明
inline void swap (int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

// main 函数的参数
int main(int argc, char const *argv[])
// 递推函数
int sum(int n){
	if(n==1){
		return 1;
	}
	return n+sum(n-1);
}
scanf("%d,%d,%d",&a,&b,&c); // 从键盘输入三个整数，用逗号分隔
//函数名和参数列表一起构成了函数签名。意味着可以出现参数列表不同但是函数名相同的函数. void print()和void print(int num)不同

// 9. C作用域规则
// 在函数或块内部的局部变量；在所有函数外部的全局变量；在形式参数的函数参数定义中
// 全局变量保存在内存的全局存储区中，占用静态的存储单元；
// 局部变量保存在栈中，只有在所在函数被调用时才动态地为变量分配存储单元。

// 局部变量需自行初始化；全局变量系统自动会初始化
int 0; char '\0'; float 0; double 0; pointer NULL

// 10. C数组
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
// 访问数组
int main (){
   int n[10]; /* n 是一个包含 10 个整数的数组 */
   int i,j;
   /* 初始化数组元素 */         
   for ( i = 0; i < 10; i++ ){
      n[i] = i + 100; /* 设置元素 i 为 i + 100 */
   }
   /* 输出数组中每个元素的值 */
   for (j = 0; j < 10; j++ ){
      printf("Element[%d] = %d\n", j, n[j] );
   }
   return 0;
}
// 多维数组
int a[3][4] = {  
 {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
 {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
 {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
};

int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
int main (){
   /* 一个带有 5 行 2 列的数组 */
   int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
   int i, j;
   /* 输出数组中每个元素的值 */
   for ( i = 0; i < 5; i++ ){
      for ( j = 0; j < 2; j++ ){
         printf("a[%d][%d] = %d\n", i,j, a[i][j] );
      }
   }
   return 0;
}

int i;
char names[6][50]={"马超","关平","赵云","张飞","关羽","刘备"};
for(i=0;i<6;i++)  {
  printf("悍将名称：%s\n",names[i]);
}

// 编译器寻址方式
&a[i][j]=&a[0][0]+i*sizeof(int)*n+j*sizeof(int); // 注意 n 为第二维的维数
// C传递数组给函数
void myFunction(int *param);
void myFunction(int param[10]);
void myFunction(int param[]);
// 二维数组传递函数
double * MatrixMultiple(double a[][2], double b[][3]);  // 这才是正确的 二维以上数组一定要规定一个最高维数
void print_a(int a[][5], int n, int m)；
void print_b(int (*a)[5], int n, int m)
void print_c(int *a, int n, int m)

// C从函数返回数组
//C语言不允许返回一个完整的数组作为函数的参数，但可以通过指定不带索引的数组名来返回一个指向数组的指针
int * myfunction();

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 要生成和返回随机数的函数 */
int * getRandom(){
  static int  r[10];
  int i;
  /* 设置随机种子 */
  srand( (unsigned)time( NULL ) );
  for ( i = 0; i < 10; ++i){
     r[i] = rand();
     printf( "r[%d] = %d\n", i, r[i]);
  }
  return r;
}
 
/* 要调用上面定义函数的主函数 */
int main (){
   /* 一个指向整数的指针 */
   int *p;
   int i;
   p = getRandom();
   for ( i = 0; i < 10; i++ ){
       printf( "*(p + %d) : %d\n", i, *(p + i));
   }
   return 0;
}
// 指向数组的指针(数组名是一个指向数组中第一个元素的常量指针)
double balance[50];
// balance是一个指向&balance[0]的指针，即数组balance的第一个元素的地址

// *(balance + 4)是访问balance[4]数据的合法方式
int main (){
   /* 带有 5 个元素的整型数组 */
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;
   int i;
   p = balance;
   /* 输出数组中每个元素的值 */
   printf( "使用指针的数组值\n");
   for ( i = 0; i < 5; i++ ){
       printf("*(p + %d) : %f\n",  i, *(p + i) );
   }
   printf( "使用 balance 作为地址的数组值\n");
   for ( i = 0; i < 5; i++ ){
       printf("*(balance + %d) : %。10lf\n",  i, *(balance + i) ); // 输出10位小数
   }
   return 0;
}
// 指针与数组的区别:指针是一个变量，存储的数据是地址，可以进行数值运算；数组名代表数组最开始的一个元素的地址
char *str = "Hello";
char arrgs[] = "Hello";
// 字符数组
char *p = (char*)&arrgs == char *p=arrgs;
char *p = (char*)(&(arrgs[0])) == &arrgs == arrgs;
// 字符串指针
char *p=(char*)&str != str; 
str == str[0] == 'H';
//结论 字符数组的首地址可用arrgs, &arrgs来表示并且他们相等, 但是指针&str和str不同
num = sizeof(a)/sizeof(a[0]);

// !!!注意： (a+i) 代表 a[0+i] == *(a+i)的地址
void minMax(int a[], int len, int *min, int *max) { // a[] == *a
    int i;
    *min = *max = a[0]; //假定最大值 最小值相等 为a[0]  
    for(i= 1; i < len, i++) {
        if( a[i] < *min) {
          *min = a[i];
        }
        if(a[i] > *max) {
          *max = a[i];
        }
    }
}

int a[] = {1, 2, 3, 4, 5, 7, 8, 9, 15, 18, 25, 33};
int min, max;
minMax(a, sizeof(a)/ sizeof(a[0]), &min , &max );
printf( "min = %d, max = %d \n",  min,  max);4

int *q = a; //允许
int a[10];
*(a+1) == a[1];
//对数组名取地址：&a，得到的应该是整个数组的地址。这时可以认为a是整个数组的变量名.
//对变量名进行取地址操作：&，会得到该变量的地址；
//操作：（&a+1）得到的是增大整个数组内存大小的地址：增大4*10。

// 11. enum枚举
enum DAY{
      MON=1, TUE, WED, THU, FRI, SAT, SUN //第一个成员默认值0，后续枚举成员值在前一个成员上加1.
};
enum DAY day;
int main(){
    // 遍历枚举元素
    for (day = MON; day <= SUN; day++) {
        printf("枚举元素：%d \n", day);
    }
}

int main(){
    enum color { red=1, green, blue };
    enum  color favorite_color;
    /* ask user to choose color */
    printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
    scanf("%d", &favorite_color);
    /* 输出结果 */
    switch (favorite_color){
    case red:
        printf("你喜欢的颜色是红色");
        break;
    case green:
        printf("你喜欢的颜色是绿色");
        break;
    case blue:
        printf("你喜欢的颜色是蓝色");
        break;
    default:
        printf("你没有选择你喜欢的颜色");
    }
    return 0;
}
int main(){
    enum day{
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } workday;
    int a = 1;
    enum day weekend;
    weekend = ( enum day ) a;  //类型转换
    //weekend = a; //错误
    printf("weekend:%d",weekend);
    return 0;
}// weekend:1

// 12. C指针
int main(){
  int var1;
  char var2[10];
  printf("var1 变量的地址： %p\n", &var1  );
  printf("var2 变量的地址： %p\n", &var2  );
   return 0;
}
//对应指针的值的类型都是一样的，都是一个代表内存地址的长的十六进制数。
int main (){
   int  var = 20;   /* 实际变量的声明 */
   int  *ip;        /* 指针变量的声明 */
   ip = &var;  /* 在指针变量中存储 var 的地址 */
   printf("Address of var variable: %p\n", &var  );
   /* 在指针变量中存储的地址 */
   printf("Address stored in ip variable: %p\n", ip );
   /* 使用指针访问值 */
   printf("Value of *ip variable: %d\n", *ip );
   return 0;
}
int  *ptr = NULL;
if(ptr)     /* 如果 p 非空，则完成 */
if(!ptr)    /* 如果 p 为空，则完成 */

//指针的算术运算
//指针的每一次递增，它其实会指向下一个元素的存储单元。
//指针的每一次递减，它都会指向前一个元素的存储单元。
//指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节。
const int MAX = 3;
int main (){
   int  var[] = {10, 100, 200};
   int  i, *ptr;
   /* 指针中的数组地址 */
   ptr = var;
   /* 指针中最后一个元素的地址 */
   ptr = &var[MAX-1];

   for ( i = 0; i < MAX; i++){
      printf("存储地址：var[%d] = %x\n", i, ptr );
      printf("存储值：var[%d] = %d\n", i, *ptr );
      /* 移动到下一个位置 */
      ptr++;
   }
   return 0;
}
if (ptr <= &var[MAX - 1]){
	printf("True!\n");
}

// 指针数组
int *ptr[MAX];
const int MAX = 3;
int main (){
   int  var[] = {10, 100, 200};
   int i, *ptr[MAX];
   for ( i = 0; i < MAX; i++){
      ptr[i] = &var[i]; /* 赋值为整数的地址 */
   }
   for ( i = 0; i < MAX; i++){
      printf("Value of var[%d] = %d\n", i, *ptr[i] );
   }
   return 0;
}

int  a[5]={ 1,2,3,4,5 };    //定义一个一维数组 a
int  (*prt)[5];      // 步长为 5 的数组指针，即 prt 指向的数组里有 5 个元素  
prt=&a;    // 把数组 a 的地址付给 prt，则 prt 为数组 a 的地址，*prt 表示数组 a 本身
prt[ 0 ];    //表示数组首元素的地址
*prt[ 0 ]；  //表示数组的首元素的值，即为数组 a 的 1
**prt;         //表示数组的首元素的值，即为数组 a 的 1
*prt[ 1 ] ;   //表示指向数组的下一行元素的首元素的值，但是a是一维数组，只有一行，所以指向的地址中的值不确定

// 指向指针的指针
//指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。
int main (){
   int  var;
   int  *ptr;
   int  **pptr;
   var = 3000;
   /* 获取 var 的地址 */
   ptr = &var;
   /* 使用运算符 & 获取 ptr 的地址 */
   pptr = &ptr;
   /* 使用 pptr 获取值 */
   printf("Value of var = %d\n", var );
   printf("Value available at *ptr = %d\n", *ptr );
   printf("Value available at **pptr = %d\n", **pptr);
   return 0;
}

// 传递指针给参数
void getSeconds(unsigned long *par);
int main (){
   unsigned long sec;
   getSeconds( &sec );
   /* 输出实际值 */
   printf("Number of seconds: %ld\n", sec );
   return 0;
}
void getSeconds(unsigned long *par)
{
   /* 获取当前的秒数 */
   *par = time( NULL );
   return;
}
//接受数组作为参数
/* 函数声明 */
double getAverage(int *arr, int size);
 
int main (){
   /* 带有 5 个元素的整型数组  */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
   /* 传递一个指向数组的指针作为参数 */
   avg = getAverage( balance, 5 ) ;
   /* 输出返回值  */
   printf("Average value is: %f\n", avg );
   return 0;
}

double getAverage(int *arr, int size){
  int    i, sum = 0;      
  double avg;          
  for (i = 0; i < size; ++i){
    sum += arr[i];
  }
  avg = (double)sum / size;
  return avg;
}

// 函数指针
int fun1(int,int);
int fun1(int a, int b){ 
    return a+b;
}
int main(){
    int (*pfun1)(int,int); 
    pfun1=fun1;//这里&fun1和fun1的值和类型都一样，用哪个无所谓 
    int a=(*pfun1)(5,7); //通过函数指针调用函数。
}
// *test --> *(&test) --> test --> &test 等价
// 指针函数(返回值为指针的函数)
char *strcat( char *dest, const char *src );​
char *strcpy( char *dest, const char *src );
​char *strchr( const char *s, int c );​
char *strstr( const char *src, const char *sub );

// 从函数返回指针
//C 不支持在调用函数时返回局部变量的地址，除非定义局部变量为 static 变量

//int *(*p(int))[3]; -- 可以先跳过, 不看这个类型, 过于复杂从 p 开始,先与 () 结合, 说明 p 是一个函数, 
//然后进入 () 里面, 与 int 结合, 说明函数有一个整型变量参数, 
//然后再与外面的 * 结合, 说明函数返回的是一个指针, 
//然后到最外面一层, 先与[]结合, 说明返回的指针指向的是一个数组, 
//然后再与 * 结合, 说明数组里的元素是指针, 
//然后再与 int 结合, 说明指针指向的内容是整型数据。
//所以 p 是一个参数为一个整数据且返回一个指向由整型指针变量组成的数组的指针变量的函数。

int board[8][8];    /* int 数组的数组 */ 
int ** ptr;         /* 指向 int 指针的指针 */
int * risks[10];    /* 具有 10 个元素的数组, 每个元素是一个指向 int 的指针 */
int (* rusks) [10];  /* 一个指针, 指向具有 10 个元素的 int 数组 */
int * oof[3][4];    /* 一个 3 x 4 的数组, 每个元素是一个指向 int 的指针 */ 
int (* uuf) [3][4]; /* 一个指针, 指向 3 X 4 的 int 数组 */
int (* uof[3]) [4]; /* 一个具有 3 个元素的数组, 每个元素是一个指向具有 4 个元素的int 数组的指针 */ 
// 野指针和悬空指针要赋NULL

// 13.函数指针与回调函数
typedef int (*fun_ptr)(int,int); // 声明一个指向同样参数、返回值的函数指针类型
int max(int x, int y){
    return x > y ? x : y;
}
int main(void){
    /* p 是函数指针 */
    int (* p)(int, int) = & max; // &可以省略
    int a, b, c, d;
    printf("请输入三个数字:");
    scanf("%d %d %d", & a, & b, & c);
    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c); 
    printf("最大的数字是: %d\n", d);
    return 0;
}
// 回调函数
// 函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。
// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void)){
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}
// 获取随机值
int getNextRandomValue(void){
    return rand();
}
int main(void){
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}
// size_t 类型在C语言标准库函数原型使用的很多，数值范围一般是要大于int和unsigned.
//但凡不涉及负值范围的表示size取值的，都可以用size_t；比如array[size_t]。
//size_t 在stddef.h头文件中定义。
//在其他常见的宏定义以及函数中常用到有：
// 1，sizeof运算符返回的结果是size_t类型；  2，void *malloc(size_t size)
// Definitions of common types
#ifdef _WIN64
    typedef unsigned __int64 size_t;
    typedef __int64          ptrdiff_t;
    typedef __int64          intptr_t;
#else
    typedef unsigned int     size_t;
    typedef int              ptrdiff_t;
    typedef int              intptr_t;
#endif

// 14.字符串
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};   //不加'\0'会烫烫烫
char greeting[] = "Hello";
strcpy(s1, s2);  //复制字符串 s2 到字符串 s1。
strcat(s1, s2);  //连接字符串 s2 到字符串 s1 的末尾。
strlen(s1);      //返回字符串 s1 的长度。
strcmp(s1, s2);  //如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
strchr(s1, ch);  //返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
strstr(s1, s2);  //返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。

char *str = "hello"; // 指针不能直接赋值给数组

// 15.结构体允许存储不同类型的数据项。结构体变量所占内存长度是其中最大字段大小的整数倍
struct Books{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book= {"C 语言", "RUNOOB", "编程语言", 123456};
 
int main(){
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);

    struct Books Book2;        /* 声明 Book2，类型为 Books */
      /* Book2 详述 */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
   printBook( Book2 );
}
void printBook( struct Books book )
{
   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}

// 指向结构的指针
void printBook( struct Books *book )
{
   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}
printBook( &Book2 );

// 位域把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。
struct bs{
    int a:8;
    int b:2;
    int c:6;
}data;  
// data 为 bs 变量，共占两个字节。其中位域 a 占 8 位，位域 b 占 2 位，位域 c 占 6 位。
struct bs{
    unsigned a:4;
    unsigned  :4;    /* 空域 */
    unsigned b:4;    /* 从下一单元开始存放 */
    unsigned c:4
} // a 占第一字节的 4 位，后 4 位填 0 表示不使用，b 从第二字节开始，占用 4 位，c 占用 4 位。

main(){
    struct bs{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    } bit,*pbit;
    bit.a=1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b=7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c=15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n",bit.a,bit.b,bit.c);    /* 以整型量格式输出三个域的内容 */
    pbit=&bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a=0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b&=3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c|=1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);    /* 用指针方式输出了这三个域的值 */
}
// 15. C共用体
//共用体占用的内存应足够存储共用体中最大的成员。节省内存，有两个很长的数据结构，不会同时使用
union Data{
   int i;
   float f;
   char  str[20];
};
 
int main( ){
   union Data data;        
   printf( "Memory size occupied by data : %d\n", sizeof(data));  // 20
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);  // 访问
   return 0;
}

// 16. 位域

// typedef 使用它为类型取新的名字
typedef unsigned char BYTE;
BYTE b1,b2;

typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;
Book book;

// typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
// typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
# define TRUE 1
# define FALSE 0

#define PTR_INT int *
PTR_INT p1, p2;        //p1、p2 类型不相同，宏展开后变为int *p1, p2;
typedef int * PTR_INT
PTR_INT p1, p2;        //p1、p2 类型相同，它们都是指向 int 类型的指针。
//回调函数
int *(*a[5])(int, char*);
// <==>
typedef int *(*pFun)(int, char*);
pFun a[5];

// 16. C输入&输出
// 标准文件  标准输入：stdin; 标准输出: stdout; 标准错误： stderr
// C语言的I/O通常使用printf()和scanf()

int main(){
   int c;
   printf( "Enter a value :");
   c = getchar( );          // int getchar(void)读取一个可用的字符
   printf( "\nYou entered: ");
   putchar( c );            // int putchar(int c)输出一个单一的字符
   printf( "\n");
   return 0;
}

int main(){
   char str[100];
   char c[100] ;
   printf( "Enter a value :");
   gets( str );   // char *gets(char *s) 从stdin读取一行到s所指的缓冲区，直到一个终止符或EOF
   fgets( c,100,stdin );
   printf( "\nYou entered: ");
   puts( str );  // 把字符串s和一个尾随的换行符写到stdout
   fputs( c,stdout );
   return 0;
}

int main( ) {
   char str[100];
   int i;
   printf( "Enter a value :");
   scanf("%s %d", str, &i);
   printf( "\nYou entered: %s %d ", str, i);
   printf("\n");
   return 0;
}

int i;
char c;
scanf("%d", &i);
while((c=getchar())==' ' || c=='\n');
c = getchar();
// 用正则表达式
int i;
char c;
scanf("%d%[^' '^'\n']", &i, &c);

printf("%20.15f\n",a/3); // 数据占20列，包括15位小数

// 17. C文件读写
#include <stdio.h>
// 写入文件
int main(){
   FILE *fp = NULL;
   fp = fopen("./test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fputc('s',fp);
   fclose(fp);
}
// 读取文件
int main(){
   FILE *fp = NULL;
   char buff[255];
   fp = fopen("./test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1: %s\n", buff );
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
}
int main(){   
    FILE *fp = NULL;
    fp = fopen("test.txt", "r+");  // 确保 test.txt 文件已创建 
    fprintf(fp, "This is testing for fprintf...\n");   
    // fseek 可以移动文件指针到指定位置读,或插入写:
    fseek(fp, 10, SEEK_SET);  // SEEK_SET文件头，SEEK_CUR当前位置, SEEK_END文件尾，10=offset 
    if (fputc(65,fp) == EOF) {
        printf("fputc fail");   
    }   
    fclose(fp);
}
// fopen_s更安全
FILE* fp=NULL;
fopen_s(&fp,"\\123.txt","w+");

// 18.预处理器  所有预编译命令都是井号 # 开头
#define MAX_ARRAY_LENGTH 20
#include "myheader.h"
#undef  FILE_SIZE
#ifdef  FILE_SIZE 42

#ifndef MESSAGE
  #define MESSAGE "You wish!"
#endif

#if
#else
#elif
#endif
#error
#pragma

// 预定义宏
__DATE__ __TIME__ __FILE__ __LINE__ __STDC__

#define  message_for(a, b)  \    //宏延续运算符
    printf(#a " and " #b ": We love you!\n")  // 字符串常量化运算符#

#define tokenpaster(n) printf ("token" #n " = %d", token##n) // 标记粘贴运算符##

#if !defined (MESSAGE)  // defined()运算符
   #define MESSAGE "You wish!"
#endif

int main(void){
   message_for(Carole, Debra);
   return 0;
}

// 参数化的宏
#define square(x) ((x) * (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))

// 18.文件头
// 只引用一次头文件
#ifndef HEADER_FILE
#define HEADER_FILE
#include <fstream>
#include <iostream>
#endif
// 有条件引用
#if SYSTEM_1
   # include "system_1.h"
#elif SYSTEM_2
   # include "system_2.h"
#elif SYSTEM_3
   ...
#endif

#define SYSTEM_H "system_1.h"
...
#include SYSTEM_H

// 强制类型转换
int sum = 17, count = 5;
double mean;
mean = (double) sum / count;
// 整数提升
int main(){
   int  i = 17;
   char c = 'c'; /* ascii 值是 99 */
   int sum;
   sum = i + c;
   printf("Value of sum : %d\n", sum );  // 116
}

// 20. 错误处理
//C 语言提供了 perror() 和 strerror() 函数来显示与 errno 相关的文本消息。
//perror() 函数显示您传给它的字符串，后跟一个冒号、一个空格和当前 errno 值的文本表示形式。
//strerror() 函数，返回一个指针，指针指向当前 errno 值的文本表示形式。
#include <stdio.h>
#include <errno.h>
#include <string.h>
 
extern int errno ;
int main (){
   FILE * pf;
   int errnum;
   pf = fopen ("unexist.txt", "rb");
   if (pf == NULL){
      errnum = errno;
      fprintf(stderr, "错误号: %d\n", errno);
      perror("通过 perror 输出错误");
      fprintf(stderr, "打开文件错误: %s\n", strerror( errnum ));
   }
   else{
      fclose (pf);
   }
   return 0;
}
// 被零除
main(){
   int dividend = 20;
   int divisor = 0;
   int quotient;
   if( divisor == 0){
      fprintf(stderr, "除数为 0 退出运行...\n");
      exit(-1);
   }
   quotient = dividend / divisor;
   fprintf(stderr, "quotient 变量的值为 : %d\n", quotient );
   exit(0);
}
// 程序退出状态
exit(EXIT_SUCCESS);  // EXIT_SUCCESS 0 ; EXIT_FAILURE -1

// C递归
// 数的阶乘
double factorial(unsigned int i){
   if(i <= 1){
      return 1;
   }
   return i * factorial(i - 1);
}
int  main(){
    int i = 15;
    printf("%d 的阶乘为 %f\n", i, factorial(i));
    return 0;
}
// 斐波那契数列
int fibonaci(int i){
   if(i == 0){
      return 0;
   }
   if(i == 1){
      return 1;
   }
   return fibonaci(i-1) + fibonaci(i-2);
}
 
int  main(){
    int i;
    for (i = 0; i < 10; i++){
       printf("%d\t\n", fibonaci(i));
    }
    return 0;
}
// 22. 可变参数
#include <stdio.h>
#include <stdarg.h>
double average(int num,...){
    va_list valist;
    double sum = 0.0;
    int i;
    /* 为 num 个参数初始化 valist */
    va_start(valist, num);
    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++){
       sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);
    return sum/num;
}
int main(){
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
   printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
}
// 23. 内存管理
void *calloc(int num, int size);
//在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。
//所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是0。
void free(void *address);
//该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
void *malloc(int num);
//在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
void *realloc(void *address, int newsize);
//该函数重新分配内存，把内存扩展到 newsize。
// 动态分配内存
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
   char name[100];
   char *description;
   strcpy(name, "Zara Ali");
   /* 动态分配内存 */
   description = (char *)malloc( 200 * sizeof(char) ); // calloc(200, sizeof(char));
   if( description == NULL ){
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else{
      strcpy( description, "Zara ali a DPS student in class 10th");
   }
   printf("Name = %s\n", name );
   printf("Description: %s\n", description );

    /* 假设您想要存储更大的描述信息 */
   description = (char *) realloc( description, 100 * sizeof(char) );
   if( description == NULL ){
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else{
      strcat( description, "She is in class 10th");
   }
   
   printf("Name = %s\n", name );
   printf("Description: %s\n", description );
   /* 使用 free() 函数释放内存 */
   free(description);
}
void * pvoid;  // 不能对void指针进行算法操作
pvoid++; //ANSI：错误
pvoid += 1; //ANSI：错误
// ANSI标准之所以这样认定，是因为它坚持：进行算法操作的指针必须是确定知道其指向数据类型大小的。
int *pint;
pint++; //ANSI：正确

typedef struct{
  int id;
  char name[0];
}stu_t;
stu_t *s = NULL;    //定义一个结构体指针
s = malloc(sizeof(*s) + 100);//sizeof(*s)获取的是4，但加上了100，4字节给id成员使用，100字节是属于name成员的
s->id = 1010;
strcpy(s->name,"hello");

// 24. 命令行参数
int main( int argc, char *argv[] )  {
   if( argc == 2 ){
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 ){
      printf("Too many arguments supplied.\n");
   }
   else{ // 若没有提供任何参数，argc为1, 否则传递一个参数，argc为2
      printf("One argument expected.\n");
   }
}

//25. 冒泡排序
#include <stdio.h>
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}