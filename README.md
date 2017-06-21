## runtime-Learning



**runtime** 是 iOS 编程中比较难的模块，想要深入学习 OC，那 **runtime** 是你必须要熟练掌握的东西，  

要想做出多牛逼酷炫的效果，就必须承受同等学习的代价；  
在「时间和知识 」有限内，总结的文章难免有「未全、不足 」的地方，还望各位好友指出，以提高文章质量。

 


## directory【目录】

>目录：  
>1. runtime 概念  
>2. runtime 消息机制  
>3. runtime 方法调用流程「消息机制」  
>4. runtime 运行时常见作用  
>5. runtime 常用开发应用场景「工作掌握」  
>1.runtime 交换方法  
>2.runtime 给分类动态添加属性  
>3.runtime 字典转模型（Runtime 考虑三种情况实现）  
>6. runtime 运行时其它作用「面试熟悉」  
>1.动态添加方法  
>2.实现NSCoding的自动归档和解档  
>3.runtime 下Class的各项操作  
>4.runtime 几个参数概念  
>7. 什么是 method swizzling（俗称黑魔法）  
>8. 最后一道面试题的注解  
>9. 期待 & 后续






## 期待

- 如果在阅读过程中遇到 error，希望你能 Issues 我，谢谢。

- 如果你想为【本文相关】分享点什么，也希望你能 Issues 我，我非常想为这篇文章增加更多实用的内容，谢谢。

- 对本文我会【不定时、持续更新、一些 学习心得与文章、实用才是硬道理】^_^.

- 如果你下载了，对你有帮助或是觉得写的还可以，不要忘记回来叫Star到我碗里来 嗷 ^_^.



![坐下来 品一杯白开水，写的小样在下面 ~](http://upload-images.jianshu.io/upload_images/2230763-5954375df964c0dd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



温馨提示：【真的不点进去阅读一下 ❓】
[**更多有关本文系统文件的属性和方法及常用功能代码案例，请移步这里**]()

[**→【iOS·UIKit & Foundation框架—Annotations & Category注解工具类 👀 **](https://github.com/CustomPBWaters/Framework-Annotations-Category)

[**→【iOS Apple官方译文框架源码注解】👀 **](https://github.com/CustomPBWaters/Apple-OfficialTranslation-SourceAnnotation) 


#### About me
***

【[博客](https://custompbwaters.github.io)】  【[简书](http://www.jianshu.com/u/fd745d76c816)】   【[掘金](https://juejin.im/post/5948b282da2f600067910186)】  【[公众号: 白开水ln](https://github.com/CustomPBWaters/Framework-Annotations-Category)】  【[译文 & 源码](https://github.com/CustomPBWaters/Apple-OfficialTranslation-SourceAnnotation)】   【[工具类](https://github.com/CustomPBWaters/Framework-Annotations-Category)】


【白开水ln】：(我) 也是对【所花费时间的一个总结】！

【白开水ln】：(我) 只是个【有思想的伐码猿🐒】加上【自己的学习总结☕️】写出来的文章 ！

【白开水ln】：(我) 得文章【对你有新思想 或是 习惯】，你的 「Star & Fork」 是对我最大的赞赏 ！


































