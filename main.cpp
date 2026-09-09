#include <iostream>
#include <iomanip>
#include <vector>
#include "sales.h"

using namespace std;

int main()
{
	cout << "Monthly Products Sales Program\n\n";
	vector<Sale> sales;

	try
	{
		load_sales(sales);
	}
	catch (const runtime_error& e){
		cout << e.what() << endl;
		cout << "exiting program..\n\n";
		return 0;
	}

	display_sales(sales);

	double total = calc_total_sales(sales);

	cout << fixed << setprecision(2);
	cout << "\nTotal Monthly Sales: $" << total << endl;

	Sale top = find_top_product(sales);

	cout << "\nTop selling product: " << top.product << " Units Sold: " << top.quantity << endl << endl;

	return 0;
}
