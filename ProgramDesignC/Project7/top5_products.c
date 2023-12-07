/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  The program is written in order to see the top 5 of products sale by the quantity   */
/*  in a store. The quantity of fruits and vegetables sold in the month is kept in      */
/*  a file. The program would read from the file, sort the products by quantity from    */
/*  the highest to lowest,and write on the new file the top 5 highest sale number.      */
/*  Quyen Dang.                                                                         */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 100
#define LIST_LEN 100
//Create the struct variable with name, price, and quantity.
struct product {
	char name[NAME_LEN + 1];
	double price;
	double quantity;
};

void sort_products(struct product list[], int n);
int main(void)
{
	FILE *rFile;
	FILE *wFile;
	rFile = fopen("fruits_vegetables.txt", "r");// open file to read
	wFile = fopen("top5.txt", "w");//open file to write on
	struct product list[LIST_LEN];//create array of struct product
	int i = 0, j;

	if(rFile == NULL)//check if file can open
	{
		printf("Error opening file");
		return 1;
	}
	while(!feof(rFile) && ! ferror(rFile)) //read the next product until end of file and file not error
	{
		if(fscanf(rFile,"%s %lf %lf", list[i].name,
		     &list[i].price, &list[i].quantity) == 3)
		i++;
	}
	sort_products(list, i);//call the sort function

	if(wFile == NULL) //check if file can open
	{
		printf("Error opening file.\n");
		return 1;
	}
//write the top 5 product to the wFile(top5.txt)
	for (j = 0; j < 5; j++)
		fprintf(wFile,"%-20s\t %.2lf\t %-11.2lf\n", list[j].name,
			list[j].price, list[j].quantity);
	fclose(rFile);
	fclose(wFile);

	return 0;
}
//function to sort the product by quantity from the highest to lowest
void sort_products(struct product list[], int n)
{
	int i, j;

	for( i = 0; i < n; i ++)
	{
		for(j = i + 1; j < n; j ++)//next index to compare with the previous one
		{
			if(list[i].quantity < list[j].quantity)//condition to sort
			{
				//change the index of the higher quantity
				struct product temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}

}


