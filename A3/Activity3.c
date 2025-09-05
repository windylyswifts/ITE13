#include <stdio.h>

int main() {
    // SIMPLE STORE INVENTORY SYSTEM
    // 
    // You are managing a small convenience store with 5 products.
    // Track inventory levels and sales throughout the week (7 days).
    // 
    // Products: 0=Bread, 1=Milk, 2=Eggs, 3=Apples, 4=Chips
    // Starting inventory: 20, 15, 30, 25, 40
    
    int inventory[5] = {20, 15, 30, 25, 40}; // Starting inventory for each product
    int daily_sales[7][5]= {
        {5,3,8,12,7},
        {4,2,6,10,5},
        {6,4,7,8,6},
        {3,5,9,15,8},
        {8,6,12,20,12},
        {10,7,15,18,15},
        {7,4,10,14,9}
    }; // Sales for each product on each day
    int prices[5] = {3, 5, 8, 2, 4}; // Price per unit for each product
    
    printf("CONVENIENCE STORE INVENTORY SYSTEM\n");
    printf("==================================\n\n");
    
    // PART 1: Initialize daily sales data
    // Week sales data (fill this into your 2D array):
    // Day 0 (Mon): 5, 3, 8, 12, 7
    // Day 1 (Tue): 4, 2, 6, 10, 5  
    // Day 2 (Wed): 6, 4, 7, 8, 6
    // Day 3 (Thu): 3, 5, 9, 15, 8
    // Day 4 (Fri): 8, 6, 12, 20, 12
    // Day 5 (Sat): 10, 7, 15, 18, 15
    // Day 6 (Sun): 7, 4, 10, 14, 9
    
    // TODO: Fill the daily_sales array with the data above
    
    
    
    // Display the sales data
    printf("Daily Sales Report:\n");
    printf("Day   | Bread | Milk | Eggs | Apples | Chips\n");
    printf("------|-------|------|------|--------|------\n");
    
    char days[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    
    for(int day = 0; day < 7; day++) {
        printf("%s   |", days[day]);
        for(int product = 0; product < 5; product++) {
            printf("  %2d  |", daily_sales[day][product]);
        }
        printf("\n");
    }
    printf("\n");
    
    // PART 2: Calculate total sales for each product over the week
    // added '0' as a starting point so that the loop will base on the existing value and increase
    int total_sales[5] = {0}; // Total sales for each product
    
    // TODO: Calculate total sales for each product across all 7 days
    for (int i = 0; i < 7; i++){
        total_sales[0] += daily_sales[i][0];   
        total_sales[1] += daily_sales[i][1];   
        total_sales[2] += daily_sales[i][2];   
        total_sales[3] += daily_sales[i][3];      
        total_sales[4] += daily_sales[i][4];      
    }
    
    printf("Weekly Sales Summary:\n");
    char products[5][10] = {"Bread", "Milk", "Eggs", "Apples", "Chips"};
    
    for(int i = 0; i < 5; i++) {
        printf("%s: %d units sold\n", products[i], total_sales[i]);
    }
    printf("\n");
    
    // PART 3: Calculate remaining inventory after the week
    int remaining[5]= {0};
    
    // TODO: Calculate remaining inventory = starting inventory - total sales
    // If remaining goes negative, set it to 0 (can't have negative inventory)
    
    for (int i = 0; i < 7; i++){
        inventory[0] -= daily_sales[i][0];
        inventory[1] -= daily_sales[i][1];
        inventory[2] -= daily_sales[i][2];
        inventory[3] -= daily_sales[i][3];
        inventory[4] -= daily_sales[i][3];
    }
    for (int i = 0; i < 5; i++){
        remaining[i] = inventory[i];
        if (remaining[i] <= 0){
            remaining[i] = 0;
        }
    }
    
    
    printf("Remaining Inventory:\n");
    for(int i = 0; i < 5; i++) {
        printf("%s: %d units remaining\n", products[i], remaining[i]);
    }
    printf("\n");
    
    // PART 4: Find the best and worst selling products
    int best_product = 0;
    int worst_product = 0;
    
    // TODO: Find which product sold the most units (best seller)
    // TODO: Find which product sold the least units (worst seller)
    
    for (int i = 0; i < 5; i++){        
        if (total_sales[i] >= total_sales[0] && total_sales[i] >= total_sales[1] &&
            total_sales[i] >= total_sales[2] && total_sales[i] >= total_sales[3] &&
            total_sales[i] >= total_sales[4]){
            best_product = i;
            }
            if (total_sales[i] <= total_sales[0] && total_sales[i] <= total_sales[1] &&
            total_sales[i] <= total_sales[2] && total_sales[i] <= total_sales[3] &&
            total_sales[i] <= total_sales[4]){
            best_product = i;
            }
    }
    
    
    printf("Best Seller: %s (%d units)\n", products[best_product], total_sales[best_product]);
    printf("Worst Seller: %s (%d units)\n\n", products[worst_product], total_sales[worst_product]);
    
    // PART 5: Calculate daily revenue (money earned each day)
    int daily_revenue[7]= {0};
    
    // TODO: For each day, calculate revenue = sum of (sales * price) for all products
    
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 5; j++){
            daily_revenue[i] += daily_sales[i][j] * prices[j];
        }
    }
    
    
    printf("Daily Revenue:\n");
    for(int day = 0; day < 7; day++) {
        printf("%s: $%d\n", days[day], daily_revenue[day]);
    }
    printf("\n");
    
    // PART 6: Find the most profitable day
    int best_day = 0;
    
    // TODO: Find which day had the highest revenue
    
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 5; j++){
            if (daily_revenue[i] >= daily_revenue[0] && daily_revenue[i] >= daily_revenue[1] &&
            daily_revenue[i] >= daily_revenue[2] && daily_revenue[i] >= daily_revenue[3] &&
            daily_revenue[i] >= daily_revenue[4]){
                best_day = i;
            }
        }
    }
    
    
    printf("Most Profitable Day: %s ($%d)\n\n", days[best_day], daily_revenue[best_day]);
    
    // PART 7: Restock Alert System
    // Check which products need restocking (less than 5 units remaining)
    
    printf("Restock Alerts:\n");
    int restock_needed = 0;
    int temp = 0;
    // TODO: Check each product's remaining inventory
    // If remaining < 5, print a restock alert for that product
    // Count how many products need restocking
    
    for (int i = 0; i < 5; i++){
        if (remaining[i] < 5){
            while (temp != 5){
                temp++;
            }
            restock_needed += temp;
            printf("\nRequired stocks for %s:%d", products[i], temp);
            temp = 0;//reset       
        }
    }
    
    
    if(restock_needed == 0) {
        printf("No restocking needed!\n");
    } else {
        printf("\nTotal products needing restock: %d\n", restock_needed);
    }
    printf("\n");
    
    // PART 8: Weekly Performance Summary
    int total_weekly_revenue = 0;
    int total_units_sold = 0;
    
    // TODO: Calculate total revenue for the entire week
    // TODO: Calculate total units sold across all products
    
    for (int i = 0; i < 7; i++){
        total_weekly_revenue += daily_revenue[i];
        for (int j = 0; j < 5; j++){
            total_units_sold += daily_sales[i][j];
        }
    }
    
    
    
    printf("=== WEEKLY PERFORMANCE SUMMARY ===\n");
    printf("Total Revenue: $%d\n", total_weekly_revenue);
    printf("Total Units Sold: %d\n", total_units_sold);
    printf("Average Daily Revenue: $%d\n", total_weekly_revenue / 7);
    
    // Simple validation - check if calculations seem reasonable
    if(total_weekly_revenue > 0 && total_units_sold > 0) {
        printf("\nSUCCESS: All calculations completed!\n");
    } else {
        printf("\nERROR: Check your calculations.\n");
    }
    
    
    return 0;
}