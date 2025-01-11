User Management

1) addUser(int userId, const char *name, const char *email)

-Purpose: Adds a new user to the user hash table.
-Operation: Creates a User struct with the provided details, hashes the user ID to find an index, and stores the user at that index.

2) getUser(int userId)

-Purpose: Retrieves a user from the hash table.
-Operation: Computes the hash index using hashUser() and returns the user at that index.

3)updateUser(int userId, const char *name, const char *email)

-Purpose: Updates the details of an existing user.
-Operation: Retrieves the user using getUser() and updates the name and email fields.


Product Management

4) addProduct(int productId, const char *name, float price, int stock)

-Purpose: Adds a new product to the product hash table.
-Operation: Creates a Product struct, hashes the product ID to find an index, and stores the product at that index.

5)getProduct(int productId)

-Purpose: Retrieves a product from the hash table.
-Operation: Computes the hash index using hashProduct() and returns the product at that index.

6)updateProduct(int productId, float price, int stock)

-Purpose: Updates the price and stock of an existing product.
-Operation: Retrieves the product using getProduct() and modifies the price and stock fields.



Hashing

7)hashUser(int userId)

-Purpose: Computes a hash index for a user ID.
-Operation: Uses modulo operation (userId % MAX_USERS) to ensure indices stay within bounds.

8)hashProduct(int productId)

-Purpose: Computes a hash index for a product ID.
-Operation: Similar to hashUser(), uses modulo operation to find the index.

History Management

9)initHistoryGraph()

-Purpose: Initializes the adjacency matrix for the history graph.
-Operation: Sets all elements in the matrix to 0, indicating no history initially.

10)recordBrowsingHistory(int userId, int productId)

-Purpose: Records that a user browsed a product.
-Operation: Updates the adjacency matrix at [userId][productId] to 1.

11)recordPurchaseHistory(int userId, int productId)

-Purpose: Records that a user purchased a product.
-Operation: Updates the adjacency matrix at [userId][productId] to 2.

12)retrieveUserHistory(int userId)

-Purpose: Retrieves and displays the browsing and purchase history of a user.
-Operation: Iterates over the product indices for the given user ID in the adjacency matrix and prints the corresponding history.


Recommendation Engine

13)generateRecommendations(int userId)
-Purpose: Generates product recommendations for a user based on their browsing and purchase history.
-Operation: Checks the adjacency matrix for entries 1 (browsed) and 2 (purchased), and prints recommendations accordingly.


Main Program Workflow
14)main()
-Purpose: Drives the program by initializing structures, adding data, recording history, retrieving history, generating recommendations, and updating data.
-Operation:

Initializes the history graph using initHistoryGraph().
Adds users and products using addUser() and addProduct().
Records history using recordBrowsingHistory() and recordPurchaseHistory().
Displays user history with retrieveUserHistory().
Generates recommendations using generateRecommendations().
Updates user and product details using updateUser() and updateProduct().
Demonstrates the updated data retrieval with getUser() and getProduct().