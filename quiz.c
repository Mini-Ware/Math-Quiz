#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate(int limit)
{
    //Modulus to get range of output
    int result = rand() % limit;
    return result;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    
    //Variable declaration
    int ans, score, timer, x, y, n;
    char op[] = "+-x/";
    timer = time(NULL);

    //Ask questions
    score = 0;
    for (int qn = 1; qn <= 20; qn++)
    {

        x = generate(13);
        y = generate(12);
        n = generate(4);

        //Ensure questions can be solved
        y += 1;
        if (n == 3)
        {
            x *= y;
        }

        printf("%d) What is %d %c %d?\n", qn, x, op[n], y);
        printf("Answer: ");

        //Get user input
        scanf("%d", &ans);
        if (n == 0 && ans != x + y)
        {
            printf("That is wrong!\n\n");
        }
        else if (n == 1 && ans != x - y)
        {
            printf("That is wrong!\n\n");
        }
        else if (n == 2 && ans != x * y)
        {
            printf("That is wrong!\n\n");
        }
        else if (n == 3 && ans != x / y)
        {
            printf("That is wrong!\n\n");
        }
        else
        {
            printf("That is correct!\n\n");
            score++;
        }
    }

    //Finish
    printf("Accuracy: %d%%\n", score * 5);
    printf("Time taken: %ld seconds\n", time(NULL) - timer);
    return 0;
}
