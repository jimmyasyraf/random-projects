"""HANGMAN GAME !!!"""
import random
words = ["apple","sony"]
chosen_word = random.choice(words)
trial_length = len(chosen_word) + 2
list_letter = list(chosen_word)
"""print (list_letter)"""

def game():
	trial = trial_length
	inserted_word = []
	def guess(trial, inserted_word):
		letter = raw_input("Category: Tech Giants ")
		letter = raw_input("Guess a letter: ")
		if trial > 0 :

			if letter in list_letter :
				inserted_word.append(letter)
				print (inserted_word)
				trial = trial - 1
				if inserted_word == list_letter :
					print ("You win!")
					print ("It's %s") % (chosen_word)
				else:
					guess(trial, inserted_word)
			else :
				print ("try again")
				trial = trial - 1
				guess(trial, inserted_word)

		if trial <= 0 :
			print ("game over")

	guess(trial, [])
game()
