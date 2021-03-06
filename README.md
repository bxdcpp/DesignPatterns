# 设计模式
## 设计模式六大原则
- 单一职责原则
 * 低耦合，高内聚，职责分明，代码思路清晰，便于维护
- 开闭原则（Open Close Principle）
    * 对扩展开放，对修改关闭是为了使程序的扩展性好，易于维护和升级。想要达到这样的效果，我们需要使用接口和抽象类，后面的具体设计中我们会提到这点
- 里氏代换原则（Liskov Substitution Principle）
	* LSP 是继承复用的基石，只有当派生类可以替换掉基类，且软件单位的功能不受到影响时，基类才能真正被复用，而派生类也能够在基类的基础上增加新的行为。
- 依赖倒转原则（Dependence Inversion Principle）
	* 这个原则是开闭原则的基础，具体内容：针对对接口编程，依赖于抽象而不依赖于具体。
- 接口隔离原则（Interface Segregation Principle）
	* 使用多个隔离的接口，比使用单个接口要好。它还有另外一个意思是：降低类之间的耦合度。由此可见，其实设计模式就是从大型软件架构出发、便于升级和维护的软件设计思想，它强调降低依赖，降低耦合。
	如何实现接口隔离呢？可以使用（适配器模式，外观模式，代理模式，中介模式）
- 迪米特法则，又称最少知道原则（Demeter Principle）
	* 最少知道原则是指：一个实体应当尽量少地与其他实体之间发生相互作用，使得系统功能模块相对独立。

- 合成复用原则（Composite Reuse Principle）（设计模式书籍没有这个原则）
	* 合成复用原则是指：尽量使用合成/聚合的方式，而不是使用继承。

### 模式特点
- 优化代码第一步：单一职责原则
- 让程序更稳定更灵活：开闭原则
- 构建扩展性更好的系统：里式替换原则
- 让项目拥有变化的能力：依赖倒置原则
- 系统有更高的灵活性：接口隔离原则
- 更好地扩展性：迪米特原则

## UML6大关系

  [参考博客一](https://www.runoob.com)
  [参考博客二](https://blog.csdn.net/mike_caoyong/article/details/42563867)
 
- 泛化(Generalization)
	* 【泛化关系】：是一种继承关系，表示一般与特殊的关系，它指定了子类如何特化父类的所有特征和行为。例如：老虎是动物的一种，即有老虎的特性也有动物的共性。
		【箭头指向】：带三角箭头的实线，箭头指向父类
		 ![Generalization UML](https://github.com/bxdcpp/DesignPatterns/blob/master/doc/Generalization.png  "Generalization UML")
		 
- 实现（Realization）
	* 【实现关系】：是一种类与接口的关系，表示类是接口所有特征和行为的实现.
       【箭头指向】：带三角箭头的虚线，箭头指向接口
	    ![Realization UML](https://github.com/bxdcpp/DesignPatterns/blob/master/doc/realization.png  "Realization UML")
- 关联（Association)
	* 关联关系】：是一种拥有的关系，它使一个类知道另一个类的属性和方法；如：老师与学生，丈夫与妻子关联可以是双向的，也可以是单向的。双向的关联可以有两个箭头或者没有箭头，单向的关联有一个箭头。
		【代码体现】：成员变量
		【箭头及指向】：带普通箭头的实心线，指向被拥有者
		![Association UML](https://github.com/bxdcpp/DesignPatterns/blob/master/doc/association.png  "Association UML")
- 聚合（Aggregation）
	* 【聚合关系】：是整体与部分的关系，且部分可以离开整体而单独存在。如车和轮胎是整体和部分的关系，轮胎离开车仍然可以存在。
		聚合关系是关联关系的一种，是强的关联关系；关联和聚合在语法上无法区分，必须考察具体的逻辑关系。
		 ![Aggregation UML](https://github.com/bxdcpp/DesignPatterns/blob/master/doc/aggregation.png  "Aggregation UML")
- 组合(Composition)
	*	【组合关系】：是整体与部分的关系，但部分不能离开整体而单独存在。如公司和部门是整体和部分的关系，没有公司就不存在部门。
			组合关系是关联关系的一种，是比聚合关系还要强的关系，它要求普通的聚合关系中代表整体的对象负责代表部分的对象的生命周期。
			【代码体现】：成员变量
			【箭头及指向】：带实心菱形的实线，菱形指向整体
			 ![Composition UML](https://github.com/bxdcpp/DesignPatterns/blob/master/doc/composition.png  "Composition UML")

- 依赖(Dependency)
	*  【依赖关系】：是一种使用的关系，即一个类的实现需要另一个类的协助，所以要尽量不使用双向的互相依赖.
		【代码表现】：局部变量、方法的参数或者对静态方法的调用
		【箭头及指向】：带箭头的虚线，指向被使用者
		 ![Dependency UML](https://github.com/bxdcpp/DesignPatterns/blob/master/doc/dependency.png  "Dependency UML")
### 各种关系的强弱顺序：
泛化 = 实现 > 组合 > 聚合 > 关联 > 依赖
