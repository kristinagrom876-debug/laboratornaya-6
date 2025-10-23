/****************************
 * Автор: Кристина Щербакова*
 * Вариант: 14              *
 ****************************/
 
#include <stdio.h>
#include <string.h>

int main() {
  struct printer {
    char company[20];
    char print_type[20];
    char model[10];
    int cost;
  } p;
    
  int i;
  int numberOfPrinters = 0;
  double averageCost = 0;
  int maxCost = 0, minCost = 100000000;
  char search_print_type[20];
  char maxCompany[20], maxModel[10], minCompany[20], minModel[10];
    
  FILE *f = fopen("printers.txt", "w");
  for (i = 0; i < 3; i++) {
    printf("Enter printer company: \n");
    scanf("%s", p.company);
    printf("Enter print type: \n");
    scanf("%s", p.print_type);
    printf("Enter model: \n");
    scanf("%s", p.model);
    printf("Enter cost: \n");
    scanf("%d", &p.cost);
    fprintf(f, "%s %s %s %d\n", p.company, p.print_type, p.model, p.cost);
  }
    fclose(f);
    
    printf("Enter print type to search: \n");
    scanf("%s", search_print_type);
    
  f = fopen("printers.txt", "r");
    
  while (fscanf(f, "%s %s %s %d", p.company, p.print_type, p.model, &p.cost) != EOF) {
    if (strcmp(p.print_type, search_print_type) == 0) {
        averageCost += p.cost;
        numberOfPrinters += 1;
    }
        
    if (p.cost > maxCost) {
        maxCost = p.cost;
        strcpy(maxCompany, p.company);
        strcpy(maxModel, p.model);
    }
    if (p.cost < minCost) {
        minCost = p.cost;
        strcpy(minCompany, p.company);
        strcpy(minModel, p.model);
    }
  }
    
  fclose(f);
    
  if (numberOfPrinters > 0) {
    averageCost = averageCost / numberOfPrinters;
    printf("Average cost of %s printers = %.2f \n", search_print_type, averageCost);
    printf("Number of found printers = %d \n", numberOfPrinters);
  } else {
      printf("No printers found with print type: %s \n", search_print_type);
    }
    
  printf("Most expensive printer: %s %s, cost = %d \n", maxCompany, maxModel, maxCost);
  printf("Cheapest printer: %s %s, cost = %d \n", minCompany, minModel, minCost);
    
  return 0;
}
