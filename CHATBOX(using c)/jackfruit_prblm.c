#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

// User structure
typedef struct {
    int userId;
    char name[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
} User;

// Product structure
typedef struct {
    int productId;
    char name[MAX_NAME_LEN];
    float price;
    int stock;
} Product;

// Graph structure for history tracking
typedef struct Graph {
    int adjMatrix[MAX_USERS][MAX_PRODUCTS]; // 1 for browsed, 2 for purchased
} Graph;

Graph historyGraph;

// Hash Tables for storing users and products
User *userTable[MAX_USERS];
Product *productTable[MAX_PRODUCTS];

// Hash functions
int hashUser(int userId) {
    return userId % MAX_USERS;
}

int hashProduct(int productId) {
    return productId % MAX_PRODUCTS;
}

// User Management
void addUser(int userId, const char *name, const char *email) {
    int index = hashUser(userId);
    User *newUser = (User *)malloc(sizeof(User));
    newUser->userId = userId;
    strcpy(newUser->name, name);
    strcpy(newUser->email, email);
    
    userTable[index] = newUser;
}

User* getUser(int userId) {
    int index = hashUser(userId);
    return userTable[index];
}

void updateUser(int userId, const char *name, const char *email) {
    User *user = getUser(userId);
    if (user) {
        strcpy(user->name, name);
        strcpy(user->email, email);
    }
}

// Product Management
void addProduct(int productId, const char *name, float price, int stock) {
    int index = hashProduct(productId);
    Product *newProduct = (Product *)malloc(sizeof(Product));
    newProduct->productId = productId;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->stock = stock;
    
    productTable[index] = newProduct;
}

Product* getProduct(int productId) {
    int index = hashProduct(productId);
    return productTable[index];
}

void updateProduct(int productId, float price, int stock) {
    Product *product = getProduct(productId);
    if (product) {
        product->price = price;
        product->stock = stock;
    }
}

// Initialize the history graph
void initHistoryGraph() {
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_PRODUCTS; j++) {
            historyGraph.adjMatrix[i][j] = 0;
        }
    }
}

// Record browsing history
void recordBrowsingHistory(int userId, int productId) {
    historyGraph.adjMatrix[userId][productId] = 1;
}

// Record purchase history
void recordPurchaseHistory(int userId, int productId) {
    historyGraph.adjMatrix[userId][productId] = 2;
}

// Retrieve and display user history
void retrieveUserHistory(int userId) {
    printf("History for User %d:\n", userId);
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (historyGraph.adjMatrix[userId][i] == 1) {
            printf("Browsed Product %d\n", i);
        }
        if (historyGraph.adjMatrix[userId][i] == 2) {
            printf("Purchased Product %d\n", i);
        }
    }
}

// Recommendation Engine: Generate product recommendations
void generateRecommendations(int userId) {
    printf("Generating recommendations for User %d:\n", userId);
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (historyGraph.adjMatrix[userId][i] == 1) { // If the user browsed the product
            printf("Recommended Product %d based on browsing history\n", i);
        }
        if (historyGraph.adjMatrix[userId][i] == 2) { // If the user purchased the product
            printf("Recommended Product %d based on purchase history\n", i);
        }
    }
}

int main() {
    // Initialize the history graph
    initHistoryGraph();

    // User Management: Adding users
    addUser(1, "Alice", "alice@example.com");
    addUser(2, "Bob", "bob@example.com");

    // Product Management: Adding products
    addProduct(101, "Laptop", 999.99, 50);
    addProduct(102, "Smartphone", 499.99, 100);
    addProduct(103, "Headphones", 99.99, 200);

    // Track browsing and purchase history
    recordBrowsingHistory(1, 101);
    recordBrowsingHistory(1, 102);
    recordPurchaseHistory(1, 103);

    recordBrowsingHistory(2, 102);
    recordPurchaseHistory(2, 101);

    // Retrieve and display user history
    retrieveUserHistory(1);
    retrieveUserHistory(2);

    // Generate recommendations for users based on their history
    generateRecommendations(1);
    generateRecommendations(2);

    // Update user and product data
    updateUser(1, "Alice Wonderland", "alice@newdomain.com");
    updateProduct(101, 899.99, 40);

    // Display updated data
    User *user = getUser(1);
    if (user) {
        printf("Updated User: %s, %s\n", user->name, user->email);
    }
    Product *product = getProduct(101);
    if (product) {
        printf("Updated Product: %s, Price: %.2f, Stock: %d\n", product->name, product->price, product->stock);
    }

    return 0;
}