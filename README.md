# SummerTTS-python

# 说明
- 本项目基于[SummerTTS](https://github.com/huakunyang/SummerTTS)，在summerTTS基础上封装成可python调用的python库。
- 本项目只对单人场景做了适配。
- 本项目目前只在ubuntu（amd64/arm64）上编译过，windows可能需要少量修改。

# 环境要求：
- 需要安装cmake等基本编译环境、swig等。
> sudo apt update && sudo apt upgrade
>
> sudo apt install cmake swig libasound-dev libportaudio2 portaudio19-dev python-numpy
>
> pip install scipy sounddevice

# 使用说明
- 将本项目的代码克隆到本地，最好是Ubuntu Linux 环境
- 从以下的百度网盘地址下载模型，放入本项目的model目录中：
  链接: https://pan.baidu.com/s/1rYhtznOYQH7m8g-xZ_2VVQ?pwd=2d5h 提取码: 2d5h
    
  模型文件放入后，models目录结构如下（python下没有做多人的适配）：    
  models/  
  ├── multi_speakers.bin  
  ├── single_speaker_mid.bin  
  ├── single_speaker_english.bin  
  ├── single_speaker_english_fast.bin  
  └── single_speaker_fast.bin  
  
- 进入Build 目录，执行以下命令：  
  cmake ..  
  make  
- 编译完成后，会在Build 目录中生成 _SummerTTS.so 和python文件夹
- 将 _SummerTTS.so 和 python 文件夹下的SummerTTS.py拷贝到根目录下的python文件夹，这两个文件应在同一级目录下。
- 进入到python目录下，运行下列命令，测试语音合成（TTS）：  
> python test.py   
- 如果运行时缺库安装对应的库即可，网上都有。
- 具体使用方法test.py已经给出，本项目只是实例化成类并编译为python库，如需在项目中使用只需将SummerTTS.py和_SummerTTS.so文件一起放到主程序所在目录即可。如果想要在C++中调用可以参照src中的SummerTTS.h和SummerTTS.cpp修改调用即可。

# 感谢
特别感谢SummerTTS的作者[huakunyang](https://github.com/huakunyang)，这是一个很有趣的作品。
