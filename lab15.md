# 智能蛇实验报告

## 设计算法决定贪吃蛇走向
* 算法框架
```C
 // Hx,Hy: 头的位置
    // Fx,Fy：食物的位置
    function whereGoNext(Hx,Hy,Fx,Fy) {
    // 用数组movable[3]={“a”,”d”,”w”,”s”} 记录可走的方向
    // 用数组distance[3]={0,0,0,0} 记录离食物的距离
    // 分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置
    //     例如：假设输入”a” 则distance[0] = |Fx – (Hx-1)| + |Fy – Hy|
    //           如果 Hx-1，Hy 位置不是Blank，则 distance[0] = 9999
    // 选择distance中存最小距离的下标p，注意最小距离不能是9999
    // 返回 movable[p]
    }
```
* 智能蛇总框架

```C
输出字符矩阵
    WHILE not 游戏结束 DO
        wait(time)
        ch＝whereGoNext(Hx,Hy,Fx,Fy)
        CASE ch DO
        ‘A’:左前进一步，break 
        ‘D’:右前进一步，break    
        ‘W’:上前进一步，break    
        ‘S’:下前进一步，break    
        END CASE
        输出字符矩阵
    END WHILE
    输出 The game is over！ 
```
* 结合之前的贪吃蛇代码即可实现智能蛇