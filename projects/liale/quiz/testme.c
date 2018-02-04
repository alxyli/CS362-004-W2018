#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char* buffer = 0;

char inputChar()
{
    // randomChar is selected from the set of input values and returned
    char randomChar = "[({ ax})]reset"[rand() % 14];
    return randomChar;
}

char *inputString()
{
    // free buffer to avoid memory leak
    if (buffer != 0)
      free(buffer);

    // allocate memory for string
    buffer = malloc(5 * sizeof(char));

    // fill spots 0-4 in string with only the letters from inputChar() function
    for (int i = 0; i < 5; i++) {
      char letter = inputChar();
      while (letter < 97 || letter > 116)
        letter = inputChar();

      buffer[i] = letter;
    }

    // terminate string with NULL
    buffer[5] = 0;
    
    return buffer;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
