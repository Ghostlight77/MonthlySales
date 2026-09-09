#pragma once
#ifndef WARNE_SALES_H
#define WARNE_SALES_H

#include <string>
#include <vector>

struct Sale {
	std::string product;
	double price;
	int quantity;
};

void load_sales(std::vector<Sale>& sales);
void display_sales(const std::vector<Sale>& sales);
double calc_total_sales(const std::vector<Sale>& sales);
Sale find_top_product(const std::vector<Sale>& sales);

#endif
