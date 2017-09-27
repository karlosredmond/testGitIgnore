/*! 
  \\ Author: Karl Redmond
  \\ Date: 10th Oct 2017 
  \\ brief A Semaphore Implementation to show mutual exclusion, where only one thread can access a resource at any time, in my case I am demonstrating it with "cout"
  \									\
  \\ Uses C++11 features such as mutex and condition variables to implement Semaphore

*/
#include "Semaphore.h"
#include <iostream>
#include <vector>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> sem){
  sem->Wait();
  std::cout << "Launched from task One\n";
  sem->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> sem){
  sem -> Wait();
  std::cout << "Launched from Two\n";
  sem -> Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,mutex);
  threadTwo=std::thread(taskOne,mutex);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
