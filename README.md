# ❌⭕ C Tic-Tac-Toe with Minimax AI

A high-performance console-based Tic-Tac-Toe game written in C. It features a smart AI opponent that calculates the optimal move using the Minimax algorithm.

## 🚀 Features
- **2 Game Modes:**
  - Single Player (Human vs Computer)
  - Multiplayer (Human vs Human)
- **3 Difficulty Levels:**
  - **Easy:** Random moves.
  - **Medium:** Blocks winning moves, otherwise plays strategically.
  - **Impossible:** Uses the **Minimax Algorithm** to recursively calculate the perfect move. The AI *cannot* lose in this mode.
- **Clean Console UI:** Clear grid visualization and input validation.

## 🛠️ Technologies Used
- C Programming Language
- Standard Libraries (`stdio.h`, `stdlib.h`, `time.h`)

## 💻 How to Run
1. **Compile the code:**
   ```bash
   gcc Tic_Tac_Toe_Game.c -o game