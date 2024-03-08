# Program: Tic-Tac-Toe with numbers.
# Author: Mohammad Walid Abdulmotal - 20230362 - no section yet
# Version: 3.0
# Date: 28/2/2024

def again():
    while True:
        try:
            # Ask user for input to play again or exit
            choice = int(input("1) Play Again\n2) Exit\n"))

            if choice == 1:
                main_game()  # If user chooses to play again, restart the game
                break
            elif choice == 2:
                exit()  # If user chooses to exit, terminate the program
            else:
                print("Please Enter a valid input")
        except ValueError:  # Handle the case when user enters a non-integer input
            print("Please Enter a valid input")

# Function to check if a player has won the game
def win_check(board):
    for i in range(3):

        try:
            if sum(board[i]) == 15:  # Check win in rows
                return True
        except TypeError:
            pass

        try:
            if sum(board[j][i] for j in range(3)) == 15: # Check win in columns
                return True
        except TypeError:
            pass

    try:
        if sum(board[i][i] for i in range(3)) == 15:# Check for a win in the diagonals
            return True
    except TypeError:
        pass

    try:
        if sum(board[i][2 - i] for i in range(3)) == 15: # Check for a win diagonaly
            return True
    except TypeError:
        pass

    return False

# Function to switch the player turn between 1 and 2
def switch(PlayerTurn):
    if PlayerTurn == 1:
        return 2
    if PlayerTurn == 2:
        return 1

# Validation Function
def check_valid(number, p1numbers, p2numbers, PlayerTurn):
    if PlayerTurn == 1:
        if number in p1numbers:
            return True
        else:
            print("Please enter a valid input!")
            return False
    if PlayerTurn == 2:
        if number in p2numbers:
            return True
        else:
            print("Please enter a valid input!")
            return False

# Function to a move on the board
def move(board, p1numbers, p2numbers, PlayerTurn):
    while True:
        try:
            try:
                # Get input from the player for the (row, column, and number)
                row, col, number = map(int, (input(f'Player {PlayerTurn} choose a row and column and the number with spaces between every number: ').split()))
                if board[row][col] == None and check_valid(number, p1numbers, p2numbers, PlayerTurn):
                    board[row][col] = number # Update the board
                    print("")
                    break
            except ValueError:
                print("Please enter a valid input!")
        except IndexError:
            print("Please enter valid row and column values within the range.")

# Function to display the current game state (updated)
def disp_game(board):
    col = 0
    for row in board:
        print(" | ".join(map(str, row)), "|", str(col))
        col += 1
    print("  0      1      2  ")
    print("")

# Main function
def main_game():
    PlayerTurn = 1 # initializing for Player 1 to start the game
    board = [[None, None, None],
             [None, None, None],    # initializing the board of the game
             [None, None, None]]
    p1numbers = [1, 3, 5, 7, 9]  # player1's available numbers
    p2numbers = [0, 2, 4, 6, 8]  # player2's available numbers
    while True:
        disp_game(board)  # Display the current updated game state
        move(board, p1numbers, p2numbers, PlayerTurn)  # move function to start a move
        if win_check(board):  # Checks if the current player won
            print(f"Congrats! Player {PlayerTurn} wins !")
            again()  # Ask if players want to play again or not
            return
        PlayerTurn = switch(PlayerTurn)  # To switch the player turn
        print("----------------")


print("*** Welcome to Tic-Tac-Toe with numbers ***\n") # Welcoming Message
main_game() # Calling main_game function to start game
