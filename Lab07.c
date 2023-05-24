#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Returns the number of vowels in a given string.
 *
 * Requires: The given string has no spaces. Can contain uppercase, lowercase
 * characters and digits.
 *
 * Examples:
 *  4  num_vowels("BitsPilani")
 *  2  num_vowels("GOA")
 *  0  num_vowels("CSF111")
 */
int num_vowels(char str[])
{
  int count = 0;
  char vowels[] = "aeiouAEIOU";
  for (int i = 0; str[i]; i++)
  {
    if (strchr(vowels, str[i]))
    {
      count++;
    }
  }
  return count;
}

/**
 * @brief Prints the longest substring in a given string with no repeating
 * characters. A character in lowercase and uppercase is treated different. ('a'
 * is different than 'A') If there are multiple substrings of the same length,
 * print the substring whose starting index in the original string is higher.
 *
 * Requires: The given string has no spaces. Can contain uppercase, lowercase
 * characters and digits.
 *
 * Examples:
 *  Prints "abcd" for longest_substring("abcd")
 *  Prints "est" for longest_substring("test")
 *  Prints "BITSPilan" for longest_substring("BITSPilaniGoaCampus")
 *  Prints "TSPILAN"  longest_substring("BITSPILANIGOACAMPUS")
 */
void longest_substring(char str[]) {
  char longest[100];
  int hash[256] = {0};
  int start = 0;
  int max = 0;
  int end = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (hash[str[i]] >= start) {
      start = hash[str[i]];
    }
    hash[str[i]] = i + 1;
    if (i - start + 1 >= max) {
      max = i - start + 1;
      end = i;
    }
  }
  strncpy(longest, str + end - max + 1, max);
  longest[max] = '\0';
  printf("Longest substring with no repeating characters: %s\n", longest);
}



int main()
{
  printf("This program supports TWO operations:\n");
  printf("\t1. Count the number of vowels in a string,\n");
  printf("\t2. Find the longest substring with no repeating characters.\n\n");
  printf("Choose an operation (1 or 2): ");
  int operation = 0;
  scanf("%d", &operation);

  const int MAX_LENGTH = 100;
  char str[MAX_LENGTH];

  printf("Enter the string: ");
  scanf("%s", str);

  if (operation == 1)
  {
    printf("The number of vowels in %s is %d\n", str, num_vowels(str));
  }

  else if (operation == 2)
  {
    longest_substring(str);
  }

  return 0;
}
