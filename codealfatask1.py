import random

def play_hangman():
    # 1. Small list of 5 predefined words
    words = ["python", "coding", "developer", "hangman", "computer"]
    
    # Select a random word from the list
    word_to_guess = random.choice(words)
    guessed_letters = []
    incorrect_guesses = 0
    max_incorrect = 6
    
    print("==================================")
    print("   WELCOME TO TEXT HANGMAN!       ")
    print("==================================")
    print(f"You have {max_incorrect} incorrect guesses allowed.")
    
    # 2. While loop for game progression
    while incorrect_guesses < max_incorrect:
        # Display current progress (e.g., _ y t _ o n)
        display_word = ""
        for letter in word_to_guess:
            if letter in guessed_letters:
                display_word += letter + " "
            else:
                display_word += "_ "
        
        print("\nWord:", display_word.strip())
        
        # Check if the player has won
        if "_" not in display_word:
            print("\n🎉 Congratulations! You guessed the word correctly!")
            break
            
        # Get user input
        guess = input("Guess a letter: ").lower().strip()
        
        # Input validation
        if len(guess) != 1 or not guess.isalpha():
            print("⚠️ Please enter a single valid alphabetical letter.")
            continue
            
        if guess in guessed_letters:
            print(f"⚠️ You already guessed the letter '{guess}'. Try another one.")
            continue
            
        # Record the guess
        guessed_letters.append(guess)
        
        # 3. If-else conditional logic for checks
        if guess in word_to_guess:
            print(f"✅ Good job! '{guess}' is in the word.")
        else:
            incorrect_guesses += 1
            remaining = max_incorrect - incorrect_guesses
            print(f"❌ Incorrect! '{guess}' is not in the word.")
            print(f"Remaining incorrect guesses: {remaining}")
            
    else:
        # Executed when the while loop exhausts all incorrect guesses
        print("\n💀 Game Over! You ran out of incorrect guesses.")
        print(f"The hidden word was: {word_to_guess}")

if __name__ == "__main__":
    play_hangman()