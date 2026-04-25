# Computing-Network-Assignment8

## 项目介绍

本项目是一个计算机网络课程的作业，包含三个网络相关的编程任务，主要涉及IP地址处理和数据包分片功能。

## 项目结构

```
Computing-Network-Assignment8/
├── Computing-Network-Assignment8/  # Task1：IP地址与网络掩码计算
│   ├── main.c
│   ├── Computing-Network-Assignment8.vcxproj
│   └── Computing-Network-Assignment8.vcxproj.filters
├── Task2/                          # Task2：IP地址分类
│   ├── main.c
│   ├── Task2.vcxproj
│   └── Task2.vcxproj.filters
├── Task3/                          # Task3：IP数据包分片
│   ├── main.cpp
│   ├── Task3.vcxproj
│   └── Task3.vcxproj.filters
├── Computing-Network-Assignment8.slnx
├── .gitattributes
└── .gitignore
```

## 任务描述

### Task1: IP地址与网络掩码计算

**功能**：实现IP地址和网络掩码的AND操作，判断一个IP是否在指定的网络中。

**核心函数**：
- `is_in_net(unsigned char* ip, unsigned char* netip, unsigned char* mask)`：判断IP是否在网络范围内
- `get_ip_info(uint32_t x)`：将32位整数IP转换为32位二进制字符串

**测试**：测试IP地址 `10.16.5.10` 是否在网络 `10.16.0.0/24` 中。

### Task2: IP地址分类

**功能**：根据IP地址的第一个字节判断IP地址的类别（A、B、C、D类）。

**核心函数**：
- `classwise(unsigned char* ip)`：返回IP地址的类别（A、B、C、D）
- `get_ip_info(uint32_t x)`：与Task1相同，将32位整数IP转换为32位二进制字符串

**测试**：测试B类地址 `172.16.0.1` 的分类是否正确。

### Task3: IP数据包分片

**功能**：实现IP数据包的分片处理，根据路径MTU进行分片。

**核心函数**：
- `fragmentPacket(int packetLength, const vector<int>& pathMTUs)`：根据路径MTU列表对数据包进行分片
- `fragmentOne(const Fragment& frag, int mtu)`：对单个数据包进行分片

**测试**：测试长度为10000字节的数据包在路径MTU为500、400、200时的分片情况。




## 注意事项

1. 在Task1和Task2中，`get_ip_info`函数将32位整数IP转换为32位二进制字符串，每个字符代表一个bit
2. Task3中，分片时考虑了20字节的IP头部长度
3. 所有任务都包含内存分配和释放，确保不会内存泄漏