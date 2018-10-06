# 我的第一个游戏--射击打怪游戏
## 简介：
在这个游戏中，玩家可以通过鼠标和键盘操控Player的方向和移动，并通过点击鼠标左键对怪物发起攻击，最终消灭怪物。
## 教程：
1、完成这个游戏的制作其实很简单，只要根据以下链接中的教程操作即可。

https://www.scirra.com/tutorials/37/beginners-guide-to-construct-2/page-1

2、作为construct 2 的初次使用者，可能会在此过程中遇到一些困惑，以下提供了一些可能出现的问题及解决方法。
(注：以下解决方法建立在上面教程的基础上)
#### (1)我想让自己选的背景图充满整个游戏界面，而不是重复出现,怎么办？
![image](http://a4.qpic.cn/psb?/V13KTFw64Y3DPr/EGiKb3BQc2s77wxapAzpTQj5CSjy8KVrsOT.IVz2fb8!/m/dDMBAAAAAAAAnull&bo=1wLQAtcC0AIDCSw!&rf=photolist&t=5)

在layer层中选中background，单击外面的区域，会在属性栏看到Layout Size(image2)，记住它的值，在下一次插入背景图片前将图片的规格改成与它的值一样就行(我直接放在PPT中修改，然后粘贴到constrct 2中)。

![image](http://a3.qpic.cn/psb?/V13KTFw64Y3DPr/6o4m9ark.cMtphxzg7agPJkMJCzjGRP3aMXfN5I8APk!/m/dFYAAAAAAAAAnull&bo=cwNlAnMDZQIDCSw!&rf=photolist&t=5)

#### (2)运行游戏后老是移动太麻烦了，我想让自己的视野占据整个界面较大的比例？
![image](http://a4.qpic.cn/psb?/V13KTFw64Y3DPr/YDh30fitTpdU7fkf1xty5Hl0Cm89BH4KjuaIsLgYKs0!/m/dFMBAAAAAAAAnull&bo=AAW3AgAFtwIDCSw!&rf=photolist&t=5)

游戏一开始显示的界面为虚线框内的内容，大约是总的界面的四分之一，如果我想一开始就看到二分之一或更多，只需要修改总界面即Layout Size 的大小，再将背景图的规格按上面的方法修改即可,必要时可再将sprite缩小，使界面看起来更宽阔。
![image](http://a4.qpic.cn/psb?/V13KTFw64Y3DPr/qzc69*aZ*s7VIvJeEermCEj8AmY73AZekB17ZH1qSiw!/m/dFMBAAAAAAAAnull&bo=AAW3AgAFtwIDCSw!&rf=photolist&t=5)

#### (3)子弹打起来不过瘾？
![image](http://m.qpic.cn/psb?/V13KTFw64Y3DPr/sSp50bPSNUAuAX4snFNxqr3t0rjTAzsEVLmPyWKcHQM!/b/dFMBAAAAAAAA&bo=wgddBMIHXQQDCSw!&rf=viewer_4)
在此区域重复上一行的action，即可一次发出多个子弹。

另外，用画笔自己绘制炫酷的激光也是一个不错的选择
![image](http://r.photo.store.qq.com/psb?/V13KTFw64Y3DPr/NF3L3bzz55DuZalYlFaOoHTPkC22hn4gkPLPtOiOVBs!/r/dFIBAAAAAAAA)


