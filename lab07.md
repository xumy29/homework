## 硬件编程–机器指令编程
   利用机器指令控制冯诺依曼计算机执行程序。
### 一、实验目的
理解冯·诺伊曼计算机的结构  
理解机器指令的构成  
理解机器指令执行周期  
用汇编编写简单程序  
### 二、实验/学习工具
简单 CPU 仿真工具 Pippin CPUSim ！  
网址 (http://www.science.smith.edu/~jcardell/Courses/CSC103/CPUsim/cpusim.html)  
正常人是用不了的，因为太老了......可以通过以下办法使用该软件(https://ks0508.github.io/SE-project/QA1/QA1)
(感谢某学委的帮助)
### 任务 1：简单程序 (Add 2 number)
(1)  
![image](http://m.qpic.cn/psb?/V12BUkXq4Y4X3I/76FDV3hS*9rAFMMGz06FK*FC.7UQBrmSw5dH9Q.8nN4!/b/dFIBAAAAAAAA&bo=4QNkAuEDZAIDByI!&rf=viewer_4)
以上通过PIPPIN汇编语言编写了一个简单程序，分别在W和X中储存了值。

(2) 各寄存器的作用

IR:指令寄存器，用于储存正在执行的一条指令；  
PC:程序寄存器，用于存放CPU当前执行到的指令的地址；
ACC:累加寄存器，为ALU提供一个工作区，暂时储存ALU运算结果。

(3) fetch-execute  周期（举例说明）

* LOD #3  

1.读取PC中的地址(0)，将memory中对应地址的指令(LOD #3)提取出来  
2.经过传输，指令LOD #3被储存在IR中  
3.IR将LOD指令传输给Decoder，解码后，Decoder把LOD指令传给ALU，并命令MUX把操作数3传递到ALU  
4.ALU进行计算  
5.计算后的结果存储到ACC  
6.指令执行后，PC的地址+2，指向下一条要执行的指令

* ADD W   

1.读取PC中的地址(8)，将memory中对应地址的指令(ADD W)提取出来  
2.经过传输，指令ADD W被储存在IR中  
3.IR将ADD指令传输给Decoder，解码后，Decoder把ADD指令传给ALU，ALU指示ACC把值传过来，Decoder再指示把内存里地址为W的值传过来，指示MUX接收内存传来的值，并将其传到ALU里  
4.ALU进行计算  
5.计算后的结果存储到ACC  
6.指令执行后，PC的地址+2，指向下一条要执行的指令




* “LOD #3” 与 “ADD W” 指令的执行在Fetch-execuate周期的不同：

1.后者利用了储存在ACC中的值    
2.前者在第三步中MUX直接把指令中带有的值3传给ALU，后者MUX需要进入内存中将W对应的值提取出来

（3）“Binary”形式
![image](http://m.qpic.cn/psb?/V12BUkXq4Y4X3I/aKT1x7QWTI2TmTaU*aXtE3SNMP5S*ptLd5wsyzQlcP0!/b/dDIBAAAAAAAA&bo=.QNhAvkDYQIDByI!&rf=viewer_4)

(4)二进制下看上面的程序

首先给出PIPPIN汇编语言的指令集
(https://ks0508.github.io/SE-project/QA1/PIPPIN_Guide.pdf)  
1.以此可以写出指令 “LOD #7” 的二进制形式：00010100 00000111  
2.解释 RAM 的地址:  指令地址以0开头，相邻两个指令地址的值相差为2；  内存地址以1开头，相邻两个内存地址的值相差为1.  
3.按累加器的位数，该机器CPU是8位的  
4.该程序对应的 C语言表达是：

> int a = 3;  
int b = 5;  
int c = a + 5;

### 任务2 简单循环

（1） 输入程序Program 2，运行并回答问题：
![image](http://a1.qpic.cn/psb?/V12BUkXq4Y4X3I/AP2ITLJKilhk2he1KO39d9oOJOyuILPwXHS9uf.irBU!/m/dDQBAAAAAAAAnull&bo=wANIAsADSAIDByI!&rf=photolist&t=5)

用一句话总结程序的功能:循环一个值，每次减1，到0为止  
写出对应的 c 语言程序
> int a = 5;  
while (a > 0) {  
    --a;  
}



（2） 修改该程序，用机器语言实现 10+9+8+..1 ，输出结果存放于内存 Y


1.写出 c 语言的计算过程
> int_8 X = 10;  
int_8 Y = 0;  
while (X > 0)  {  
    Y += X;  
    --X;  
}

2.写出机器语言的计算过程  
注：地址16的指令为HLT
![image](http://m.qpic.cn/psb?/V12BUkXq4Y4X3I/gfMIrM5w*lh6uxDwsXnDbrkLQCXs6dxhZKh16zyLgDI!/b/dFQBAAAAAAAA&bo=5ANlAuQDZQIDByI!&rf=viewer_4)
![image](http://m.qpic.cn/psb?/V12BUkXq4Y4X3I/j*kP.Jp2AwHftxh*R0x09a4RkuXPnfqyrVx9tAoT680!/b/dDQBAAAAAAAA&bo=5ANlAuQDZQIDByI!&rf=viewer_4)

3.用自己的语言，简单总结高级语言与机器语言的区别与联系:  
高级语言，它是在低级语言的基础上，采用接近于人类自然语言的单词和符号来表示一组低级语言程序，使编程变得更加简单，易学，且写出的程序可读性强;  
机器语言运行速度更快；  
计算机只能识别机器语言,所以高级语言必须经过编译器转化为机器语言后才可以被计算机识别。
