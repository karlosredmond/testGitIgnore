#include "Semaphore.h"
#include <iostream>
#include <vector>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> sem){
  sem->Wait();
  std::cout << "Launched from task One\n";
  std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task One\n";
   std::cout << "Launched from task Oe\n";
 
  sem->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> sem){
  sem -> Wait();
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";
  std::cout << "Launched from Two\n";

  sem -> Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex(new Semaphore(10));
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,mutex);
  threadTwo=std::thread(taskOne,mutex);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
