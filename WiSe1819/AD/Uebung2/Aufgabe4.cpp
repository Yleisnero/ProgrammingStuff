#include <iostream>
#include <stack>
#include <random>

int function(int, int);
int functionIt(int, int);

void simulate();

int main() {
    std::cout << functionIt(1, 3) << std::endl;
    std::cout << function(1,3) << std::endl;
    return 0;
}

int function(int n, int m){

    if(n == 0){
        return m + 1;
    }else if(m == 0 && n > 0){
        return function(n - 1, 1);
    }else{
        return function(n - 1, function(n, m - 1));
    }

}

int functionIt(int n, int m){
    std::stack<int> stack_n;
    std::stack<int> stack_m;
    stack_n.push(n);
    stack_m.push(m);
    //int counter = 0;

    while(!stack_n.empty()){
        //std::cout << counter++ << std::endl;
        if(stack_n.top() == 0){
            stack_n.pop();

            m = stack_m.top() + 1;
            stack_m.pop();
            stack_m.push(m);
        } else if(stack_m.top() == 0 && stack_n.top() > 0){
            n = stack_n.top() - 1;
            stack_n.pop();
            stack_n.push(n);

            stack_m.pop();
            stack_m.push(1); //m = 1; push(m)
        }else{
            n = stack_n.top();
            stack_n.pop();
            stack_n.push(n - 1);
            stack_n.push(n);

            m = stack_m.top() - 1;
            stack_m.pop();
            stack_m.push(m);
        }
    }
    return m;
}

void simulate(){
    int m;
    int n;
    for(int i = 0; i < 100; i++){
        m = rand() % 100 + 1;
        n = rand() % 100 + 1;
        std::cout << "n: " << n << std::endl;
        std::cout << "m: " << m << std::endl;
        std::cout << "Rekursiv: " << function(n, m) << std::endl;
        std::cout << "Iterativ: " << functionIt(n, m) << std::endl;
    }
}