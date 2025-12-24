# MicroWatch✨

![status](https://img.shields.io/badge/status-WIP-yellow?style=flat-square) ![language](https://img.shields.io/badge/language-C-blue?style=flat-square) ![platform](https://img.shields.io/badge/platform-ARM--Cortex--M-informational?style=flat-square) ![pcb](https://img.shields.io/badge/PCB-planned-lightgrey?style=flat-square) ![license](https://img.shields.io/badge/license-MIT-green?style=flat-square) ![todo](https://img.shields.io/badge/TODO-Open-brightgreen?style=flat-square)

📅 本教程创建于: 2025-12-24
👨‍💻 作者： CharlieChen, HNHKHNH
📮 联系方式： 725610365@qq.com

> 本项目隶属于组织[Awesome-Embedded-Learning-Studio](https://github.com/Awesome-Embedded-Learning-Studio)的文档教程

## 快速说明

> [software_codes](./software_codes)下放置着本项目的软件代码
> [hardware_asset](./hardware_asset) 放置着所有的硬件电路图和PCB文件等
> [documents](./documents) 是本项目的文档
> 如果本项目计划出教学项目, 则会还有[tutorial](./tutorial)文件夹
> 具体的细节，请到[具体的说明步骤🖱](./codes_and_assets/instractions.md)
> 您如果不知道从何开始，请到[从这里开始!🖱](./tutorial/README.md)查看！

## 🚀 这是什么？

一个面向资源受限嵌入式平台的智能手表原型工程。目标是在有限硬件上实现响应迅速、模块化清晰的时间/交互类功能与若干趣味应用（DinoGame / 计步 / 指南针）

------

## 🤖核心特性（已规划）

- [ ] 秒表 / 倒计时（计时器界面）
- [ ] 闹钟（可设置时间并触发蜂鸣器）
- [ ] Dino Game（离线小恐龙小游戏，适配小屏幕按键操作）
- [ ] 步态计步界面（步数统计 + 基本步频估算）
- [ ] 指南针界面（基于三轴陀螺/磁力计）
- [ ] 模块化驱动/服务/应用目录结构，方便替换芯片或更换通信接口

------

## 💻硬件清单

硬件清单处于正在评审中的环节，将会在[HNHKHNH (futureBASS)](https://github.com/HNHKHNH)做好评估后定下清单：

------

## 💻(预计)软件架构

按照功能需求清单，主要分为两个部分

- **Timer（apps/timer）**：秒表与倒计时，支持按键操作与长按复位。计时器必须在低功耗下能被 RTC 中断精确唤醒（若使用外置 RTC）。
- **Alarm（apps/alarm）**：提供时间设置、重复规则（每天/工作日/自定义）、蜂鸣器驱动接口与持久化（flash/EEPROM）。
- **DinoGame（apps/dino）**：横版小游戏，控制简单（左右跳跃），以低 CPU 负荷实现帧率控制与碰撞检测演示。
- **Pedometer（services/pedometer）**：基于加速度计的步态算法（轻量），输出步数与步频供 UI 显示。
- **Compass（services/compass）**：磁力计校准（软铁/硬铁）流程 + 指南针 UI（带平滑滤波）。

所有的软件代码将会放到`software_codes/`下，其中，更加详细的分层：

- **hal/** — 板级抽象层（引脚、外设时钟、电源控制）
- **drivers/** — 低层驱动（OLED 驱动、I2C/SPI、IMU、RTC、Buzzer）
- **libs/** — 通用库（图形库、字体、事件队列、时间基准）
- **services/** — 业务适配层（把驱动能力封装成“计步”、“指南针”、“闹钟”等接口）
- **apps/** — 应用层（timer、alarm、dino、pedometer、compass）
- **ui/** — 界面组件（窗口管理、输入处理、样式）
- **tools/** — 调试工具与脚本（看情况是不是要有）

------

## 💻项目的WIP

#### 硬件TODO

- 做如下硬件清单的候选:

- [ ] 主控芯片（需要调查，结合性能，需求和价格三方最优解）
- [ ] OLED（成本，分辨率，大小）
- [ ] 时钟芯片（专门的芯片）（Optional可选的，取决于最终方案选择RTC还是专门的芯片）
- [ ] 陀螺仪（带磁力计）（MPU6050，待评审，因为芯片有点老，需要考虑新方案）
- [ ] 拨轮按钮（注意，多大决定于PCB板的体积，最后考虑）
- [ ] 迷你蜂鸣器 / 音乐芯片（考虑 +调查下，看看体积足够小就考虑）

#### 软件TODO

- [ ] 确定好硬件方案后展开:
- [ ] OLED库的编写
  1. 直接应用组件库
  2. 组件库
  3. 图形库 
  4. OLED驱动（板件参数宏）器件层
  5. IIC驱动（引脚）/SPI等通信层
- [ ] 上述芯片的基本驱动到获取业务接口的桥接代码（从让这个芯片正确跑起来 到 让这个芯片发挥它的作用）
- [ ] 业务层代码迭代到第二次TODO完成

#### 本轮评估预计产出：

1. 调查上面的硬件清单，选择合适选型，交付一小份说明/报告，包含啥硬件，为什么选，有没有备选，淘宝链接或者购买链接等存放到仓库下的hardware_asset下
2. 在对下敲定这套硬件方案后，准备展开对硬件预采购，驱动编写和模块测试

------

## ☞License

MIT © `Charliechen114514`，`HNHKHNH`

------

## 📞联系 / Maintainer

如果你在看 README：欢迎提 PR / Issue。
维护者：`Charliechen114514`，`HNHKHNH`

## 🚀 快速演示！

TODO
