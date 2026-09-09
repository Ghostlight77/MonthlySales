#include <iostream>
#include <fstream>
#include <iomanip>
#include "sales.h"

using namespace std;

void load_sales(vector<Sale>& sales)
{
	ifstream inputfile("monthlysales.txt");
	if (!inputfile)
	{
		throw runtime_error("Monthly sales file was not found!");
	}

	Sale sale;

	while (inputfile >> sale.product >> sale.price >> sale.quantity)
	{
		sales.push_back(sale);
	}
	inputfile.close();
}

void display_sales(const vector<Sale>& sales)
{
	cout << fixed << setprecision(2);
	cout << "MONTHLY PRODUCT SALES\n"
		<< "------------------------\n";

	for (Sale sale : sales)
	{
		cout << sale.product << " - $" << sale.price << " - Sold: " << sale.quantity << endl << endl;
	}
}

double calc_total_sales(const vector<Sale>& sales)
{
	double total = 0;
	for (Sale sale : sales)
	{
		total += sale.price * sale.quantity;
	}
	return total;
}

Sale find_top_product(const vector<Sale>& sales)
{
	Sale topProd = sales[0];

	for (Sale sale : sales){
		if (sale.quantity > topProd.quantity){
			topProd = sale;
		}
	}
	return topProd;
}
