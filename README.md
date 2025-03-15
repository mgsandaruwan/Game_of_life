# Game of Life - Arduino Implementation with 8x8 LED Matrix

## About the Project

This project is a simple implementation of Conway's Game of Life using an Arduino and an 8x8 LED matrix. The game simulates the life cycle of cells based on their neighbors, where each cell can either be alive or dead. The state of the grid evolves with each generation based on certain rules, creating interesting patterns and behaviors.

In this project, the LED matrix is used to visually represent the grid, with each cell being either on (alive) or off (dead). The game runs in a loop, continuously evolving and displaying the next generation of the grid.

## Key Features

- **8x8 LED Matrix Display**: Visualizes the grid of cells for Conway's Game of Life.
- **Randomized Initial State**: Cells are randomly initialized as alive or dead at the start of the game.
- **Neighbor Count**: Cells' states are updated based on their neighboring cells.
- **Grid Update**: The grid is updated and displayed every half-second (500ms).
- **Edge Wrapping**: The grid wraps around at the edges, making it behave as a toroidal array (where the edges are connected).

## Technologies Used

- **Arduino**: Used to control the 8x8 LED matrix and run the Game of Life logic.
- **LedControl Library**: A library to interface with the MAX7219 and control the LED matrix.
- **MAX7219**: Used to drive the 8x8 LED matrix.

## How to Use

1. Clone the repository to your local machine:


