//
//  cppgraph.cpp
//  XcodeCProgrammer
//
//  Created by admindyn on 2017/2/28.
//  Copyright © 2017年 admindyn. All rights reserved.
//

#include "cppgraph.hpp"
void testTuBianLi()
{
   /*
    图的遍历 分为 深度优先搜索（根左右 前序遍历） 和 广度优先搜索
    这里没有涉及到 节点之间权的问题 
    
    接下来考虑 权的问题
    那么就需要用到最小生成树的问题
    
    最小生成树 算法 
    prim 普里姆算法
    首先需要点的集合  纳入到最小生成树的点的集合 A F
    边的集合 纳入到最小生成树的边的集合 A-F(1) F-B(2)
    待选边的集合
    A-B(6) A-F(1) A-E(5) 
    
    扩大
    F-E(9) F-B(2) F-C(8) F-D(4)
    
    扩大
    。。。
    
    克鲁斯卡尔 算法
    待选边集合
    A-F(1) F-B(2) D-E(2) B-C(3)
    F-D(4) A-E(5) A-B(6) C-D(7)
    F-C(8) F-E(9)
    已选编的集合
    待选边集合次小边 （选的时候考虑 有没有形成闭环 闭环 需要舍弃）
    待选集合次小边 出现没有和其他点相连
    
    A-F(1) F-B(2) D-E(2) B-C(3)
    已涉及点的集合
    A F B | D E
    
    
    
    */
}
void testTuLinJieJuZhen()
{
/*
 第一:图的存储结构 将图转换为数据 存储
 第二:存储 分为 有向图 无向图
 
 第三:图的存储结构 分为 邻接矩阵（用数组表达） 邻接表 十字链表（有向图 链表表达） 邻接多重表（无向图）
 第四:对于箭头 狐尾 箭头的起端  箭头的终端 为狐头  箭头 权值
 第五:两个城市之间有道路 道路之间的距离300 就说权值为300 权值是抽象的概念
 
 第六:无论什么存储方式 都需要存储顶点与狐
 第七: 存储顶点信息 顶点的表示方法 只需要存储顶点 顶点索引 顶点数据
 第八:存储狐 使用邻接矩阵
 第九:邻接矩阵 如何 表达 图
     根据两个顶点之间是否有联线就用0 1 表示
  有向图
   v1 v2 v3 v4
v1 0   1  1  1
v2 0   0  0  0
v3 0   0  0  1
v4 1   0  0  0
     
   无向图
        v1 v2 v3 v4
     v1 0   1  1  1
     v2 1   0  0  0
     v3 1   0  0  1
     v4 1   0  1  0
 邻接矩阵如何 转换为 代码语句
     
     int matrix[4][4]; //然后在相应的位置表达0或1 表达狐或者边
     邻接矩阵有了 
     那么 图 的结构体如何定义呢
     struct Node
     {
     顶点索引;
     顶点数据;
     }
     struct Map{
      顶点数组; //存储所有的顶点
      邻接矩阵; //存储的是边或者狐 即顶点之间的关系
     }
     */

}

void testLinJieBiao()
{
   /*
  第一：  邻接表 需要用到知识 先熟悉链式存储
    链式存储基于 链表 线性表篇
  第二：表达图 也需要记录 顶点和 狐
  第三: 顶点表示方法 
   只需要 顶点索引 出弧链表头指针 顶点数据
  第四: 狐的表示方法 
    狐头顶点索引 下一条狐指针 狐数据（狐的权值）
    
   例如狐 v1->v2  v1 记录出弧链表头指针 根据头指针 可以找到该狐 
    记录 狐头的顶点索引 v2 而此时v1就是狐尾
    总结：
    发现 只要有顶点的表示方法 和 狐的表示方法 就能够拿到一个顶点 而找到它的任意一条出弧 ，而找到出弧后就找到下一个相应的节点（顶点）
    理解：：
    记录v1 v2 v3 v4 的索引 0 1 2 3 并且都有狐指针next
    v1（0） v2（1） v3（2） v4（3）
    next    next    next   next
            next->null
    
    next->1 data next
    next->2 data next
    next->2 data next
    next->null
    
    
    逆邻接表 与 邻接表 （邻接表 记录 出弧链表头指针 邻接表 入狐链表头指针 ） 它们之间相对的
    
    数据结构表达
    
    struct Node
    {
    顶点索引;
    该顶点弧链表的头节点;(就与它的狐相连接 )
    顶点数据;
    }
    
    struct Arc{
    指向顶点的索引;
    指向下一条狐的指针;
    狐信息;
    }
    struct Map{
    顶点数组;
    }
    
    */
    
}
void testShiZiLianBiao()
{
/*
  十字链表 存储有向图 链式存储
 
 十字链表 存储顶点
 存储 
 顶点索引 顶点数据 以该顶点为狐尾的狐节点指针
 以该顶点为狐头的狐节点指针
 记录v1 顶点
 存储 狐
 狐尾顶点索引 狐头顶点索引 狐尾相同的下一条狐的指针
 狐头相同的下一条狐的指针 狐的数据
 
 struct Map {
  存储顶点数组;
 }
 
 struct Node
 {
    顶点索引;
    顶点数据;
 第一条入狐节点指针;
 第一条出弧节点指针;
 }
 struct Arc
 {
    狐尾顶点索引;
    狐头顶点索引;
    指向下一条狐头相同的狐的指针;
    指向下一条狐尾相同的狐的指针;
    狐信息;
 
 }
 
 */
}

void testLianJieDuoChongBiao()
{
    /*
     连接多重表 记录 无向图 采用的也是 链式存储
     
     因为是无向图 这里记录的是 顶点 和 边
     
     顶点的表示方法:
     顶点索引  连接该顶点的边 顶点数据
     
     边的表示方法:
     A顶点的索引 B顶点的索引  
     与A顶点相连接的下一条边的指针
     与B顶点相连接的下一条边的指针
     边数据
     
     如何用程序表达  结构体表达
     struct Map{
        顶点数组;
     }
     struct Node
     {
     
     顶点索引;
     顶点数据;
     第一条边的节点指针；
     
     }
     struct Edge
     {
     顶点A索引;
     顶点B索引;
     连接A的下一条边的指针;
     连接B的下一条边的指针;
     边信息;
     
     }
     */
}

/*
 c++数据结构 图
 数据结构学习顺序
 对类 栈 链表 树 图
 
 图 相对于 树来说 是一种 更为复杂的数据结构
 图是
 是由节点和她们之间联线的集合
 根据联线的不同分为 有向图 和 无向图（都是双向的）
 需要注意的概念：
 第一 ：有向图
 
 每一个节点 都叫做顶点
 顶点与顶点间的 联线 叫做狐
 联线 狐分 为狐头 狐尾
 出度 入度（联线 由顶点发出来 或 由其他顶点发出来  有了 出度数 与 入度数）
 
第二：无向图
总 每一个节点 也叫做顶点
 
而 顶点之间的连线 叫做 边
 
顶点和其他有链接的点 叫做 邻接点
 
任意点都是连通的图 叫做 连通图
 
完全图 边数 与 顶点数 关系 n(n-1)/2

生成树 边数 = n-1 顶点数-1
 
图的表示法 

图的遍历 （第一 数据量大 第二 考虑有向图 单向）
 
最小生成树 （最有价值的  多个城市之间建立高速公路）
 
图的应用 路径规划  工程规划  战略规划 

 

 
 

 
 
 
 */