// 析构函数定义为 protected，则没法在栈上定义
// 因为栈变量的销毁在退出作用域的时候由编译器调用
// protected 会导致外部调用析构函数失败

class A
{
protected:
    ~A() {}

public:
    A() {}
    static A *create()
    {
        return new A();
    }
    void destory()
    {
        delete this;
    }
};

class B
{
protected:
	// void *operator new(size_t t) {return malloc(t);}    // 注意函数的第一个参数和返回值都是固定的
	void operator delete(void *ptr) {} // 重载了 new 就需要重载 delete
public:
    B() {}
    ~B(){}
};

int main(){
	A* a = new A();
	// delete a;
	a->destory();

	// A b = A();

	B c = B();
	// B* d = new B();
	return 0;
}