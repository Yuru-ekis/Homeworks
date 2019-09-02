# 探究 BOOST 电路升压原理
<center>张网<sup>1</sup></center>
<center>(1. 汕头大学，汕头 515063)</center>
BOOST 电路是一种 DC-DC 升压电路。    
<!-- BOOST 电路的基本原理是通过函数信号发生器发出信号控制并改变 MOSFET （金属氧化物半导体场效晶体管）的占空比进而 PWM 升压。  -->

![图1_1.jpg](https://i.loli.net/2019/09/01/x5PSDAhZrYRF2LI.jpg)

这是一个典型的 BOOST 电路图。其中，电感起着储存能量，释放能量的作用；电容起着储存电荷的作用；二极管起着单向导电的作用。MOSFET 起着控制电路通断与占空比的作用；电源的作用是提供能量。    
首先，当 MOSFET 导通时，因为二极管有着单向导电的特性，右边电容中的电荷无法通过左边的回路。电路类似下面这样：
![图像.png](https://i.loli.net/2019/09/01/xWwy9cigEI3rlHY.png)
这个时候，电源开始给电感充电，给电感储存能量。    
然后，当 MOSFET 断开时，由于电感的电流方向不会突变，所以此时流经电感的电流方向还是朝右。二极管导通，其等效电路图如下：
![图像 2.png](https://i.loli.net/2019/09/01/PrU89oR1VCfZjaz.png)
这个时候，电感与电源一起为电容充电，向负载供电。由于电感的能量是瞬间释放的，可以把电感原本储存的来自电源的能量释放出去，于是就可以达到很高的电压，实现   DC-DC 升压。
将 MOSFET 导通的时间记为 $t_{on}$，将 MOSFET 断开的时间记为 $t_{off}$。设 MOSFET 导通时，电感吸收的能量为 $EIt_{on}$

记电感两端的电压为 $U_0 - U_i$，释放的能量为 $(U_0 - U_i)It_{off}$
因为能量守恒，电感吸收的能量与释放的能量相等，所以有: $U_iIt_{on} = (U_0 - U_i)It_{off}$

设 $T = t_{off} + t_{on}$  为一个周期，可以得到 $U_0 = U_i × \frac{t_{on}+t_{off}}{t_{off}} = U_i × \frac{T}{t_{off}} = \frac{E × T}{T - t_{on}} = \frac{E}{1-d}$     
其中 $d = \frac{t_{on}}{T}$ ，定义为`占空比`。

所以，BOOST 升压电路的最终输出电压由`占空比`决定。我们可以通过函数信号发生器发生信号控制 MOSFET 通断来控制占空比。这种形式一般被称为 `PWM` (`脉冲宽度调制`)。
***
## 当开关导通时，用电感值、电感电压、导通时间表示 $\Delta i{}'_{L}$
![图像 3.png](https://i.loli.net/2019/09/02/Pcz9seNO8p3Z1BL.png)
首先，设 $i_L$ 达到顶峰的时刻为 $t_0$ 。则导通时间 $t_{on} = t_0 - 0$。    

根据所学知识，对于电感有 ${\mathcal  {E}}=-L{{\mathrm  {d}}i \over {\mathrm  {d}}t}$；
其中，${\displaystyle {\mathcal {E}}}$ 是电动势，${\displaystyle L}$ 是电感，${\displaystyle i}$ 是电流，${\displaystyle t}$ 是时间。

由此可知，利用积分的思想，可得
 $i_{t0} = i_0 + \frac{1}{L}\int_{0}^{t_0}U(E)dE$     
化简得 $\Delta i{}'_{L} = \frac{1}{L} \cdot U_i \cdot  t_{on}$

## 当开关断开时，用电感值、电感电压、导通时间表示 $\Delta i{}''_{L}$    
![Ai_- ECos- U. _ toff.png](https://i.loli.net/2019/09/02/iO7emt4z9d1ZXxq.png)

设 $i_L$ 达到最低点的时刻为 $t_1$，则断开时间 $t_{off} = t_1 - t_0$。利用积分的思想，可得
$i_{t1} = i_{t0} + \frac{1}{L}\int_{t_0}^{t_1}U(E)dE$。
化简得 $\Delta i{}''_{L} = \frac{1}{L}(U_i - U_0)\cdot t_{off}$

## 证明 $U_0 = \frac{U_i}{1-D}$
![图像 4.png](https://i.loli.net/2019/09/02/QdFuYJDGV34LKZn.png)

由能量守恒定律知，有 $\Delta i{}'_{L} = \Delta i{}''_{L}$
由此可知 $U_i \cdot t_{on} = (U_i - U_0) \cdot t_{off}$
又因为根据之前的定义，$T = t_{on} + t_{off}$;$d = \frac{t_{on}}{t}$

代入上式进行化简得 $U_0 = \frac{U_i}{1-d}$
***
参考文献：    

[1]周作辉,方益.集成双升Boost电路的充电器设计[J/OL].现代信息科技,2019(15)[2019-09-02].http://kns.cnki.net/kcms/detail/44.1736.TN.20190829.1534.002.html.




