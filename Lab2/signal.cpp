#include "Semaphore.h"
#include <iostream>
#include <vector>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> task1, std::shared_ptr<Semaphore> task2){
  std::cout <<"I ";
  std::cout << "must ";
  task2-> Signal();
  task1-> Wait();
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  task2 -> Signal();
}
void taskTwo(std::shared_ptr<Semaphore> task1,std::shared_ptr<Semaphore> task2){
  task2 -> Wait();
  std::cout <<"This ";
  std::cout << "will ";
  task1->Signal();
  task2->Wait();
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> semA(new Semaphore);
  std::shared_ptr<Semaphore> semB(new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,semA,semB);
  threadTwo=std::thread(taskOne,semA,semB);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
