#include <LedControl.h>

// Pin configuration for MAX7219
const int DIN_PIN = 12;   // Data In
const int CS_PIN = 10;    // Chip Select
const int CLK_PIN = 11;   // Clock

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

const int rows = 8;
const int cols = 8;
byte grid[rows][cols];
byte nextGrid[rows][cols];

void setup() {
  lc.shutdown(0, false);       // Wake up the MAX7219
  lc.setIntensity(0, 8);       // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);          // Clear display register

  randomSeed(analogRead(0));   // Seed the random function
  
  // Initialize grid with random states
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = random(2);  // Randomly set cells to 0 or 1
    }
  }
}

void loop() {
  displayGrid();
  computeNextGeneration();
  delay(500);  // Delay between generations
}

void displayGrid() {
  for (int i = 0; i < rows; i++) {
    byte rowValue = 0;
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 1) {
        rowValue |= (1 << j);
      }
    }
    lc.setRow(0, i, rowValue);
  }
}

void computeNextGeneration() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int liveNeighbors = countLiveNeighbors(i, j);
      
      if (grid[i][j] == 1) {  // Cell is alive
        if (liveNeighbors < 2 || liveNeighbors > 3) {
          nextGrid[i][j] = 0; // Cell dies
        } else {
          nextGrid[i][j] = 1; // Cell lives
        }
      } else {  // Cell is dead
        if (liveNeighbors == 3) {
          nextGrid[i][j] = 1; // Cell becomes alive
        } else {
          nextGrid[i][j] = 0; // Cell stays dead
        }
      }
    }
  }
  
  // Copy nextGrid to grid
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = nextGrid[i][j];
    }
  }
}

int countLiveNeighbors(int x, int y) {
  int liveCount = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;  // Skip the cell itself
      int newX = (x + i + rows) % rows;  // Wrap around for edge cells
      int newY = (y + j + cols) % cols;  // Wrap around for edge cells
      liveCount += grid[newX][newY];
    }
  }
  return liveCount;
}
