#include <stdio.h>
#include <string.h>

enum scale { CELSIUS = 0, FARENHEIT = 1 };

int temp(enum scale s, int temperature);

int main() {
  enum scale s;
  int temperature;

  printf("Please select the temperature scale to convert to: ");
  scanf("%d", &s);
  printf("Please select the temperature: ");
  scanf("%d", &temperature);

  printf("%d\n", temp(s, temperature));

  return 0;

}

int temp(enum scale s, int temperature) {

  if (s == CELSIUS) {
    return 5 * (temperature - 32) / 9;
  } else if (s == FARENHEIT) {
    return 9 * temperature / 5 + 32;
  }

  return 0;
}
