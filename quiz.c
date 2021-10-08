#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function declaration
int generate();

int main(int argc, char *argv[]){

  //Variable declaration
  int ans, qn, score, timer, x, y, n;
  char op[] = "+-x/";
  timer = time(NULL);

  //Ask questions
  score = 0;
  for (qn = 1; qn <= 20; qn++){

    x = generate(time(NULL)*qn, 13);
    y = generate(time(NULL)*x, 12);
    n = generate(time(NULL)*y, 4);

    //Ensure questions can be solved
    y = y+1;
    if (n == 3){
      x = x*y;
    }

    printf("%d) What is %d %c %d?\n", qn, x, op[n], y);
    printf("Answer: ");

    //Get user input
    scanf("%d", &ans);
    if (n == 0 && ans != x+y){
      printf("That is wrong!\n\n");
    }else if (n == 1 && ans != x-y){
      printf("That is wrong!\n\n");
    }else if (n == 2 && ans != x*y){
      printf("That is wrong!\n\n");
    }else if (n == 3 && ans != x/y){
      printf("That is wrong!\n\n");
    }else{
      printf("That is correct!\n\n");
      score = score+1;
    }
  }

  //Finish
  printf("Accuracy: %d%%\n",score*5);
  printf("Time taken: %ld seconds\n", time(NULL)-timer);
  return 0;
}

int generate(int seed, int limit){

  //Using time as seed
  srand(seed);

  //Modulus to get range of output
  int result = rand() % limit;
  return result;
}
