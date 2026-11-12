#include <stdio.h>
#include <string.h>

static void remove_spaces(const char *text, char *out) {
   size_t j = 0;
   for (size_t i = 0; text[i] != '\0'; i++) {
       if (text[i] != ' ') out[j++] = text[i];
   }
   out[j] = '\0';
}

static void keep_digits(const char *text, char *out) {
   size_t j = 0;
   for (size_t i = 0; text[i] != '\0'; i++) {
       if (text[i] >= '0' && text[i] <= '9') out[j++] = text[i];
   }
   out[j] = '\0';
}

int main(void) {
   char text[32], no_spaces[32], digits[32];
   if (fgets(text, sizeof text, stdin) == NULL) return 1;
   text[strcspn(text, "\n")] = '\0';
   if (strlen(text) > 30) return 1;
   remove_spaces(text, no_spaces);
   keep_digits(text, digits);
   printf("no spaces: [%s]\n", no_spaces);
   printf("digits: [%s]\n", digits);
   return 0;
}