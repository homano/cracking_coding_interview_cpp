//what is the meaning of name hiding

Let us explain through an example. In C++, when you have a class with an overloaded method, 
and you then extend and override that method, you must override all of the overloaded methods.
For example:
1 class FirstClass {
2 public:
3 virtual void MethodA (int);
4 virtual void MethodA (int, int);
5 };
6 void FirstClass::MethodA (int i) {
7 std::cout << “ONE!!\n”;
8 }
9 void FirstClass::MethodA (int i, int j) {
10 std::cout << “TWO!!\n”;
11 }
This is a simple class with two methods (or one overloaded method).
 If you want to override the one-parameter version, you can do the following:
1 class SecondClass : public FirstClass {
2 public:
3 void MethodA (int);
4 };
5 void SecondClass::MethodA (int i) {
6 std::cout << “THREE!!\n”;
7 }
8 void main () {
9 SecondClass a;
10 a.MethodA (1);
11 a.MethodA (1, 1);
12 }
However, the second call won’t work, since the two-parameter MethodA is not visible. 
Thatis name hiding.