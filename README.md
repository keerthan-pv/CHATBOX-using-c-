User & Product Management System
This project implements a basic management system for users and products, including history tracking and a recommendation engine based on user activity. It uses hash tables for efficient data storage and retrieval.

Features

User and Product Management (Add, Get, Update)

Browsing and Purchase History Tracking

Hashing for Quick Lookups

Product Recommendation Engine

Function Overview

User Management
Function	Purpose	Operation
addUser(int userId, const char *name, const char *email)	Add a new user	Creates a User struct, hashes userId, and inserts into user table
getUser(int userId)	Retrieve user	Hashes userId and returns the user
updateUser(int userId, const char *name, const char *email)	Update user info	Gets the user by userId and updates name and email

Product Management
Function	Purpose	Operation
addProduct(int productId, const char *name, float price, int stock)	Add new product	Creates a Product struct, hashes productId, and inserts into product table
getProduct(int productId)	Retrieve product	Hashes productId and returns the product
updateProduct(int productId, float price, int stock)	Update product info	Gets the product by productId and updates price and stock

Hashing Functions
Function	Purpose	Operation
hashUser(int userId)	Hash user ID	userId % MAX_USERS
hashProduct(int productId)	Hash product ID	productId % MAX_PRODUCTS

History Management
Function	Purpose	Operation
initHistoryGraph()	Initialize history graph	Sets all elements in adjacency matrix to 0
recordBrowsingHistory(int userId, int productId)	Track product browse	Sets adjacencyMatrix[userId][productId] = 1
recordPurchaseHistory(int userId, int productId)	Track product purchase	Sets adjacencyMatrix[userId][productId] = 2
retrieveUserHistory(int userId)	Show user history	Loops over products and prints browse/purchase info

Recommendation Engine
Function	Purpose	Operation
generateRecommendations(int userId)	Recommend products	Uses browsing and purchase history to suggest products

Main Program Workflow

c
Copy
Edit
main() {
    initHistoryGraph();                       // Initialize history matrix
    addUser(...);                             // Add user(s)
    addProduct(...);                          // Add product(s)
    recordBrowsingHistory(...);               // Log browsing history
    recordPurchaseHistory(...);               // Log purchase history
    retrieveUserHistory(...);                 // Print user activity
    generateRecommendations(...);             // Show recommendations
    updateUser(...);                          // Update user data
    updateProduct(...);                       // Update product data
    getUser(...); getProduct(...);            // Retrieve updated info
}
Technologies Used

Programming Language: C

Data Structures: Hash Tables, Adjacency Matrix

Notes

Ensure MAX_USERS and MAX_PRODUCTS are defined appropriately for hashing.

History matrix can be expanded to support additional actions or weights.

The system can be extended with file I/O or database integration.

