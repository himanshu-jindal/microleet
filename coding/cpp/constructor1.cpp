// Online C++ compiler to run C++ program online

// copy constructor is present default, but in some cases we need to define it, example is given here, comment the copy constructor method and see magic

#include <iostream>
class A{
  
  
  private:
  int* x;
  int* y;
  
  public:
  A(){}

  A(int x1, int y1){
      
      x = new int(x1);
      y = new int(y1);

  }
  void display(){
      std::cout<<"addresses" << x << " "<<y<< std::endl;
      std::cout<<"values" << *x << " "<<*y<< std::endl;
  }
  
  A(const A& obj){
     std::cout<< "in copy constructor";
     x = new int(*(obj.x));
     y = new int(*(obj.y));
    
  }
  
  void change(){
      *x = 3;
      *y = 4;
      
  }
    
};
int main() {
    // Write C++ code here
    std::cout << "Hello world!";

    A obj1(1,2);
    A obj2 = obj1;
    obj1.display();
    obj2.display();
    
    obj2.change();
    
    obj1.display();
    obj2.display();

    return 0;
}
