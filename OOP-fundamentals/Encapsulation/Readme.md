Design ShoppingCart Class

Problem: Build a ShoppingCart class that manages items, supports a one-time discount code, and prevents modifications after checkout.

Requirements:

Private map/dictionary of items (item name to price)
Private discount code (can only be applied once)
Private isCheckedOut flag
addItem(name, price): adds an item, but only if the cart hasn't been checked out
applyDiscount(code): if the code is "SAVE10" and no discount has been applied yet, marks the discount as applied and stores it. Returns success/failure.
getTotal(): returns the sum of all prices, minus 10% if a discount was applied
checkout(): marks the cart as checked out if it has at least one item. After checkout, no items can be added and no discounts can be applied.