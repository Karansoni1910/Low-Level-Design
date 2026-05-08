Design Menu System

Problem: Build a restaurant menu system where individual menu items and submenus share a common interface. A MenuItem is a leaf with a name and price. A SubMenu is a composite with a name that contains menu items and other submenus.

Requirements:

Component interface: Menu with display(indent) and getItemCount() returning an int
Leaf: MenuItem with a name and price. display() prints the item. getItemCount() returns 1.
Composite: SubMenu with a name. display() prints its name then delegates to children. getItemCount() sums children's counts.