# 🧑‍💼🛒 User & Product Management System

**Team Project**

## 📌 Project Overview

This project implements a basic management system in C for handling users and products, with the following capabilities:
- **User and Product Management** (Add, Retrieve, Update)
- **Browsing and Purchase History Tracking**
- **Product Recommendation Engine** based on user activity
- Uses **Hash Tables** for efficient lookup
- Maintains a **History Matrix** to track user-product interactions

---

## 🚀 Features

- 🔹 Add, get, and update users and products
- 🔹 Track browsing and purchasing activities
- 🔹 Fast data access using hash functions
- 🔹 Recommend products to users based on interaction history

---

## ⚙️ Function Overview

### 👤 User Management

| Function | Purpose | Operation |
|---------|---------|-----------|
| `addUser(int userId, const char *name, const char *email)` | Add new user | Hash `userId` and insert into user table |
| `getUser(int userId)` | Retrieve user | Hash `userId` and return matching user |
| `updateUser(int userId, const char *name, const char *email)` | Update user info | Get user by `userId` and update info |

### 📦 Product Management

| Function | Purpose | Operation |
|---------|---------|-----------|
| `addProduct(int productId, const char *name, float price, int stock)` | Add new product | Hash `productId` and insert into product table |
| `getProduct(int productId)` | Retrieve product | Hash `productId` and return matching product |
| `updateProduct(int productId, float price, int stock)` | Update product info | Get product and update price/stock |

### 🔢 Hashing Functions

| Function | Purpose | Operation |
|---------|---------|-----------|
| `hashUser(int userId)` | Hash user ID | `userId % MAX_USERS` |
| `hashProduct(int productId)` | Hash product ID | `productId % MAX_PRODUCTS` |

### 📚 History Management

| Function | Purpose | Operation |
|---------|---------|-----------|
| `initHistoryGraph()` | Initialize matrix | Set all cells to 0 |
| `recordBrowsingHistory(int userId, int productId)` | Track browsing | Set matrix cell to 1 |
| `recordPurchaseHistory(int userId, int productId)` | Track purchase | Set matrix cell to 2 |
| `retrieveUserHistory(int userId)` | Show user activity | Print browsing/purchase history |
# 🧑‍💼🛒 User & Product Management System

**Team Project**

## 📌 Project Overview

This project implements a basic management system in C for handling users and products, with the following capabilities:
- **User and Product Management** (Add, Retrieve, Update)
- **Browsing and Purchase History Tracking**
- **Product Recommendation Engine** based on user activity
- Uses **Hash Tables** for efficient lookup
- Maintains a **History Matrix** to track user-product interactions

---

## 🚀 Features

- 🔹 Add, get, and update users and products
- 🔹 Track browsing and purchasing activities
- 🔹 Fast data access using hash functions
- 🔹 Recommend products to users based on interaction history

---

## ⚙️ Function Overview

### 👤 User Management

| Function | Purpose | Operation |
|---------|---------|-----------|
| `addUser(int userId, const char *name, const char *email)` | Add new user | Hash `userId` and insert into user table |
| `getUser(int userId)` | Retrieve user | Hash `userId` and return matching user |
| `updateUser(int userId, const char *name, const char *email)` | Update user info | Get user by `userId` and update info |

### 📦 Product Management

| Function | Purpose | Operation |
|---------|---------|-----------|
| `addProduct(int productId, const char *name, float price, int stock)` | Add new product | Hash `productId` and insert into product table |
| `getProduct(int productId)` | Retrieve product | Hash `productId` and return matching product |
| `updateProduct(int productId, float price, int stock)` | Update product info | Get product and update price/stock |

### 🔢 Hashing Functions

| Function | Purpose | Operation |
|---------|---------|-----------|
| `hashUser(int userId)` | Hash user ID | `userId % MAX_USERS` |
| `hashProduct(int productId)` | Hash product ID | `productId % MAX_PRODUCTS` |

### 📚 History Management

| Function | Purpose | Operation |
|---------|---------|-----------|
| `initHistoryGraph()` | Initialize matrix | Set all cells to 0 |
| `recordBrowsingHistory(int userId, int productId)` | Track browsing | Set matrix cell to 1 |
| `recordPurchaseHistory(int userId, int productId)` | Track purchase | Set matrix cell to 2 |
| `retrieveUserHistory(int userId)` | Show user activity | Print browsing/purchase history |

### 🤖 Recommendation Engine

| Function | Purpose | Operation |
|---------|---------|-----------|
| `generateRecommendations(int userId)` | Suggest products | Based on interaction history |

---

## 🔁 Main Program Workflow

```c
int main() {
    initHistoryGraph();               // Initialize history tracking

    addUser(...);                     // Add user(s)
    addProduct(...);                  // Add product(s)

    recordBrowsingHistory(...);       // Log user browsing
    recordPurchaseHistory(...);       // Log user purchases

    retrieveUserHistory(...);         // View history
    generateRecommendations(...);     // Get recommendations

    updateUser(...);                  // Update user details
    updateProduct(...);               // Update product details

    getUser(...); getProduct(...);    // Retrieve latest info
}

### 🤖 Recommendation Engine

| Function | Purpose | Operation |
|---------|---------|-----------|
| `generateRecommendations(int userId)` | Suggest products | Based on interaction history |

---

## 🔁 Main Program Workflow

```c
int main() {
    initHistoryGraph();               // Initialize history tracking

    addUser(...);                     // Add user(s)
    addProduct(...);                  // Add product(s)

    recordBrowsingHistory(...);       // Log user browsing
    recordPurchaseHistory(...);       // Log user purchases

    retrieveUserHistory(...);         // View history
    generateRecommendations(...);     // Get recommendations

    updateUser(...);                  // Update user details
    updateProduct(...);               // Update product details

    getUser(...); getProduct(...);    // Retrieve latest info
}
