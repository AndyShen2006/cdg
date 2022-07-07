# C++ Data Generator

## Instructions:

### English:

### 简体中文：
这是一个使用C++编写的随机数据生成库，您可以使用该随机生成库生成图论算法等随机数据。

安装方法：

先确认您电脑上已安装CMake(不低于3.16.3)，GNU C++ Compiler 5.0及以上（或者其他支持C++11的编译器），Ninja, git

执行

```
git clone https://github.com/AndyShen2006/cdg.git
```

克隆该库到您电脑的任意位置。

然后依次执行一下命令以执行编译(以Linux为例,Windows基本类似)
```
cd cdg/
mkdir build/
cd build/
cmake ..
ninja
sudo ninja install
```


Copyright (C) 2022  Andy Shen

This program is free software: you can redistribute it 
and/or modify it under the terms of the GNU General Public License as 
published by the Free Software Foundation, either version 3 of the 
License, or (at your option) any later version.

This program is distributed in the hope that it will be 
useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
See the GNU General Public License for more details.

You should have received a copy of the GNU General 
Public License along with this program.  If not, see <https://www.gnu.
org/licenses/>.