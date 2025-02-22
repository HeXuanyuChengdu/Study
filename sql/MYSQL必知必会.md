# MYSQL必知必会

## 第一课 了解SQL

### 1.1数据库基础

现代软件几乎离不开数据库，但是对数据库具体概念并不是每个人都清楚。

有时在数据库方面的同一个术语会代表不同内容

#### 1.1.1数据库

数据库：以某种有组织的方式存储的数据集合

类似于一个文件柜，数据库就是这个柜子，对于柜子装什么内容、如何装内容柜子本身并不在意。

数据库管理系统——DBMS:数据库的管理软件，通过DBMS创建和管理数据库，常见的MySQL、Oracle

#### 1.1.2表

表：

- 一种结构化的文件，存储某种特定类型的数据。
- 存储在同一张表上的数据应该是同一种类型。
- 在一个数据库中，表名应保持唯一
- 模式：关于数据库和表的布局及特性的信息，包括：
	- 如何存储数据
	- 数据如何分解
	- 各部分信息如何命名
	- …..

#### 1.1.3 列和数据类型

表由列组成。

列（column）：

- 表中的一个字段，所有表都是由一个列或多个列组成。
- 应当正确的把数据分为多个列，根据需求确定分到何种程度
- 每个列都有固定的数据类型，数据类型限制了存储在每一列的数据的种类
- 由于不同的DBMS对数据类型的定义不同，导致了不同DBMS的SQL不兼容

#### 1.1.4 行(row)

表中的数据按照行存储。

行也称为记录，一条记录代表了一个具体的数据对象。

​                         行与列示意图

![数据表的行与列](示意图/数据表的行与列.png)



#### 1.1.5 主键

 对于一张表的每一个记录，都应该有一列（或多列）用来对该记录进行唯一标识， 这一列称为主键(primary key)。

- SQL语法没有强制规定创建一张表必须有主键，但是规范设计的表都必须考虑设计主键
- 任意两行都应该有不同的主键值，也就是作为主键的列中的值都是唯一的
- 每一行都必须有一个主键值，主键值不能为NULL
- 主键列中的值不允许修改或更新
- 主键值不能重用—-即使某行被删除，它的主键值也不能赋给新行。
- 如果多个列组合作为主键，那么单个列的值可以不唯一，但多个列的组合必须唯一

### 1.2 什么是SQL

SQL:结构化查询语言，是一种专门用于沟通数据库的语言

SQL相比其他计算机语言语法更加简洁内容少，因为SQL的设计目的就是为了完成一项任务——从数据库读写数据。



