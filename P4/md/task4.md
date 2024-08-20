yolo8训练过程
=============

使用make sense对给定图片进行标注，得到标注文件。

![标注文件](标注文件.png)

新建data目录，对标记文件及原图片进行划分，分为test，train，valid

![文件分组](文件分组.png)

编写yaml文件

![yaml文件](yaml.png)

创建虚拟环境
	conda create -n y8 python=3.8
进入虚拟环境
![y8](y8.png)
安装软件包
![install pkg](软件包.png)
获取预训练模型下载地址前往github镜像下载
测试yolo运行情况
![run test](test.png)

开始训练
参数：
  轮数：100
  图片大小：640
  单轮投入数量：40
  设备：gpu0
![train](train.png)

训练结果
![end](结果.png)

模型验证
![val](val.png)
![val](val1.png)
![val](val2.png)