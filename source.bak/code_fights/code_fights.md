# Code Fights 
code practice and exercises from [Code Fights website](https://codesignal.com/)

## Boared Friends
Two friends Davit and Tigran were bored. So they decided to play a game.? <br>
Rules of the game are as follows: First, they choose an integer n. Then they take successive turns, starting with Davit. <br>
In each turn, a player chooses an integer from 1 to 8 (inclusive) and subtracts it from n. <br>
The player wins if after his turn, n becomes 0. <br>
Your task is to determine whether Davit will win or not, assuming that both players play optimally. <br>

### Examples
For n = "5", the output should be boredFriends(n) = true. Davit can make n = 0 after his first move. <br>
For n = "9", the output should be boredFriends(n) = false. Davit can't win during his first move,
but no matter what number he chooses, Tigran can win on the next move. <br>

## Cipher 26
You've intercepted an encrypted message, and you are really curious about its contents.
You were able to find out that the message initially contained only lowercase English letters,
and was encrypted with the following cipher:
  Let all letters from 'a' to 'z' correspond to the numbers from 0 to 25, respectively.
  The number corresponding to the ith letter of the encrypted message is then equal to the sum of numbers
    corresponding to the first i letters of the initial unencrypted message modulo 26.
Now that you know how the message was encrypted, implement the algorithm to decipher it.
### Example:
For message = "taiaiaertkixquxjnfxxdh", the output should be cipher26(message) = "thisisencryptedmessage".
The initial message "thisisencryptedmessage" was encrypted as follows:
  letter 0: t -> 19 -> t;
  letter 1: th -> (19 + 7) % 26 -> 0 -> a;
  letter 2: thi -> (19 + 7 + 8) % 26 -> 8 -> i;
  etc.

## First Duplicate
TODO: get the description for this one from website

## First Non Repeating
TODO: get the description for this one from website

## Is Power
Determine if the given number is a power of some non-negative integer

## Least Appearance
TODO: get the description for this one from website

## PEP Eight
PEP 8, Style Guide for Python Code, requires a coder to write lines no longer than 79 characters.
Given some code line, find out if it satisfies PEP 8 requirements.

## Reach Next Level
You are playing an RPG game.
Currently your experience points (XP) total is equal to experience.
To reach the next level your XP should be at least at threshold.
If you kill the monster in front of you, you will gain more experience points in the amount of the reward.
Given values experience, threshold and reward, check if you reach the next level after killing the monster.

## Rotate Image
TODO: get the description for this one from website
