// Include - to use for output to the screen
#include <stdio.h>

// Include for string functions
#include <string.h>

// Main function for running program
int main(void)
{
	// Creates an input and output file
	FILE * inputFile;
	FILE * outputFile;
	
	// Creates variables at top of main
	int number;
	int counter = 0;
	char item[20];
	double priceInitial;
	double pricePerItem;
	char markupCategory[20];
	int quantity;
	double markupPercentage;
	double sales;
	double totalSales = 0;
	double profit;
	double totalProfit = 0;
	
	// Opens the file for the input
	inputFile = fopen("DataFile.txt", "r");
	
	// Opens the file for the output
	outputFile = fopen("LabOutput.txt", "w");
	
	// Print header
	fprintf(outputFile, "------------------------------------\n");
	fprintf(outputFile, "[COLLEGE]\n");
	fprintf(outputFile, "Lab Written by: [NAME]\n");
	fprintf(outputFile, "Lab # 3\n");
	fprintf(outputFile, "------------------------------------\n");
	fprintf(outputFile, "\n");
	
	// Print item group header
	fprintf(outputFile, "%*s", 0, "No.");
	fprintf(outputFile, "%*s", 8, "Product");
	fprintf(outputFile, "%*s", 14, "Retail");
	fprintf(outputFile, "%*s", 12, "Mark-up");
	fprintf(outputFile, "%*s", 14, "Price per");
	fprintf(outputFile, "%*s", 13, "Quantity");
	fprintf(outputFile, "%*s", 10, "Total");
	fprintf(outputFile, "%*s\n", 13, "Total");
	fprintf(outputFile, "%*s", 24, "Cost");
	fprintf(outputFile, "%*s", 15, "Percentage");
	fprintf(outputFile, "%*s", 9, "Item");
	fprintf(outputFile, "%*s", 26, "Sales");
	fprintf(outputFile, "%*s\n", 14, "Profit");
		
	// Determines if the text file contains contents
	if (inputFile != NULL)
	{
		while (counter < 20)
		{
			
			// Obtains data from each line in the data file
			fscanf(inputFile, "%s%lf%s%d", &item, &priceInitial, &markupCategory, &quantity);
			
			// Determines value of markup
			if(strcmp(markupCategory, "A") == 0)
			{
				markupPercentage = 1.40;
			}
			else if (strcmp(markupCategory, "B") == 0)
			{
				markupPercentage = 1.50;
			}
			else
			{
				markupPercentage = 1.60;
			}
			
			// Increases markup percentage is quantity is greater than 60
			if(quantity > 60)
			{
				markupPercentage += 0.10;
				
			}
			
			// Uses markup to determine item price
			pricePerItem = priceInitial*markupPercentage;
			
			// Determines the total sales of the specific item
			sales = pricePerItem*quantity;
			
			// Determines the total profit of a product
			profit = (pricePerItem-priceInitial)*quantity;
			
			// Prints values to screen in proper format
			fprintf(outputFile, "%-4d", counter + 1);
			fprintf(outputFile, "%-15s", item);
			fprintf(outputFile, "$%-10.2f", priceInitial);
			fprintf(outputFile, "%-12.2f", markupPercentage-1);
			fprintf(outputFile, "$%-13.2f", pricePerItem);
			fprintf(outputFile, "%-13d", quantity);
			fprintf(outputFile, "$%-12.2f", sales);
			fprintf(outputFile, "$%.2f\n", profit);
			counter++;
			totalSales += sales;
			totalProfit += profit;
			
		}
		
	}
	else
	{
		// Print error message to the screen
		printf("File did not open\n");
		
	}
	
	// Prints the total sales and total profit of all items combined
	fprintf(outputFile, "\n");
	fprintf(outputFile, "Total Sales: $%.2f\n", totalSales);
	fprintf(outputFile, "Total Profit: $%.2f\n", totalProfit);
	
	// Close input file
	fclose(inputFile);
	
	// Close output file
	fclose(outputFile);
	
	// Returning 0 to end the main
	return 0;
}
